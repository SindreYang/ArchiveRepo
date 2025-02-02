# -*- coding: utf-8 -*-

from app import app, db
from app.models import User, Book, Log, Role

app_ctx = app.app_context()
app_ctx.push()
db.create_all()
Role.insert_roles()

admin = User(name=u'root', job_id='root', password='root', major='administrator')
Moderator = User(name=u'扫描员',job_id='s', password='s', major='扫描部门')
user1 = User(name=u'查询人员c1', job_id='c1', password='c1')
user2 = User(name=u'查询人员c2', job_id='c2', password='c2')

book1 = Book(Project_name=u"Web 开发", Project_number=u"110", Receipt_name=u"小张", Voucher_number='9787115373991',image='http://img3.doubanio.com/lpic/s1959961.jpg',
            summary=u"""#这里是Web 开发项目备注""", Receipt_number='root')
book2 = Book(Project_name=u"120开发", Project_number=u"120", Receipt_name=u"小120", Voucher_number='9997115373991', image='http://img3.douban.com/lpic/s27906700.jpg',
             summary=u"""*#这里是120开发项目备注""")
book3 = Book(Project_name=u"119 开发", Project_number=u"119", Receipt_name=u"小119", Voucher_number="0787111251217", image='http://img3.doubanio.com/lpic/s1959961.jpg',
             summary=u"""* 119 开发备注""")
book4 = Book(Project_name=u"009 开发", Project_number=u"009", Receipt_name=u"小009", Voucher_number="1787111321330", image='http://img3.doubanio.com/lpic/s1959969.jpg',
             Receipt_number='c2',summary=u"""* 009 开发备注""")
book5 = Book(Project_name=u"019 开发", Project_number=u"019", Receipt_name=u"小019",Voucher_number="2787517010845", image='http://img3.doubanio.com/lpic/s1959968.jpg',
             Receipt_number='root',summary=u"""019 开发备注""")
book6 = Book(Project_name=u"109 开发", Project_number=u"109", Receipt_name=u"小109",Voucher_number="3787111187776",image='http://img3.doubanio.com/lpic/s1959967.jpg',
             Receipt_number='c1',summary=u"109 开发备注")
# logs = [Log(user1, book2), Log(user1, book3), Log(user1, book4), Log(user1, book6),
#         Log(user2, book1), Log(user2, book3), Log(user2, book5),
#         Log(user3, book2), Log(user3, book5)]

#db.session.add_all([admin, user1, user2, user3, user4, book1, book2, book3, book4, book5, book6] + logs)

db.session.add_all([admin, user1,user2, Moderator, book1, book2, book3, book4, book5, book6] )
db.session.commit()

app_ctx.pop()
