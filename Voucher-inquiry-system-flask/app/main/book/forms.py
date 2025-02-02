# -*- coding:utf-8 -*-
from app.models import Book
from flask_pagedown.fields import PageDownField
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, IntegerField
from wtforms import ValidationError
from wtforms.validators import Length, DataRequired, Regexp


class EditBookForm(FlaskForm):
    Voucher_number = StringField(u"凭证号",
                       validators=[DataRequired(message=u"该项忘了填写了!"),
                                   Regexp('[0-9]{13,13}', message=u"13位凭证号")])
    Project_name = StringField(u"项目名称",
                        validators=[DataRequired(message=u"该项忘了填写了!"), Length(1, 128, message=u"长度为1到128个字符")])
    Project_number = StringField(u"项目代码", validators=[Length(0, 128, message=u"长度为0到128个字符")])
    Receipt_name = StringField(u"报销人员姓名", validators=[Length(0, 128, message=u"长度为0到128个字符")])
    Receipt_number = StringField(u"报销人员工号", validators=[Length(0, 128, message=u"长度为0到64个字符")])
    summary = PageDownField(u"内容简介")
    catalog = PageDownField(u"目录")
    submit = SubmitField(u"保存更改")


class AddBookForm(EditBookForm):
    def validate_isbn(self, filed):
        if Book.query.filter_by(isbn=filed.data).count():
            raise ValidationError(u'已经存在相同的ISBN,无法录入,请仔细核对是否已库存该书籍.')


class SearchForm(FlaskForm):
    search = StringField(validators=[DataRequired()])
    submit = SubmitField(u"搜索")



class ScannerBookForm(FlaskForm):
    Voucher_number = StringField(u"凭证号",
                                 validators=[DataRequired(message=u"该项忘了填写了!"),
                                             Regexp('[0-9]{13,13}', message=u"13位凭证号")])
    Project_name = StringField(u"项目名称",
                               validators=[DataRequired(message=u"该项忘了填写了!"), Length(1, 128, message=u"长度为1到128个字符")])
    Project_number = StringField(u"项目代码", validators=[Length(0, 128, message=u"长度为0到128个字符")])
    Receipt_name = StringField(u"报销人员姓名", validators=[Length(0, 128, message=u"长度为0到128个字符")])
    Receipt_number = StringField(u"报销人员工号", validators=[Length(0, 128, message=u"长度为0到64个字符")])
    summary = PageDownField(u"内容简介")
    catalog = PageDownField(u"凭证影像详单")
    submit = SubmitField(u"保存更改")