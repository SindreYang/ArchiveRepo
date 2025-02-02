'''
跟着图走

'''
import torch.nn as nn

#我们首先建立G (由一个编码器,一个解码器构成)
class G(nn.Module):
    def __init__(self,args):
        super(G,self).__init__()
        ngf = args.ngf  #ngf 设置为128  卷积一般扩大两倍 参数为4,2,1
        self.encoder= nn.Sequential(
            # 输入一个真实图像3*64*64
            nn.Conv2d (3, ngf, 4, 2, 1, bias=False),
            nn.BatchNorm2d (ngf),
            nn.LeakyReLU (True),
            # (ngf) x 32x 32
            nn.Conv2d (ngf, ngf * 2, 4, 2, 1, bias=False),
            nn.BatchNorm2d (ngf * 2),
            nn.LeakyReLU (True),
            # (ngf*2) x 16 x 16
            nn.Conv2d (ngf * 2, ngf, 4, 2, 1, bias=False),
            nn.BatchNorm2d (ngf),
            nn.LeakyReLU (True))
       
        #还原尺寸
        self.decoder = nn.Sequential (
                                 nn.ConvTranspose2d(ngf,ngf*2,4,2,1),
                                 nn.BatchNorm2d(ngf*2),
                                 nn.ReLU(),
                                 nn.ConvTranspose2d (ngf*2,ngf,4,2,1),
                                 nn.BatchNorm2d (ngf),
                                 nn.ReLU (),
                                 nn.ConvTranspose2d (ngf, 3, 4, 2, 1),
                                 nn.Tanh ())
                                 
        #3*64*64
        
    #前向传播
    def forward(self,x):
        out=self.encoder(x)
        out_x=self.decoder(out)
        #print(out_x.size())
        return out_x

#建立D
class D(nn.Module):
    def __init__(self,args):
        super(D,self).__init__()
        ndf = args.ndf  # ndf 128
        self.D_layer= nn.Sequential(
                # 输入 1 x 64 x 64,
                nn.Conv2d (3, ndf, 4, 2, 1, bias=False),
                nn.BatchNorm2d (ndf),
                nn.LeakyReLU (True),
                #输出 (ndf)*32*32
                nn.Conv2d(ndf,ndf*2,4,2,1, bias=False),
                nn.BatchNorm2d (ndf*2),
                nn.LeakyReLU (True),
                # 输出 (ndf*2)*16*16
                nn.Conv2d (ndf*2, ndf*4, 4, 2, 1, bias=False),
                nn.BatchNorm2d (ndf*4),
                nn.LeakyReLU (True),
                # 输出 (ndf*4)*8*8
                nn.Conv2d (ndf*4, ndf*8, 4, 2, 1, bias=False),
                nn.BatchNorm2d (ndf*8),
                nn.LeakyReLU (True),
                # 输出 (ndf*8)*4*4
                nn.Conv2d (ndf * 8, 1, 4, 1, 0, bias=False),
                # 输出 1*1*1
                nn.Sigmoid())#告诉D概率
                
    #前向传播
    def forward(self,x):
        out=self.D_layer(x)
        return out



