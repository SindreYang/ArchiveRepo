'''
跟着图走

'''
import torch.nn as nn

#我们首先建立G
class G(nn.Module):
    def __init__(self,args):
        super(G,self).__init__()
        ngf = args.ngf  #ndf 设置为128  卷积一般扩大两倍 参数为4,2,1
        self.G_layer= nn.Sequential(
            # 输入的相当于nz*1*1
            nn.ConvTranspose2d (args.nz, ngf * 8, 4, 1, 0, bias=False),
            nn.BatchNorm2d (ngf * 8),
            nn.ReLU (True),
            # (ngf*8) x 4 x 4
            nn.ConvTranspose2d (ngf * 8, ngf * 4, 4, 2, 1, bias=False),
            nn.BatchNorm2d (ngf * 4),
            nn.ReLU (True),
            # (ngf*4) x 8 x 8
            nn.ConvTranspose2d (ngf * 4, ngf * 2, 4, 2, 1, bias=False),
            nn.BatchNorm2d (ngf * 2),
            nn.ReLU (True),
            # (ngf*2) x 16 x 16
            nn.ConvTranspose2d (ngf * 2, ngf, 4, 2, 1, bias=False),
            nn.BatchNorm2d (ngf),
            nn.ReLU (True),
            # (ngf) x 32 x 32
            nn.ConvTranspose2d (ngf, 3, 4, 2, 1, bias=False),
            nn.Tanh ())
            # 3 x 64 x 64
        
        
        
    #前向传播
    def forward(self,x):
        out=self.G_layer(x)
        return out

#建立D
class D(nn.Module):
    def __init__(self,args):
        super(D,self).__init__()
        ndf = args.ndf  # ndf 128
        self.D_layer= nn.Sequential(
                # 输入 3 x 64 x 64,
                nn.Conv2d(3,ndf,4,2,1),
                nn.BatchNorm2d (ndf),
                nn.LeakyReLU (True),
                #输出 (ndf)*32*32
                nn.Conv2d(ndf,ndf*2,4,2,1),
                nn.BatchNorm2d (ndf*2),
                nn.LeakyReLU (True),
                # 输出 (ndf*2)*16*16
                nn.Conv2d (ndf*2, ndf*4, 4, 2, 1),
                nn.BatchNorm2d (ndf*4),
                nn.LeakyReLU (True),
                # 输出 (ndf*4)*8*8
                nn.Conv2d (ndf*4, ndf*8, 4, 2, 1),
                nn.BatchNorm2d (ndf*8),
                nn.LeakyReLU (True),
                # 输出 (ndf*8)*4*4
                nn.Conv2d (ndf * 8, 1, 4, 1, 0),
                # 输出 1*0*0
                nn.Sigmoid())#告诉D概率
                
    #前向传播
    def forward(self,x):
        out=self.D_layer(x)
        return out

