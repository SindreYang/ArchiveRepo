# -*- coding:utf-8 -*-
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField,PasswordField,SelectField
from wtforms.validators import Length, DataRequired, URL,EqualTo
from flask_pagedown.fields import PageDownField
from flask_wtf.file import FileField, FileAllowed
from app import avatars


class EditProfileForm(FlaskForm):
    name = StringField(u'用户名', validators=[DataRequired(message=u"该项忘了填写了!"), Length(1, 64, message=u"长度为1到64个字符")])
    major = StringField(u'部门', validators=[Length(0, 128, message=u"长度为0到128个字符")])
    headline = StringField(u'一句话介绍自己', validators=[Length(0, 32, message=u"长度为32个字符以内")])
    about_me = PageDownField(u"个人简介")
    submit = SubmitField(u"保存更改")


class AvatarEditForm(FlaskForm):
    avatar_url = StringField('', validators=[Length(1, 100, message=u"长度限制在100字符以内"), URL(message=u"请填写正确的URL")])
    submit = SubmitField(u"保存")


class AvatarUploadForm(FlaskForm):
    avatar = FileField('', validators=[FileAllowed(avatars, message=u"只允许上传图片")])


class RemovePasswordForm(FlaskForm):
    new_password = PasswordField(u'新密码', validators=[DataRequired(message=u"该项忘了填写了!"),
                                                     EqualTo('confirm_password', message=u'密码必须匹配'),
                                                     Length(6, 32)])
    confirm_password = PasswordField(u'确认新密码', validators=[DataRequired(message=u"该项忘了填写了!")])
    submit = SubmitField(u"保存密码")


class ChangePermissionForm(FlaskForm):
    Permission=SelectField("选择权限",validators=[DataRequired('请选择标签')],choices=[(1, '查阅人员'), (2, '扫描员'), (3, '管理员')],  coerce=int)
    submit = SubmitField(u"保存权限")