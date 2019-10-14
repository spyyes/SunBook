### sed一行的查找和替换

```sh
sed -i "/^\s*versionName\s\".*\"$/s/\".*\"/\"$ID\"/g" ./FaceUnlockDemo/build.gradle
```

**注意：**

1. 如果用到参数，那么需要用双引号而不是单引号
2. `-i`是指定修改原文件，如果不加`-i`，不会修改原文件
3. `/s`是找到行之后用于替换

### linux 脚本

1. 变量声明和赋值的时候不能加`$`，在使用的时候需要加`$`，赋值的时候的等号不能加空格。
2. `$1`是命令行的第一个参数，`$2`是命令行的第二个参数。
3. `$?`是上一个命令的执行结果，为0代表一切正常。
4. 字符串的拼接 `$str1$str2`

### studio里一键注释 ctrl + /，会自动匹配语言

### studio里一键删除一行 ctrl + y

### 命令行里一键删除输入 ctrl + u

### .gitignore文件

git中指定忽略这些文件的提交。比如/build

### git 丢弃当前分支所有本地修改

```sh
git reset --hard origin/master
```

### git fetch & git pull

因此，与git pull相比git fetch相当于是从远程获取最新版本到本地，但不会自动merge。如果需要有选择的合并git fetch是更好的选择。效果相同时git pull将更为快捷。

### git 将A分支的修改同步到B分支

```sh
git checkout B
git cherry-pick A <file>
```

### mmm

在TA/CA项目中用到。在build/envsetup.sh中设置环境。

mmm是安卓项目构建。

### SConstruct文件

> http://www.360doc.com/content/16/0421/17/478627_552627544.shtml

相当于Makefile文件，TA部分的项目用到了Scons构建。

内容是Python脚本，scons读入它时，会把脚本命令都读一遍。

Library() 库编译

StaticLibrary()显式编译静态库

SharedLibrary 编译动态库

Program()库链接

### adb remount

将/system部分置于可写入的模式，默认情况下/system只是只读模式。

只适用于被root的设备。

### Makefile.am

比Makefile更高级的编译规则。

### GCC编译

### Makefile

在构建项目时经常会用到。

> http://www.ruanyifeng.com/blog/2015/02/make.html

### 编译时多态和运行时多态

方法重载是编译时多态。

@Override 和 @Overload

### scp传输到本地

```sh
scp (-r) sensetime@10.9.111.1：name
```



