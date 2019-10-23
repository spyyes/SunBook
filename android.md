<<<<<<< HEAD
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
=======
# 阅读安卓源码
>>>>>>> 4933a719252967492f7fcd363e2f37dc006f28d5

HIDL
 hardware interface definition laguage
 旨在用于进程间通信(IPC), 进程之间的通信经过Binder化。
框架可以在无需重新构建HAL的情况下进行替换
HAL将由供应商或soc制造商构建，放置在设备的/vendor分区中。
这样，框架就可以在自己的分区中通过ota进行替换，无需重新编译hal。

？什么叫无需重新编译hal
hadl是围绕接口进行编译的，每个接口都是软件包的一部分。
已发布的HIDL软件包的根目录是hardware/interfaces 或 vendor/vendorName

软件包目录中包含扩展名为.hal的文件，每个文件都必须包含一个制定文件所属的软件包和版本的package语句。

文件types.hal并不定义接口，而是定义软件包中每个接口可以访问的数据类型。
其他的.hal文件均定义一个接口。

hal还有接口哈希，之后再研究吧。

bsp 板级支持包
核心是：
1） linux 内核硬件相关部分 (linux drivers
2） linux bsp : 比如cpu,电源管理比驱动更深入的硬件支持包
3） android 用户空间的硬件抽象层 (HAL hardware abstract layer
在有了特定的硬件平台后，为了适应不同版本的android系统，BSP部分代码通常需要重写或修改。
目前一般的处理器或者硬件平台的BSP（board support package）都是由芯片厂商统一完成的。因此开发者的主要工作不再是构建完整的BSP，而是调试和修改现有的BSP。

AOSP android open source project android开放源代码项目
一般有 camera audio sensor bluetooth 等 hal

google理论上只关心android的框架层和上层软件，每家手机厂商，或者cpu厂商底层硬件的实现都不同，所以这个HAL层基本都是手机厂商或CPU厂商去实现的


什么是共享库

程序函数库可以分成 static | shared | dynamically loaded

动态函数库和共享函数库是一个东西，在linux上叫共享对象库，后缀名是.so，windows上叫动态加载函数库，文件后缀是.dll
静态函数库的后缀一般是.a，允许程序员把程序link起来，而不用重新编译代码，节省了重新编译代码的时间。不够现在程序编译也不需要很久，所以优势不明显，还有优势在于想把自己开发的库提供给别人使用，但是又想对源程序进行保密，就可以提供一个静态函数库。
使用elf格式的静态库函数生成的代码可以比使用共享汉化诉苦的程序运行快一些。

共享库的命名：

共享函数库
当一个可执行文件在被启动的时候加载。如果一个共享函数库正常安装，所有的程序在重新运行的时候都可以自动加载最新的函数库的函数。

共享库命名的时候都要以lib作为开头，然后是函数库的名字，然后是.so，最后是版本号信息。不过有特例，就是非常底层的C库函数都不是以lib开头命名。

有soname, real nam

环境变量
LD_LIBRARY_PATH


### elf文件格式
是linux的主要可执行文件格式
由4部分组成：elf头、程序头表、节、节头表。
事实上，一个文件中不一定包含全部内容，只有elf头是固定的。其余各部分的位置、大小由elf头的各项值决定。
一般用于二进制文件、可执行文件、目标代码、共享库、核心转储格式。



