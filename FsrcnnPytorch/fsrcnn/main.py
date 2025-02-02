from __future__ import print_function

import argparse

from torch.utils.data import DataLoader

from run import FSRCNNTrainer
from dataset.data import get_training_set, get_test_set

# ===========================================================
# 训练参数设置
# ===========================================================
parser = argparse.ArgumentParser(description='PyTorch——fsrcnn')

parser.add_argument('--batchSize', type=int, default=1, help='训练 batch size')
parser.add_argument('--testBatchSize', type=int, default=1, help='测试 batch size')
parser.add_argument('--nEpochs', type=int, default=20, help='训练 epochs 数')
parser.add_argument('--lr', type=float, default=0.01, help='学习率. Default=0.01')
parser.add_argument('--seed', type=int, default=123, help='随机种子. Default=123')

# model configuration
parser.add_argument('--upscale_factor', '-uf',  type=int, default=4, help="提升分辨率数")

args = parser.parse_args()


def main():
    # ===========================================================
    # 设置train dataset & test dataset
    # ===========================================================
    print('===> Loading datasets')
    train_set = get_training_set(args.upscale_factor)
    test_set = get_test_set(args.upscale_factor)
    training_data_loader = DataLoader(dataset=train_set, batch_size=args.batchSize, shuffle=True)
    testing_data_loader = DataLoader(dataset=test_set, batch_size=args.testBatchSize, shuffle=False)

    model = FSRCNNTrainer(args, training_data_loader, testing_data_loader)
    model.run()


if __name__ == '__main__':
    main()