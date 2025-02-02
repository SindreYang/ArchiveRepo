import torch


'''
今天这个有点难得堆
一个个写,重复性太高,而且不利于观看,不优雅
重复性事我们交给你喊函数完成
'''
#遵从原来步骤
class VGG(torch.nn.Module):
	#初始化
	def __init__(self):
		super(VGG, self).__init__()
		self.Sumlayers=self.make_layers()#这里我们交由make_layers函数创建相似的模块
		#假设我们上面已经创好五个模块(文章第一幅图block1->block5)
	
		#现在创建最后的Fc
		self.fc=torch.nn.Sequential(
			torch.nn.Linear (7*7*512, 4096),  # 第一个全连接
			torch.nn.ReLU(),
			
			torch.nn.Linear (4096, 4096), # 第二个全连接
			torch.nn.ReLU(),
			
			torch.nn.Linear (4096, 2),  # 第三个全连接
			#  原版1000类       最后分成2类 因为只有猫狗两个类
			torch.nn.ReLU(),
			
			torch.nn.Softmax (dim=1),  # 最后一个 softmax 不填dim=1会报警 1.0以前好像可以直接写Softmax ()
			
			
		)
		
	#前向传播
	def forward (self, x):
		conv = self.Sumlayers (x)
		res = conv.view (conv.size (0), -1)  # 展平多维的卷积图成 一维
		out = self.fc(res)
		return out
	
	
	#构建刚才的构建模块函数make_layers
	def make_layers(self):
		#创建一个列表,用来快速构造模块,你也可以测试vgg19等等
		vgg16=[64, 64, 'Maxpool', 128, 128, 'Maxpool', 256, 256, 256, 'Maxpool',
					   512, 512, 512, 'Maxpool', 512, 512, 512, 'Maxpool']
		#创建一个列表,用来放后面层 ,后面我们直接往里面添加就可以了
		Sumlayers=[]
		
		#创建一个变量，来控制 卷积参数输入大小（in_channels）和输出大小（out_channels）
		in_c = 3 #第一次输入大小
		#遍历列表
		for x in vgg16: #获取到每个配置,我这只有vgg16这一行
			if x =='Maxpool':#如果遇到Maxpool ,我们就创建maxpool层
				Sumlayers+=[torch.nn.MaxPool2d(kernel_size=2, stride=2)]#参数看上文
			else: #否则我们创建conv(卷积模块)
				Sumlayers+= [torch.nn.Conv2d (in_channels=in_c,out_channels=x , kernel_size=3, padding=1), #x是列表中的参数
						   	torch.nn.BatchNorm2d (x),#标准化一下
						   	torch.nn.ReLU ()]
				in_c=x #输出大小成为下个输入大小
		
		return torch.nn.Sequential (*Sumlayers) #然后把构建好模型传出
	
	
# net = VGG()
# print(net)
# x = torch.randn(2,3,224,224)
# print(x)
# print(net(torch.autograd.Variable(x)).size())