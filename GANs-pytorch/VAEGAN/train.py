import torch
import torch.nn as nn
import torchvision.datasets as datasets
import torchvision.transforms as  transforms
from torch.autograd import Variable
import torch.backends.cudnn as cudnn
# 工具包
import argparse
# 载入网络
from network import G, D

#############参数设置#############
####命令行设置########
parser = argparse.ArgumentParser (description='GANs')  # 导入命令行模块
# 对关于函数add_argumen()第一个是选项，第二个是数据类型，第三个默认值，第四个是help命令时的说明
#关于训练参数
parser.add_argument ('--batch_size', type=int, default=64,
					 help='训练batch-size大小 (default: 64)')
parser.add_argument ('--imageSize', type=int, default=64,
					 help='图片尺寸')
parser.add_argument ('--max_epoch', type=int, default=20,
					 help='最大迭代数 (default: 12)')
#关于网络参数
parser.add_argument ('--lr_g', type=float, default=2e-4,
					 help='生成器学习率 (default: 2e-4)')
parser.add_argument ('--lr_d', type=float, default=2e-4,
					 help='判别器学习率 (default: 2e-4)')
parser.add_argument ('--ngf', type=int, default=64,
					 help='生成器feature map数')
parser.add_argument ('--ndf', type=int, default=64,
					 help='判别器feature map数')
parser.add_argument ('--d_every', type=int, default=1,
					 help='每几个batch训练一次判别器')
parser.add_argument ('--g_every', type=int, default=4,
					 help='每几个batch训练一次生成器')
parser.add_argument ('--nz', type=int, default=3,
					 help='噪声维度')

#关于优化器参数
parser.add_argument ('--beta1', type=int, default=0.5,
					 help='Adam优化器的beta1参数')
#路径
parser.add_argument ('--dataset', default='data/',
					 help='数据集路径')

parser.add_argument ('--save_data',  default='save/',
					 help='保存路径')

#可视化
parser.add_argument ('--vis', action='store_true',
					 help='使用visdom可视化')
parser.add_argument ('--plot_every', type=int, default=1,
					 help='每间隔_batch，visdom画图一次')
# 其他

parser.add_argument ('--cuda', action='store_true',
					 help='开启cuda训练')
parser.add_argument ('--plt', action='store_true',
					 help='开启画图')
parser.add_argument ('--test', action='store_true',
					 help='开启测试生成')
parser.add_argument ('--save_every', type=int, default=5,
					 help='几个epoch保存一次模型 (default: 2)')
parser.add_argument ('--seed', type=int, default=1,
					 help='随机种子 (default: 1)')
args = parser.parse_args ()  # 相当于激活命令


#训练过程
def train():
	###############判断gpu#############
	device = torch.device ('cuda') if args.cuda else torch.device ('cpu')
	
	####### 为CPU设置种子用于生成随机数，以使得结果是确定的##########
	torch.manual_seed (args.seed)
	if args.cuda:
		torch.cuda.manual_seed (args.seed)
	cudnn.benchmark = True
	
	#################可视化###############
	if args.vis:
		vis = Visualizer ('GANs')
	##########数据转换#####################
	data_transforms = transforms.Compose ([transforms.Scale (args.imageSize),  # 通过调整比例调整大小,会报警
										   transforms.CenterCrop (args.imageSize),  # 在中心裁剪给指定大小方形PIL图像
										   transforms.ToTensor (),# 转换成pytorch 变量tensor
										   transforms.Normalize ((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])
	###############数据载入################
	# train_dataset = datasets.ImageFolder (root=args.dataset,  # 数据路径目录
	# 									  transform=data_transforms)  # 把数据转换成上面约束样子
	
	train_dataset = datasets.CIFAR10(root=args.dataset,
									 train=True,
									 transform=data_transforms,
									 download=False)
	# test_dataset = datasets.ImageFolder (root=args.dataset,
	# 									 transform=data_transforms)
	
	##############数据装载###############
	train_loader = torch.utils.data.DataLoader (dataset=train_dataset,  # 装载数据
												batch_size=args.batch_size,  # 设置批大小
												shuffle=True)  # 是否随机打乱
	# test_loader = torch.utils.data.DataLoader (dataset=test_dataset,
	# 										   batch_size=args.batch_size,
	# 										   shuffle=True)
	
	#############模型载入#################
	netG ,netD= G (args),D (args)
	netG.to (device)
	netD.to (device)
	print (netD, netG)
	
	###############损失函数##################
	criterion = torch.nn.BCELoss ().to (device)
	optimizerD = torch.optim.Adam (netD.parameters (), lr=args.lr_d,betas=(0.5, 0.999))  # Adam优化器
	optimizerG = torch.optim.Adam (netG.parameters (), lr=args.lr_g,betas=(0.5, 0.999))  # Adam优化器
	###############画图参数保存##################
	G_losses = []
	D_losses = []
	img_list = []
	#############训练过程#####################
	import tqdm
	# Tqdm是一个快速，可扩展的Python进度条，可以在Python
	# 长循环中添加一个进度提示信息，用户只需要封装任意的迭代器
	# tqdm (iterator)。
	for epoch in range (args.max_epoch):
		for i, (images, labels) in tqdm.tqdm(enumerate (train_loader)):  # 枚举出来
			#数据处理
			images = images.to (device)
			# 装箱
			images = Variable (images)
			noises=Variable(torch.randn(images.size(0), args.nz, 1, 1).to(device))
			
			#遍历每张图片,并且根据指定的训练机制训练
			if i % args.d_every==0:#满足此条件训练D
				#D前向传播
				optimizerD.zero_grad ()
				#D网络输出
				output_r = netD (images).view(-1)
				#定义真张量
				#返回第一个参数为大小 第二参数为值 的张量
				true_label = torch.full ((images.size(0),), 1, device=device)
				#判别真的损失
				d_real_loss = criterion(output_r, true_label)
				#反向传播
				d_real_loss.backward()
				#G网络输出
				fake = netG (images) # 根据真生成图
				#把假图给d
				output_f = netD (fake).view(-1)
				#d假的损失
				#print(fake.size(),output_f.size(),output_r.size())
				# 返回第一个参数为大小 第二参数为值 的张量
				fake_label = torch.full ((images.size (0),), 0, device=device)
				d_fake_loss= criterion(output_f,fake_label)
				#D假反向传播
				d_fake_loss.backward ()
				# 总损失
				D_loss=d_fake_loss+d_real_loss
				#D更新参数
				optimizerD.step ()
				
				
				# 度量
				D_x = output_r.mean ().item ()
				D_G_z1 = output_f.mean ().item ()
			
			if i % args.g_every==0:#满足此条件训练G
				#G前向传播
				optimizerG.zero_grad ()
				#G网络输出
				fake = netG (images)  # 根据噪声生成假图
				#把假图给G
				output_f = netD (fake).view(-1)
				#G的损失
				true_label = torch.full ((images.size (0),), 1, device=device)
				G_loss = criterion(output_f,true_label)
				#G反向传播
				G_loss.backward ()
				#度量
				D_G_z2 = output_f.mean ().item ()
				#D更新参数
				optimizerG.step ()
				
			###########################################
			##########可视化(可选)#####################
			if args.vis and i % args.plot_every == args.plot_every - 1:
				fake = netG (noises)
				vis.images (fake.detach ().cpu ().numpy () [:64] * 0.5 + 0.5, win='fixfake')
				vis.images (images.data.cpu ().numpy () [:64] * 0.5 + 0.5, win='real')
				vis.plot ('errord', D_loss.item ())
				vis.plot ('errorg', G_loss.item ())
			#######################################
			############打印记录###################
			if i % 1== 0:
				print ('[%d/%d][%d/%d]\tLoss_D: %.4f\tLoss_G: %.4f\tD(x): %.4f\tD(G(z)): %.4f / %.4f'
					   % (epoch, args.max_epoch, i, len (train_loader),
						  D_loss.item (), G_loss.item (), D_x, D_G_z1, D_G_z2))
				########添加画图参数########
				G_losses.append (G_loss.item ())
				D_losses.append (D_loss.item ())
				with torch.no_grad ():
					noises = torch.randn (args.batch_size, args.nz, 1, 1).to (device)
					fake = netG (images).detach ().cpu ()
				import torchvision.utils as vutils
				img_list.append (vutils.make_grid (fake, padding=2, normalize=True))
	


		#######################################
		############保存模型###################
	
		if (epoch + 1) % args.save_every == 0:
			import torchvision as tv
			# 保存模型、图片
			tv.utils.save_image (fake.data [:64], '%s/%s.png' % (args.save_data, epoch), normalize=True,range=(-1, 1))
			torch.save (netD.state_dict (), 'checkpoints/netd_%s.pth' % epoch)
			torch.save (netG.state_dict (), 'checkpoints/netg_%s.pth' % epoch)
			print('完成%s的模型保存'%epoch)

	#######################################
	############画图###################
	
	if args.plt:
		import matplotlib.pyplot as plt
		import numpy as np
		import torchvision.utils as vutils
		
		plt.figure (figsize=(10, 5))
		plt.title ("GAN")
		plt.plot (G_losses, label="G")
		plt.plot (D_losses, label="D")
		plt.xlabel ("迭代次数",fontproperties='SimHei')
		plt.ylabel ("损失",fontproperties='SimHei')
		plt.legend ()
		plt.show ()
		
		# 从数据集加载
		real_batch = next (iter (train_dataset))
		
		# 画出真图
		plt.figure (figsize=(15, 10))
		plt.subplot (1, 2, 1)
		plt.axis ("off")
		plt.title ("真图",fontproperties='SimHei')
		plt.imshow (np.transpose (
			vutils.make_grid (real_batch [0].to (device) [:64], padding=5, normalize=True).cpu (),
			(1, 2, 0)))
		
		# 画出假图
		plt.subplot (1, 2, 2)
		plt.axis ("off")
		plt.title ("假图",fontproperties='SimHei')
		plt.imshow (np.transpose (img_list [-1], (1, 2, 0)))
		plt.show ()
				

		

		

@torch.no_grad()#禁用梯度计算
def test():
	#判断Gpu
	device = torch.device ('cuda') if args.cuda else torch.device ('cpu')
	#初始化网络
	netg, netd = netG (args).eval (), netD (args).eval ()
	#定义噪声
	noises = torch.randn (args.batch_size, args.nz, 1, 1).to (device)
	#载入网络
	netd.load_state_dict (torch.load ('checkpoints/netd_%s.pth'%args.max_epoch))
	netg.load_state_dict (torch.load ('checkpoints/netg_%s.pth'%args.max_epoch))
	#设备化
	netd.to (device)
	netg.to (device)
	# 生成图片，并计算图片在判别器的分数
	fake_img = netg (noises)
	scores = netd (fake_img).detach ()
	
	# 挑选最好的某几张
	indexs = scores.topk (5) [1]
	result = []
	for i in indexs:
		result.append (fake_img.data [i])
	
	# 保存图片
	import torchvision as tv
	tv.utils.save_image (torch.stack (result), 5, normalize=True, range=(-1, 1))











	
	###################可视化类##################################
import visdom
import time
import torchvision as tv
import numpy as np


class Visualizer ():
	"""
	封装了visdom的基本操作，但是你仍然可以通过`self.vis.function`
	调用原生的visdom接口
	"""
	
	def __init__ (self, env='default', **kwargs):
		import visdom
		self.vis = visdom.Visdom (env=env, use_incoming_socket=False, **kwargs)
		
		# 画的第几个数，相当于横座标
		# 保存（’loss',23） 即loss的第23个点
		self.index = {}
		self.log_text = ''
	
	def reinit (self, env='default', **kwargs):
		"""
		修改visdom的配置
		"""
		self.vis = visdom.Visdom (env=env, use_incoming_socket=False, **kwargs)
		return self
	
	def plot_many (self, d):
		"""
		一次plot多个
		@params d: dict (name,value) i.e. ('loss',0.11)
		"""
		for k, v in d.items ():
			self.plot (k, v)
	
	def img_many (self, d):
		for k, v in d.items ():
			self.img (k, v)
	
	def plot (self, name, y):
		"""
		self.plot('loss',1.00)
		"""
		x = self.index.get (name, 0)
		self.vis.line (Y=np.array ([y]), X=np.array ([x]),
					   win=(name),
					   opts=dict (title=name),
					   update=None if x == 0 else 'append'
					   )
		self.index [name] = x + 1
	
	def img (self, name, img_):
		"""
		self.img('input_img',t.Tensor(64,64))
		"""
		
		if len (img_.size ()) < 3:
			img_ = img_.cpu ().unsqueeze (0)
		self.vis.image (img_.cpu (),
						win=(name),
						opts=dict (title=name)
						)
	
	def img_grid_many (self, d):
		for k, v in d.items ():
			self.img_grid (k, v)
	
	def img_grid (self, name, input_3d):
		"""
		一个batch的图片转成一个网格图，i.e. input（36，64，64）
		会变成 6*6 的网格图，每个格子大小64*64
		"""
		self.img (name, tv.utils.make_grid (
			input_3d.cpu () [0].unsqueeze (1).clamp (max=1, min=0)))
	
	def log (self, info, win='log_text'):
		"""
		self.log({'loss':1,'lr':0.0001})
		"""
		
		self.log_text += ('[{time}] {info} <br>'.format (
			time=time.strftime ('%m%d_%H%M%S'),
			info=info))
		self.vis.text (self.log_text, win=win)
	
	def __getattr__ (self, name):
		return getattr (self.vis, name)
	
	
	
if __name__ == '__main__':
	if args.test:
		test()
	else:
		train()