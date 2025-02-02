# 目的

1. 解决开源库无法正常编译问题

# 依赖

```
1. jack 
2. sdl1.2
3. SDL_image (支持 PNG)


```


# 安装

```shell

sudo apt-get install libsdl-dev libsdl-image1.2-dev libjack-jackd2-dev  libsdl1.2-dev sudo apt-get install libsdl2-image-dev

./configure


make


su -c "make install"

```

# 测试

1. 需先启动jack服务 qjackctl(可用这个启动) 

```
meterbridge -t dpm system:capture_1  system:capture_2
```

2. 如果您想查看您的JACK系统正在输出什么，可以使用：
```
meterbridge -t ppm system:playback_1 system:playback_2

```

# 链接:
* http://wiki.libsdl.org/
* http://plugin.org.uk/meterbridge/



