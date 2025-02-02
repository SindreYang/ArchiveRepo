# -*- coding:utf-8 -*-
from app import db
from app.models import Book, Log, Comment, Permission, Tag, book_tag
from flask import render_template, url_for, flash, redirect, request, abort
from flask_login import current_user
from . import book
from .forms import SearchForm, EditBookForm, AddBookForm,ScannerBookForm
from ..comment.forms import CommentForm
from ..decorators import admin_required, permission_required


@book.route('/')
@permission_required(Permission.UPDATE_BOOK_INFORMATION)
def index():
    search_word = request.args.get('search', None)
    search_form = SearchForm()
    page = request.args.get('page', 1, type=int)

    the_books = Book.query
    if not current_user.can(Permission.UPDATE_BOOK_INFORMATION):
        the_books = Book.query.filter_by(Scanning_state=0)

    if search_word:
        search_word = search_word.strip()
        the_books = the_books.filter(db.or_(
            Book.Voucher_number.ilike(u"%%%s%%" % search_word), Book.Project_number.ilike(u"%%%s%%" % search_word), Book.Receipt_number.ilike(
                u"%%%s%%" % search_word), Book.tags.any(Tag.name.ilike(u"%%%s%%" % search_word)), Book.Project_name.ilike(
                u"%%%s%%" % search_word))).outerjoin(Log).group_by(Book.id).order_by(db.func.count(Log.id).desc())
        search_form.search.data = search_word
    else:
        the_books = Book.query.order_by(Book.id.desc())

    pagination = the_books.paginate(page, per_page=8)
    result_books = pagination.items
    return render_template("book.html", books=result_books, pagination=pagination, search_form=search_form,
                           title=u"凭证清单")


@book.route('/<book_id>/')
def detail(book_id):
    the_book = Book.query.get_or_404(book_id)

    if the_book.Scanning_state and (not current_user.is_authenticated or not current_user.is_administrator()):
        abort(404)

    show = request.args.get('show', 0, type=int)
    page = request.args.get('page', 1, type=int)
    form = CommentForm()

    if show in (1, 2):
        pagination = the_book.logs.filter_by(returned=show - 1) \
            .order_by(Log.borrow_timestamp.desc()).paginate(page, per_page=5)
    else:
        pagination = the_book.comments.filter_by(deleted=0) \
            .order_by(Comment.edit_timestamp.desc()).paginate(page, per_page=5)

    data = pagination.items
    return render_template("book_detail.html", book=the_book, data=data, pagination=pagination, form=form,
                           title=the_book.Voucher_number)


@book.route('/<int:book_id>/edit/', methods=['GET', 'POST'])
@permission_required(Permission.UPDATE_BOOK_INFORMATION)
def edit(book_id):
    book = Book.query.get_or_404(book_id)
    form = EditBookForm()
    if form.validate_on_submit():
        book.Voucher_number = form.Voucher_number.data
        book.Project_name = form.Project_name.data
        book.Project_number = form.Project_number.data
        book.Receipt_name = form.Receipt_name.data
        book.Receipt_number = form.Receipt_number.data
        book.summary = form.summary.data
        book.catalog = form.catalog.data
        db.session.add(book)
        db.session.commit()
        flash(u'凭证资料已保存!', 'success')
        return redirect(url_for('book.detail', book_id=book_id))
    form.Voucher_number.data = book.Voucher_number
    form.Project_name.data = book.Project_name
    form.Project_number.data = book.Project_number
    form.Receipt_name.data = book.Receipt_name
    form.Receipt_number.data = book.Receipt_number

    form.summary.data = book.summary or ""
    form.catalog.data = book.catalog or ""
    return render_template("book_edit.html", form=form, book=book, title=u"编辑凭证资料")


@book.route('/add/', methods=['GET', 'POST'])
@permission_required(Permission.ADD_BOOK)
def add():
    form = AddBookForm()
    #form.numbers.data = 3
    if form.validate_on_submit():
        new_book = Book(
            Voucher_number=form.Voucher_number.data,
            Project_name=form.Project_name.data,
            Project_number=form.Project_number.data,
            Receipt_name=form.Receipt_name.data,
            Receipt_number=form.Receipt_number.data,
            binding=form.binding.data,
            numbers=form.numbers.data,
            summary=form.summary.data or "",
            catalog=form.catalog.data or "")
        db.session.add(new_book)
        db.session.commit()
        flash(u'凭证 %s 已添加至图书馆!' % new_book.title, 'success')
        return redirect(url_for('book.detail', book_id=new_book.id))
    return render_template("book_edit.html", form=form, title=u"添加新的凭证")


@book.route('/<int:book_id>/delete/')
@permission_required(Permission.DELETE_BOOK)
def delete(book_id):
    the_book = Book.query.get_or_404(book_id)
    the_book.hidden = 1
    db.session.add(the_book)
    db.session.commit()
    flash(u'成功删除凭证,用户已经无法查看该凭证', 'info')
    return redirect(request.args.get('next') or url_for('book.detail', book_id=book_id))


@book.route('/<int:book_id>/put_back/')
@admin_required
def put_back(book_id):
    the_book = Book.query.get_or_404(book_id)
    the_book.hidden = 0
    db.session.add(the_book)
    db.session.commit()
    flash(u'成功恢复凭证,用户现在可以查看该凭证', 'info')
    return redirect(request.args.get('next') or url_for('book.detail', book_id=book_id))


@book.route('/tags/')
def tags():
    search_tags = request.args.get('search', None)
    page = request.args.get('page', 1, type=int)
    the_tags = Tag.query.outerjoin(book_tag).group_by(book_tag.c.tag_id).order_by(
        db.func.count(book_tag.c.book_id).desc()).limit(30).all()
    print(the_tags)
    search_form = SearchForm()
    search_form.search.data = search_tags

    data = None
    pagination = None

    if search_tags:
        tags_list = [s.strip() for s in search_tags.split(',') if len(s.strip()) > 0]
        if len(tags_list) > 0:
            the_books = Book.query
            if not current_user.can(Permission.UPDATE_BOOK_INFORMATION):
                the_books = Book.query.filter_by(hidden=0)
            the_books = the_books.filter(
                db.and_(*[Book.tags.any(Tag.name.ilike(word)) for word in tags_list])).outerjoin(Log).group_by(
                Book.id).order_by(db.func.count(Log.id).desc())
            pagination = the_books.paginate(page, per_page=8)
            data = pagination.items

    return render_template('book_tag.html', tags=the_tags, title='项目分类', search_form=search_form, books=data,
                           pagination=pagination)


@book.route('/<int:book_id>/scanner/', methods=['GET', 'POST'])
@permission_required(Permission.UPDATE_BOOK_INFORMATION)
def scanner(book_id):
    book = Book.query.get_or_404(book_id)
    form = ScannerBookForm()
    if form.validate_on_submit():
        book.Voucher_number = form.Voucher_number.data
        book.Project_name = form.Project_name.data
        book.Project_number = form.Project_number.data
        book.Receipt_name = form.Receipt_name.data
        book.Receipt_number = form.Receipt_number.data
        book.summary = form.summary.data
        book.catalog = form.catalog.data
        db.session.add(book)
        db.session.commit()
        flash(u'凭证资料已保存!', 'success')
        return redirect(url_for('book.detail', book_id=book_id))
    form.Voucher_number.data = book.Voucher_number
    form.Project_name.data = book.Project_name
    form.Project_number.data = book.Project_number
    form.Receipt_name.data = book.Receipt_name
    form.Receipt_number.data = book.Receipt_number

    form.summary.data = book.summary or ""
    form.catalog.data = book.catalog or ""
    return render_template("book_edit.html", form=form, book=book, title=u"编辑凭证资料")