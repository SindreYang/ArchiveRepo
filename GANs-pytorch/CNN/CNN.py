import  torch.nn as nn

class CNN(nn.Module):
	def __init__(self):
		super(CNN, self).__init__()                                      # 输入MNIST 图片大小是(1,28,28)
		self.layer=nn.Sequential(nn.Conv2d(1,8,kernel_size=5,padding=2),#第一个参数,输入是1,表示输入图片通道为1 ,8表示输出,5卷积核大小,2补边大小
								 nn.BatchNorm2d(8),#归一化
								 nn.ReLU(),#激活层
								 nn.MaxPool2d(2),#池化层 到这 (8,28,28)图片就被池化成(8,14,14)了
								 )
		self.fc=nn.Linear(14*14*8,10)  #全连接层 第一个输入的特征数,第二个 输出的特征 (0-9) 共10特征
	
	#前向传播
	def forward(self, x):
		out=self.layer(x)
		out=out.view(out.size(0),-1)#展平多维的卷积图成 (batch_size, 32 * 7 * 7)
		out=self.fc(out)
		return out
	