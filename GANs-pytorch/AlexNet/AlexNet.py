import torch

#跟着第一幅图走
class AlexNet(torch.nn.Module):
    def __init__(self):
        super(AlexNet, self).__init__()
        # 输入图片大小 227*227*3
		#第一层
        self.conv1 = torch.nn.Sequential(
			#卷积
            torch.nn.Conv2d(in_channels=3, out_channels=96, kernel_size=11, stride=4, padding=0),
            # (227-11)/4+1=55,  输出图片大小:55*55*96
            torch.nn.ReLU(),#激活层
            torch.nn.MaxPool2d(kernel_size=3, stride=2, padding=0)
            # (55-3)/2+1=27, 输出图片大小: 27*27*96
        )

        # 从上面获得图片大小27*27*96
        self.conv2 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels=96, out_channels=256, kernel_size=5, stride=1, padding=2),
            # （27-5 + 2*2）/ 1 + 1 = 27, 输出图片大小:27*27*256
            torch.nn.ReLU(),
            torch.nn.MaxPool2d(kernel_size=3, stride=2, padding=0)
            # (27 - 3 )/2 + 1 = 13, 输出图片大小:13*13*256
        )

        # 从上面获得图片大小13*13*256
        self.conv3 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels=256, out_channels=384, kernel_size=3, stride=1, padding=1),
            # (13 - 3 +1*2)/1 + 1 = 13 , 输出图片大小:13*13*384
            torch.nn.ReLU()
        )

        # 从上面获得图片大小13*13*384
        self.conv4 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels=384, out_channels=384, kernel_size=3, stride=1, padding=1),
            # (13 - 3 + 1*2)/1 +1 = 13, 输出图片大小:13*13*384
            torch.nn.ReLU()
        )

        # 从上面获得图片大小13*13*384
        self.conv5 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels=384, out_channels=256, kernel_size=3, stride=1, padding=1),
            # (13 - 3 + 1*2) +1 = 13, 13*13*256
            torch.nn.ReLU(),
            torch.nn.MaxPool2d(kernel_size=3, stride=2, padding=0)
            # (13 - 3 )/2 +1 =6, 6*6*256
        )

        # 从上面获得图片大小 6*6*256 = 9216 共9216输出特征
        self.lostlayer = torch.nn.Sequential(
			#第六层
            torch.nn.Linear(9216, 4096),#全连接
            torch.nn.ReLU(),#激活层
            torch.nn.Dropout(0.5),#以0.5&几率随机忽略一部分神经元
			
			#第七层
            torch.nn.Linear(4096, 4096),
            torch.nn.ReLU(),
            torch.nn.Dropout(0.5),
			
			#第八层
            torch.nn.Linear(4096, 2)
            # 最后输出2 ,因为只分猫狗两类
        )

	#前向传播
    def forward(self, x):
        conv1_out = self.conv1(x)
        conv2_out = self.conv2(conv1_out)
        conv3_out = self.conv3(conv2_out)
        conv4_out = self.conv4(conv3_out)
        conv5_out = self.conv5(conv4_out)
        res = conv5_out.view(conv5_out.size(0), -1)#展平多维的卷积图成 一维(batch_size, 4096)
        out = self.lostlayer(res)
        return out
