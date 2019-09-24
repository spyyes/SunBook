### 操作系统的三个能力

- 资源管理
  - 
- 向用户提供服务
- 扩展机器





DIR direct

# Linux下DIR，dirent,stat等结构体详解

https://blog.csdn.net/zhuyi2654715/article/details/7605051

位于的头文件

**DIR**

DIR是目录文件结构，保存当前正在被读取的目录的有关信息

DIR *opendir(const char *pathname)，即打开文件目录



DIR 指针被用于几个函数

direct 结构体

目录文件：包含了其他文件的名字以及指向这些文件有关的信息的指针

# Linux 设置

linux 环境变量设置：

1.一次性设置:

```sh
#export PATH=$PATH:{path}
```

用`#export`查看是不是设置好了

2.修改 #vi /etc/profile 

```sh
$ sudo vi /etc/profile
#将下列语句加进去
export PATH="$PATH:{path}"
```

环境变量文件有两个文件：可选：“/etc/profile”和用户主目录下的“.bash_profile”，“/etc/profile”对系统里所有用户都有效，用户主目录下的“.bash_profile”只对这个用户有效。



Java安装

2.1 选择要安装java的位置，如/usr/目录下，新建文件夹java(mkdir java)

2.2 将文件jdk-7u40-linux-i586.tar.gz移动到/usr/java

2.3 解压：tar -zxvf jdk-7u40-linux-i586.tar.gz

至此，jkd安装完毕，下面配置环境变量

3、打开/etc/profile（vim /etc/profile）
在最后面添加如下内容：

```
JAVA_HOME=/usr/java/jdk1.7.0_79
JRE_HOME=/usr/java/jdk1.7.0_79/jre
CLASS_PATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar:$JRE_HOME/lib
PATH=$PATH:$JAVA_HOME/bin:$JRE_HOME/bin
export JAVA_HOME JRE_HOME CLASS_PATH PATH
```

在~/.bashrc中添加

5、验证是否安装成功：java -version

