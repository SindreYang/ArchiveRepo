'''
为了简单明了,所以今天还是创最最简单的GAN

首先 有两个网络 分别是G D

'''
import torch.nn as nn

#我们首先建立G
class G(nn.Module):
    def __init__(self,args):
        super(G,self).__init__()
        ngf = args.ngf  # 生成器feature map数(该层卷积核的个数，有多少个卷积核，经过卷积就会产生多少个feature map)
        self.G_layer= nn.Sequential(
                #输入是一个nz维度的噪声，我们可以认为它是一个1 * 1 * nz的feature map
                nn.ConvTranspose2d(args.nz, 3,5,1,0),# 反conv2d
                nn.BatchNorm2d (3),
                nn.LeakyReLU(True),)
                # 输出大小为3*5*5

    #前向传播
    def forward(self,x):
        out=self.G_layer(x)
        return out

#建立D
class D(nn.Module):
    def __init__(self,args):
        super(D,self).__init__()
        ndf = args.ndf  # 生成器feature map数(该层卷积核的个数，有多少个卷积核，经过卷积就会产生多少个feature map)
        self.D_layer= nn.Sequential(
                # 输入 3 x 5 x 5,
                nn.Conv2d(3,ndf, 3),
                nn.BatchNorm2d (ndf),
                nn.LeakyReLU (True),
                #输出 (ndf)*1*1
                nn.Conv2d (ndf,1,1),
                # 输出 1*0*0
                nn.Sigmoid())#告诉D概率
                
    #前向传播
    def forward(self,x):
        out=self.D_layer(x)
        return out

