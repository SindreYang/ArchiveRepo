from __future__ import print_function
import argparse
import torch
import torch.backends.cudnn as cudnn
from PIL import Image
from torchvision.transforms import ToTensor

import numpy as np

# ===========================================================
# 参数
# ===========================================================
parser = argparse.ArgumentParser(description='PyTorch ')
parser.add_argument('--input', type=str, required=False, default=r'E:\test_working\fsrcnn\dataset\BSDS300\input\input.jpg', help='输入图片路径')
parser.add_argument('--model', type=str, default='model_path.pth', help='模型参数路径')
parser.add_argument('--output', type=str, default='test.jpg', help='输出图片路径')
args = parser.parse_args()
print(args)


# ===========================================================
# 输入图片
# ===========================================================
GPU_IN_USE = torch.cuda.is_available()
img = Image.open(args.input).convert('YCbCr')
y, cb, cr = img.split()


# ===========================================================
# 模型载入
# ===========================================================
device = torch.device('cuda' if GPU_IN_USE else 'cpu')
model = torch.load(args.model, map_location=lambda storage, loc: storage)
model = model.to(device)
data = (ToTensor()(y)).view(1, -1, y.size[1], y.size[0])
data = data.to(device)

if GPU_IN_USE:
    cudnn.benchmark = True


# ===========================================================
# 输出图片
# ===========================================================
out = model(data)
out = out.cpu()
out_img_y = out.data[0].numpy()
out_img_y *= 255.0
out_img_y = out_img_y.clip(0, 255)
out_img_y = Image.fromarray(np.uint8(out_img_y[0]), mode='L')

out_img_cb = cb.resize(out_img_y.size, Image.BICUBIC)
out_img_cr = cr.resize(out_img_y.size, Image.BICUBIC)
out_img = Image.merge('YCbCr', [out_img_y, out_img_cb, out_img_cr]).convert('RGB')

out_img.save(args.output)
print('输出图片保存在： ', args.output)