## CA编译 -- 需在服务器端

由于CA编译需要用到高通源码及安卓内核代码(庞大)，因此CA编译需要在服务器端进行。

**服务器及账号：**

```sh
xiefei@10.9.111.1
```

**路径：**

```sh
/data/repo/android_sm8150/vendor/qcom/proprietary/securemsm/sunpeiyi/sampleclient
#需要修改build.sh & Android.mk两个配置文件
sudo su
./build.sh
#产生的结果在下面的目录
/data/repo/android_sm8150/out/target/product/msmnile/vendor/bin/qseecom_sample_client
```

将生成的ca pull到本地，再push到手机。

```sh
adb root
adb remount #将只读改为可写
adb push qseecom_sample_client /vendor/bin #/vendor/bin下会自动查找/vendor/lib下的so文件
# CA加载的TA路径在c中定义了，默认是/vendor/firmware_mnt/
```

### CA的使用方法

**看一下CA代码**

```sh
    ./qseecom_sample_client -v smplap64 19 1 2
```



### CA结构分析

```
./sampleclient
Android.mk
Makefile.am
content-protection_copy.h
README.md
 
```





## TA编译 -- 本地环境配置

**路径：**

```sh
./sm8150-la-1-0_amss_standard_oem/ #root
./sm8150-la-1-0_amss_standard_oem/trustzone_images/  #TEE源码
./sm8150-la-1-0_amss_standard_oem/trustzone_images/build/ms #编译的某些文件，这里是自动生成还是后天生成需要再看源码
		build_all.py
		build_config_deploy.xml
./sm8150-la-1-0_amss_standard_oem/trustzone_images/ssg/securemsm/trustzone/qsapps #TA位置
```

**修改路径：**

1. 修改build-config.xml中的配置

    llvm & ?

2. 修改SConScript的配置



**编译：**

```sh
./build.sh
#或
python trustzone_images/build/ms/build_all.py -b TZ.XF.5.0 CHIPSET=sm8150 sampleapp -c 2>&1
python trustzone_images/build/ms/build_all.py -b TZ.XF.5.0 CHIPSET=sm8150 stapp -v 2>&1 | tee "$@"
```





- 注册app：

配置本地环境

1. 

```sh
# 在编译时发现 LLVMBIN不存在，分析发现在
scons: warning: Ignoring missing SConscript '/home/SENSETIME/sunpeiyi/sm8150-la-1-0_amss_standard_oem/trustzone_images/ssg/bsp/trustzone/qsapps/deploy_sdk/build/SConscript'
File "/home/SENSETIME/sunpeiyi/sm8150-la-1-0_amss_standard_oem/trustzone_images/ssg/bsp/trustzone/build/SConscript", line 92, in <module>
** INFO: LLVMBIN   = /pkg/qct/software/llvm/release/arm/4.0.11/bin

/home/SENSETIME/sunpeiyi/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin
```

通过分析包含/pkg的所有文件，怀疑是

```sh
~/sm8150-la-1-0_amss_standard_oem/trustzone_images/build/ms$ vim ./build_config_deploy.xml
```

这个文件的配置。





修改llvm的路径



OK



只改了这一处，其他地方没有改，也可以吗？



** INFO: LLVMLIB          = /pkg/qct/software/llvm/release/arm/4.0.11/lib/clang/4.0.11/lib/linux



** INFO: LLVMINC          = /pkg/qct/software/llvm/release/arm/4.0.11/aarch64-none-elf/libc/include





```
==============================================================================
** INFO: LLVMBIN   = /home/SENSETIME/sunpeiyi/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin
** INFO: LLVMBIN          = /home/SENSETIME/sunpeiyi/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin
** INFO: LLVMLIB          = /pkg/qct/software/llvm/release/arm/4.0.11/lib/clang/4.0.11/lib/linux
** INFO: LLVMINC          = /pkg/qct/software/llvm/release/arm/4.0.11/aarch64-none-elf/libc/include
** INFO: LLVM32INC        = /pkg/qct/software/llvm/release/arm/4.0.11/armv7-none-eabi/libc/include
** INFO: LLVMTOOLPATH     = /pkg/qct/software/llvm/release/arm/4.0.11/tools/bin
** INFO: GNULIBC          = 
** INFO: GNUTOOL          = 
** INFO: GNUROOT          = /pkg/qct/software/arm/linaro-toolchain/aarch64-none-elf/4.9-2014.07
** INFO: GNUARM7          = /prj/llvm-arm/home/common/build_tools/gcc-linaro-arm-linux-gnueabihf-4.8-2014.02_linux
** INFO: MUSLPATH         = /pkg/qct/software/llvm/release/arm/4.0.11/aarch64-none-elf/libc
** INFO: MUSL32PATH       = /pkg/qct/software/llvm/release/arm/4.0.11/armv7-none-eabi/libc
** INFO: LLVMBIN   = /home/SENSETIME/sunpeiyi/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin
** INFO: LLVMBIN          = /home/SENSETIME/sunpeiyi/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin
** INFO: LLVMLIB          = /pkg/qct/software/llvm/release/arm/4.0.11/lib/clang/4.0.11/lib/linux
** INFO: LLVMINC          = /pkg/qct/software/llvm/release/arm/4.0.11/aarch64-none-elf/libc/include
** INFO: LLVM32INC        = /pkg/qct/software/llvm/release/arm/4.0.11/armv7-none-eabi/libc/include
** INFO: LLVMTOOLPATH     = /pkg/qct/software/llvm/release/arm/4.0.11/tools/bin
** INFO: GNULIBC          = 
** INFO: GNUTOOL          = 
** INFO: GNUROOT          = /pkg/qct/software/arm/linaro-toolchain/aarch64-none-elf/4.9-2014.07
** INFO: GNUARM7          = /prj/llvm-arm/home/common/build_tools/gcc-linaro-arm-linux-gnueabihf-4.8-2014.02_linux
** INFO: MUSLPATH         = /pkg/qct/software/llvm/release/arm/4.0.11/aarch64-none-elf/libc
** INFO: MUSL32PATH       = /pkg/qct/software/llvm/release/arm/4.0.11/armv7-none-eabi/libc
scons: done reading SConscript files.
scons: Cleaning targets ...
scons: done cleaning targets.

```



在第二步Python的时候出错

fatal error: 'stddef.h' file not found





在本地编译还是不过，远程编译是要在config.xml中注册吗？





想清楚本地编译的流程。

```
python trustzone_images/build/ms/build_all.py -b TZ.XF.5.0 CHIPSET=sm8150 sampleapp -c 2>&1
```



```

```

## 调试

```sh
adb logcat |grep qsee #查看所有安卓的log	
#查看ta的log
#查看ca的log
```

