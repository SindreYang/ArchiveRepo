import torch


'''
今天在vgg基础上再优雅点
'''
#遵从原来步骤
class Resnet(torch.nn.Module):
	#初始化
	def __init__(self):
		super(Resnet, self).__init__()
		# self.Sumlayers=self.make_layers()#这里我们交由make_layers函数创建相似的模块
		# #假设我们上面已经创好五个模块(文章第一幅图block1->block5)
	
		#现在最顶端的不同层,看文章34层那个最上面橘色简化图的7*7
		self.top=torch.nn.Sequential(
			torch.nn.Conv2d(3,64,7,2,3),
			torch.nn.BatchNorm2d(64),
			torch.nn.ReLU (inplace=True),
			torch.nn.MaxPool2d(3,2,1))#最顶部构建完成

			
			
		#中间重复太多,交给make_layers函数创建相似的模块
		#第三个参数来表示有多少个捷径(高速公路)
		
		#先来一打紫色的(文中图)
		self.layer1 = self.make_layer (64,64,3)
		# 再来一打绿色的(文中图)
		self.layer2 = self.make_layer (64, 128, 4,stride=2)#图中第一个有/2
		# 再来一打橘色的(文中图)
		self.layer3 = self.make_layer ( 128,256, 6,stride=2)#图中第一个有/2
		# 再来一打银色的(文中图)
		self.layer4= self.make_layer (256, 512, 3, stride=2)  # 图中第一个有/2
		#中间重复的构造完了
		
		
		#开始最后的了
		
		self.avgPool =torch.nn.AvgPool2d(7)#全局平均化
		self.fc = torch.nn.Linear (512, 2)#最后分成猫狗两类
		self.last=torch.nn.Softmax (dim=1)
		
	
		
	#前向传播
	def forward (self, x):
		x = self.top (x)
		x = self.layer1 (x)
		x = self.layer2 (x)
		x = self.layer3 (x)
		x = self.layer4 (x)
		x = self.avgPool(x)
		res = x.view (x.size (0), -1)  # 展平多维的卷积图成 一维
		out = self.fc(res)
		out = self.last(out)
		return out
	
	
	#构建刚才的构建模块函数make_layers
	def make_layer(self,in_c,out_c,n_block,stride=1):

		#创建一个列表,用来放后面层 ,后面我们直接往里面添加就可以了
		Sumlayers=[]
		
		#构建捷径(高速公路)
		shortcut=torch.nn.Sequential(
			torch.nn.Conv2d(in_c,out_c,1,stride),#1*1卷积
			torch.nn.BatchNorm2d(out_c),
		)
		#构建完成残差
		Sumlayers.append(ResBlock(in_c,out_c,stride,shortcut))

		#构建右边的公路
		for i in range(1,n_block):
			Sumlayers.append (ResBlock (out_c, out_c))#注意输入,输出应该一样
		
		return torch.nn.Sequential (*Sumlayers) #然后把构建好模型传出
	

#构建残差块 因为参数是变动的,所以引入变量,最后一个变量表示快捷通道个数,默认没有
class ResBlock(torch.nn.Module):
	def __init__(self,in_c,out_c,stride=1,shortcut=None):
		super(ResBlock, self).__init__()
		#左边的公路
		self.left=torch.nn.Sequential(
			torch.nn.Conv2d (in_c,out_c,3,stride,1),
			torch.nn.BatchNorm2d (out_c),
			torch.nn.ReLU (inplace=True),

			torch.nn.Conv2d (out_c,out_c,3,1,1),#注意 这里输入输出应该一样
			torch.nn.BatchNorm2d (out_c)
		)

		#右边的高速公路
		self.right=shortcut

		#最后
		self.last_y=torch.nn.ReLU()
	#前向
	def forward(self, x):
		y_l=self.left(x)
		y_r = x if self.right is None else self.right (x) #如果有高数路为空,就直接保存在res中,否则执行高速路保存在res
		sum_x=y_l+y_r #两个总和
		out=self.last_y(sum_x)
		return out








#
# from torchvision import models
# model = models.resnet34()
#
# net = Resnet()
# print(net)
# x = torch.randn(1,3,224,224)
# #print(x)
# print(net(torch.autograd.Variable(x)).size())