#pytorch
import torch
import torch.nn as nn
import  torchvision.datasets as datasets
import  torchvision.transforms as  transforms
from torch.autograd import Variable

#工具包
import argparse
#载入网络
from CNN import CNN

#############参数设置#############
####命令行设置########
parser = argparse.ArgumentParser(description='CNN') #导入命令行模块
#对于函数add_argumen()第一个是选项，第二个是数据类型，第三个默认值，第四个是help命令时的说明
parser.add_argument('--batch-size', type=int, default=64, metavar='N',
                    help='训练batch-size大小 (default: 64)')
parser.add_argument('--epochs', type=int, default=10, metavar='N',
                    help='训练epochs大小 (default: 10)')
parser.add_argument('--lr', type=float, default=0.001, metavar='LR',
                    help='学习率 (default: 0.001)')
parser.add_argument('--no-cuda', action='store_true', default=False,
                    help='不开启cuda训练')
parser.add_argument('--seed', type=int, default=1, metavar='S',
                    help='随机种子 (default: 1)')
parser.add_argument('--log-interval', type=int, default=50, metavar='N',
                    help='记录等待n批次 (default: 50)')
parser.add_argument('--network', type=str, default='CNN', metavar='N',
                    help='which model to use, CNN|NIN|ResNet')
args = parser.parse_args()#相当于激活命令


args.cuda = not args.no_cuda and torch.cuda.is_available()#判断gpu

torch.manual_seed(args.seed)
if args.cuda:
    torch.cuda.manual_seed(args.seed)#为CPU设置种子用于生成随机数，以使得结果是确定的
    
    
###############数据载入################
train_dataset=datasets.MNIST(root="./data/",#保存目录
                             train=True,  #选择训练集
                             transform=transforms.ToTensor(), #把数据转换成pytorch张量 Tensor
                             download=True) #是否下载数据集
test_dataset=datasets.MNIST(root='./data/',
                            train=False,#关闭 表示选择测试集
                            transform=transforms.ToTensor(),
                            download=True)

##############数据装载###############
train_loader=torch.utils.data.DataLoader(dataset=train_dataset,#装载数据
                                         batch_size=args.batch_size,#设置批大小
                                         shuffle=True)#是否随机打乱
test_loader=torch.utils.data.DataLoader(dataset=test_dataset,
                                         batch_size=args.batch_size,
                                         shuffle=True)

#############模型载入#################
cnn=CNN()
if not args.no_cuda:
    print('正在使用gpu')
    cnn.cuda()
print(cnn)

###############损失函数##################
criterion=nn.CrossEntropyLoss()#内置标准损失
optimizer=torch.optim.Adam(cnn.parameters(),lr=args.lr)#Adam优化器

#############训练过程#####################
for epoch in range (args.epochs):
    for i, (images,labels) in enumerate(train_loader):#枚举出来
        if not  args.no_cuda:#数据处理是否用gpu
            images=images.cuda()
            labels=labels.cuda()
        
        
        images=Variable(images)#装箱
        labels=Variable(labels)
        
        ##前向传播
        optimizer.zero_grad()
        outputs=cnn(images)
        #损失
        loss=criterion(outputs,labels)
        #反向传播
        loss.backward()
        optimizer.step ()
        ##打印记录
        
        if (i+1)% args.log_interval==0:
            print('Epoch [%d/%d], Iter [%d/%d] Loss: %.4f'
                   %(epoch+1, args.epochs, i+1, len(train_dataset)//args.batch_size, loss.item()))
            
            
        #保存模型
        torch.save(cnn.state_dict(), 'cnn.pkl')