# -*- coding: utf-8 -*-
import json
from datetime import datetime, timedelta

import bleach
from app import db, lm, avatars
from flask import current_app, url_for
from flask_login import UserMixin, AnonymousUserMixin
from markdown import markdown
from werkzeug.security import generate_password_hash, check_password_hash


class User(UserMixin, db.Model):
    __tablename__ = 'users'
    id = db.Column(db.Integer, primary_key=True)
    job_id = db.Column(db.String(64), unique=True)
    name = db.Column(db.String(64))
    password_hash = db.deferred(db.Column(db.String(128)))
    major = db.Column(db.String(128))
    role_id = db.Column(db.Integer, db.ForeignKey('roles.id'))
    headline = db.Column(db.String(32), nullable=True)
    about_me = db.deferred(db.Column(db.Text, nullable=True))
    about_me_html = db.deferred(db.Column(db.Text, nullable=True))
    avatar = db.Column(db.String(128))
    member_since = db.Column(db.DateTime(), default=datetime.utcnow)
    be_permissions=db.Column(db.Text, nullable=True)
    @property
    def password(self):
        raise AttributeError('密码不可读属性')

    @password.setter
    def password(self, password):
        self.password_hash = generate_password_hash(password)

    def verify_password(self, password):
        return check_password_hash(self.password_hash, password)

    def __init__(self, **kwargs):
        super(User, self).__init__(**kwargs)
        if self.role is None:
            if self.job_id.lower() == current_app.config['FLASKY_ADMIN'].lower():
                self.role = Role.query.filter_by(permissions=0x1ff).first()
            if self.role is None:
                self.role = Role.query.filter_by(default=True).first()
        self.member_since = datetime.now()

    def can(self, permissions):
        return self.role is not None and \
               (self.role.permissions & permissions) == permissions

    def is_administrator(self):
        return self.can(Permission.ADMINISTER)

    logs = db.relationship('Log',
                           backref=db.backref('user', lazy='joined'),
                           lazy='dynamic',
                           cascade='all, delete-orphan')

    comments = db.relationship('Comment',
                               backref=db.backref('user', lazy='joined'),
                               lazy='dynamic',
                               cascade='all, delete-orphan')

    def __repr__(self):
        return '<User %r>' % self.job_id

    def borrowing(self, book):
        return self.logs.filter_by(book_id=book.id, returned=0).first()

    def can_borrow_book(self):
        return self.logs.filter(Log.returned == 0, Log.return_timestamp < datetime.now()).count() == 0

    def borrow_book(self, book):
        # if self.logs.filter(Log.returned == 0, Log.return_timestamp < datetime.now()).count() > 0:
        #     return False, u"无法借阅,你有超期的图书未归还"
        if self.borrowing(book):
            return False, u'貌似你已经授权!!'
        db.session.add(Log(self, book))
        return True, u'你成功授权 %s 凭证的授权' % book.Voucher_number

    def return_book(self, log):
        if log.returned == 1 or log.user_id != self.id:
            return False, u'没有找到这条记录'
        log.returned = 1
        log.return_timestamp = datetime.now()
        db.session.add(log)
        return True, u'你撤销了 %s 凭证的授权' % log.book.Voucher_number

    def avatar_url(self, _external=False):
        if self.avatar:
            avatar_json = json.loads(self.avatar)
            if avatar_json['use_out_url']:
                return avatar_json['url']
            else:
                return url_for('_uploads.uploaded_file', setname=avatars.name, filename=avatar_json['url'],
                               _external=_external)
        else:
            return url_for('static', filename='img/avatar.png', _external=_external)

    @staticmethod
    def on_changed_about_me(target, value, oldvalue, initiaor):
        allowed_tags = ['a', 'abbr', 'acronym', 'b', 'blockquate', 'code', 'em', 'i',
                        'li', 'ol', 'pre', 'strong', 'ul', 'h1', 'h2', 'h3', 'p']
        target.about_me_html = bleach.linkify(
            bleach.clean(markdown(value, output_format='html'),
                         tags=allowed_tags, strip=True))


db.event.listen(User.about_me, 'set', User.on_changed_about_me)


class AnonymousUser(AnonymousUserMixin):
    def can(self, permissions):
        return False

    def is_administrator(self):
        return False


lm.anonymous_user = AnonymousUser


class Permission(object):
    RETURN_BOOK = 0x01
    BORROW_BOOK = 0x02
    WRITE_COMMENT = 0x04
    DELETE_OTHERS_COMMENT = 0x08
    UPDATE_OTHERS_INFORMATION = 0x10
    UPDATE_BOOK_INFORMATION = 0x20
    ADD_BOOK = 0x40
    DELETE_BOOK = 0x80
    ADMINISTER = 0x100


class Role(db.Model):
    __tablename__ = 'roles'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(64), unique=True)
    default = db.Column(db.Boolean, default=False, index=True)
    permissions = db.Column(db.Integer)
    users = db.relationship('User', backref='role', lazy='dynamic')

    @staticmethod
    def insert_roles():
        roles = {
            'User': (Permission.RETURN_BOOK |           #普通用户
                     Permission.BORROW_BOOK , True),
            'Moderator': (Permission.RETURN_BOOK |      #扫描员
                          Permission.BORROW_BOOK |
                          Permission.WRITE_COMMENT |
                          Permission.DELETE_OTHERS_COMMENT |
                          Permission.UPDATE_BOOK_INFORMATION |
                          Permission.ADD_BOOK |
                          Permission.DELETE_BOOK , False),
            'Administrator': (0x1ff, False)
        }
        for r in roles:
            role = Role.query.filter_by(name=r).first()
            if role is None:
                role = Role(name=r)
            role.permissions = roles[r][0]
            role.default = roles[r][1]
            db.session.add(role)
        db.session.commit()

    def __repr__(self):
        return '<Role %r>' % self.name


class Book(db.Model):
    __tablename__ = 'books'
    id = db.Column(db.Integer, primary_key=True)
    #photo =db. Column(db.ImageColumn(size=(1024, 1024, False), thumbnail_size=(30, 30, True)))
    Voucher_number=db.Column(db.String(50), unique=True)                           #凭证号
    Project_name =db. Column(db.String(50))                           #项目名称
    Project_number = db.Column(db.String(50))                         #项目代码
    Receipt_name = db.Column(db.String(50))                           #报销人员姓名
    Receipt_number = db.Column(db.String(50))                         #报销人员工号
    Name_of_voucher_scanner=db.Column(db.String(50))                  #凭证扫描人员姓名
    Certificate_scanning_date=db.Column(db.Date)                      #凭证扫描日期
    Name_of_credential_auditor=db.Column(db.String(50))               #凭证审核人员姓名
    Certificate_audit_date=db.Column(db.Date)                         #凭证审核日期
    Certificate_state=db.Column(db.Boolean(),default=False)           #审核状态
    Scanning_state=db.Column(db.Boolean(),default=False)              #扫描状态
    Scan_file_format=db.Column(db.String(50))                         #扫描文件格式
    Accounting_accounting_file_path=db.Column(db.String(50))          #会计记账文件路径
    Accounting_name=db.Column(db.String(50))                          #会计记账文件名
    Document_path_for_credential_attachment=db.Column(db.String(50))  #凭证附件文件路径
    Document_attachment_file_name=db.Column(db.String(50))            #凭证附件文件名
    Path_to_original_invoice_file=db.Column(db.String(50))            #原始发票文件路径
    Original_invoice_file_name=db.Column(db.String(50))               #原始发票文件名
    image = db.Column(db.String(128))
    summary = db.deferred(db.Column(db.Text, default=""))
    summary_html = db.deferred(db.Column(db.Text))
    catalog = db.deferred(db.Column(db.Text, default=""))
    catalog_html = db.deferred(db.Column(db.Text))

    logs = db.relationship('Log',
                           backref=db.backref('book', lazy='joined'),
                           lazy='dynamic',
                           cascade='all, delete-orphan')

    comments = db.relationship('Comment', backref='book',
                               lazy='dynamic',
                               cascade='all, delete-orphan')

    @property
    def tags_string(self):
        return ",".join([tag.name for tag in self.tags.all()])

    @tags_string.setter
    def tags_string(self, value):
        self.tags = []
        tags_list = value.split(u',')
        for str in tags_list:
            tag = Tag.query.filter(Tag.name.ilike(str)).first()
            if tag is None:
                tag = Tag(name=str)

            self.tags.append(tag)

        db.session.add(self)
        db.session.commit()

    def can_scanning(self):#扫描状态
        return  self.Scanning_state

    def can_borrow_number(self):
        return 100 - Log.query.filter_by(book_id=self.id, returned=0).count()

    @staticmethod
    def on_changed_summary(target, value, oldvalue, initiaor):
        allowed_tags = ['a', 'abbr', 'acronym', 'b', 'blockquate', 'code', 'em', 'i',
                        'li', 'ol', 'pre', 'strong', 'ul', 'h1', 'h2', 'h3', 'p']
        target.summary_html = bleach.linkify(
            bleach.clean(markdown(value, output_format='html'),
                         tags=allowed_tags, strip=True))

    @staticmethod
    def on_changed_catalog(target, value, oldvalue, initiaor):
        allowed_tags = ['a', 'abbr', 'acronym', 'b', 'blockquate', 'code', 'em', 'i',
                        'li', 'ol', 'pre', 'strong', 'ul', 'h1', 'h2', 'h3', 'p']
        target.catalog_html = bleach.linkify(
            bleach.clean(markdown(value, output_format='html'),
                         tags=allowed_tags, strip=True))

    def __repr__(self):
        return u'<Book %r>' % self.title


db.event.listen(Book.summary, 'set', Book.on_changed_summary)
db.event.listen(Book.catalog, 'set', Book.on_changed_catalog)


class Log(db.Model):
    __tablename__ = 'logs'
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('users.id'))
    book_id = db.Column(db.Integer, db.ForeignKey('books.id'))
    T_number = db.Column(db.String(64))#授权目标
    borrow_timestamp = db.Column(db.DateTime, default=datetime.now())#授权时间
    return_timestamp = db.Column(db.DateTime, default=datetime.now())#撤销时间
    returned = db.Column(db.Boolean, default=0)#是否可以再次授权

    def __init__(self, user, book):
        self.user = user
        self.book = book
        self.borrow_timestamp = datetime.now()
        self.return_timestamp = datetime.now() + timedelta(days=30)
        self.returned = 0

    def __repr__(self):
        return u'<%r - %r>' % (self.user.name, self.book.Voucher_number)


class Comment(db.Model):
    __tablename__ = 'comments'
    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('users.id'))
    book_id = db.Column(db.Integer, db.ForeignKey('books.id'))
    comment = db.Column(db.String(1024))
    create_timestamp = db.Column(db.DateTime, default=datetime.now())
    edit_timestamp = db.Column(db.DateTime, default=datetime.now())
    deleted = db.Column(db.Boolean, default=0)

    def __init__(self, book, user, comment):
        self.user = user
        self.book = book
        self.comment = comment
        self.create_timestamp = datetime.now()
        self.edit_timestamp = self.create_timestamp
        self.deleted = 0


book_tag = db.Table('books_tags',
                    db.Column('book_id', db.Integer, db.ForeignKey('books.id')),
                    db.Column('tag_id', db.Integer, db.ForeignKey('tags.id'))
                    )


class Tag(db.Model):
    __tablename__ = 'tags'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String)
    books = db.relationship('Book',
                            secondary=book_tag,
                            backref=db.backref('tags', lazy='dynamic'),
                            lazy='dynamic')

    def __repr__(self):
        return u'<Tag %s>' % self.name
