from app import db
from app.models import User, Book, Comment, Log, Permission
from flask import render_template
from flask_login import current_user
from . import main
from ..book.forms import SearchForm

from ..decorators import permission_required

from sqlalchemy import or_

@main.app_context_processor
def inject_permissions():
    return dict(Permission=Permission)

from flask import Flask, render_template, session
@main.route('/index')
@permission_required(Permission.BORROW_BOOK)
def index():
    search_form = SearchForm()
    the_books = Book.query
    the_user=User.query.get(session['user_id'])#返回当前用户
    the_books = the_books.filter(or_(Book.Receipt_number==the_user.job_id ,Book.Name_of_voucher_scanner==the_user.name))
    popular_books = the_books.outerjoin(Log).group_by(Book.id).order_by(db.func.count(Log.id).desc()).limit(5)
    popular_users = User.query.outerjoin(Log).group_by(User.id).order_by(db.func.count(Log.id).desc()).limit(5)
    recently_comments = Comment.query.filter_by(deleted=0).order_by(Comment.edit_timestamp.desc()).limit(5)
    return render_template("index.html", books=popular_books, users=popular_users, recently_comments=recently_comments,
                           search_form=search_form)
