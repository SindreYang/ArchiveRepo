# 信息

2018年，用于帮朋友实现全自动收集抖音上的账号信息。





## 使用教程

- Python版本：3.0及以上

- 相关软件工具安装和使用步骤请参考 [wechat_jump_game](https://github.com/wangshub/wechat_jump_game) 和 [Android 操作步骤](https://github.com/wangshub/wechat_jump_game/wiki/Android-%E5%92%8C-iOS-%E6%93%8D%E4%BD%9C%E6%AD%A5%E9%AA%A4)


## 注意

- 目前暂时只适配了 一加5(1920x1080 分辨率)，如果手机不是该分辨率，请修改 `config/` 文件夹下面的配置文件；
- `config.json`配置文件参考：
    - `center_point`: 屏幕中心点`(x, y)`，区域范围 `rx, ry`
    - `follow_bottom`: 关注按钮位置`(x, y)`，区域范围 `rx, ry`
    - `star_bottom`: 点赞按钮位置`(x, y)`，区域范围 `rx, ry`
    

## 原理

1. 基于开源的bot，主要针对每个截图进行提取有用信息 ，如所有用户名，个性签名等
