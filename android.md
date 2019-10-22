# 安卓源码阅读

```sh
路径：/data/repo/

/android_sm8150 : 安卓源码及高通源码
/sdm8150: 高通855源码
```

```
/android
 /framework 常见框架都放在这
 /hardware 底层driver层和上层之间的中间层，起到屏蔽底层的作用。我们关于相机的处理都在这层。
 /driver 底层driver
 /external 依赖的第三方库
 /vendor 是google android 给手机芯片厂商(soc)提供的接口，因此我们常用的依赖和库都可以从这里找到。
 /proprietary 
```

```
/vendor/qcom/propeietary: 不知道这是什么意思

/securemsm 安全相关的？
QSEEComAPI #通信有关的API
QTEEConnecter #基础功能
各种CA样例代码,比如 sampleclient




```

```sh
Android.mk 是安卓代码构建的指令
include 所有的下层构建

LOCAL_PATH 
LOCAL_C_INCLUDES #依赖的头文件
LOCAL_SHARED_LIBARAIES #依赖的三方库

```

```
build.sh
lunch 50
lunch命令用来制定工具的适配平台，50代表msmnile，也即是当前版本
mmm 编译命令，只编译该应用
mm 连同依赖的库也编译
m 安卓源码编译，会很慢，安卓源码编译的结果会放在target/msmnile/...
android_sm8150/out/target/product/msmnile/...

```

```
qseecom_sample_client.c
load_whole_mbn #为了防攻击，经常会把编译出的ta切成多个小文件。这个指标表示是否采取这样的方案。

```

```
手机端
/vendor #一般是高通的东西
	/lib
	/lib64
	/firmware_mnt ta一般放在这里
/data #一般是用户数据，一般我们做开发的时候的数据放在这里
	/vendor #我们开发的东西一般和供应商有关，所以我们开发的东西一般放在这个文件夹下，然后会自动寻找依赖。
/mnt #挂载的系统，文件
mount #修改权限
/system 系统库
linux下
bin文件
/sdcard 资源文件，相当于移动硬盘的感觉
/data 应用文件
	/local 应用开发，有shell权限即可
/data/local/vendor/lib 与供应商相关的库文件
/data/local/vendor/bin 与供应商相关的可执行文件
LD_LIBRARY_PATH 指定库之后拷贝
```

```
linux常用命令
cat proc/cpuinfo #显示当前电脑的配置
meminfo 
sysdump 
adb shell meminfo --help
tee --help 将标准输出输出到某个文件中的

```

```
TEE开发 -- 高通
/data/repo/sm8150/sm8150-la-1-0_amss_standard_oem/trustzone_images
build/ms/ #一般build目录在每次编译的时候都应该重新生成，但看起来这里并不是这样
buikd_config_...xml
trustzone_image/ssg/qsapps/
sampleapp/build/Sconscript
```

```
stapp
build/Soncpipt
build脚本在某目录中找Scons脚本，并且是从上层往下层找
```

