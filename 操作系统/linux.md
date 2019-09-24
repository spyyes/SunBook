## 常用命令

```sh
$ grep -r "word" <path>
```

```
$ ssh sensetime@10.9.111.1
$ scp sensetime@10.9.111.1:/pkg/...
```

查看本机ip地址

```
$ ifconfig
eno1 inet地址 10.4.100.201
```





/proc 目录
通过/proc文件系统，在运行时访问内核的内部数据结构、改变内核设置。
它只存在于内存中，不占用内存空间，以文件系统的方式为方位系统内核数据的操作提供接口。

在读取proc文件时，proc文件系统是动态从系统内核读取出所需要的信息并提交。
/proc下有三个重要的目录：
/proc/net
/proc/scsi
/proc/sys 可写，访问修改内核参数
/proc/cpuinfo cpu信息，physical id 几颗cpu；processor每颗的核数

查看系统负载的常用命令
w
uptime
其中的load average就是平均负载

vmstat 可以展现给定时间间隔的服务器的状态值，包括cpu和内存的使用率，虚拟内存的交换情况和io读写等。
相比top命令，可以看到整个机器的cpu内存和io的情况，而不只是单单看到各个进程的。使用场景不同。
r 运行队列
b 阻塞的进程
swpd 虚拟内存已使用大小
free 空闲的物理内存大小
buff 用来存储目录中的内容和权限等缓存
catch 记忆我们打开的文件，给文件做缓冲
si 每秒从磁盘读入虚拟内存的大小，如果大于0，表示物理内存不够或内存泄露
so 每秒虚拟内存写入磁盘的大小
us用户cpu时间
bi表示有多少数据从磁盘读入内存 单位都是kb
bo表示有多少数据从内存写入磁盘
sy 系统cpu时间
id 空闲cpu时间
wa 等待io的cpu时间

nux系统里，您知道buffer和cache如何区分吗？

答：

buffer和cache都是内存中的一块区域，当CPU需要写数据到磁盘时，由于磁盘速度比较慢，所以CPU先把数据存进buffer，然后CPU去执行其他任务，buffer中的数据会定期写入磁盘；当CPU需要从磁盘读入数据时，由于磁盘速度比较慢，可以把即将用到的数据提前存入cache，CPU直接从Cache中拿数据要快的多。

top查看系统资源占用情况
virt虚拟内存用量
res物理内存用量
shr共享内存用量
mem 内存用量

实时查看网卡流量
sysstat安装之后 用sar查看


查看有哪些进程 ps -aux | ps -elf
stat一列表示这个进程的状态
S表示正在休眠；
s表示主进程；
Z表示僵尸进程

查看系统开启了哪些端口
netstat -lnp

查看网络连接状况
netstat -an

修改ip，需要编辑哪个配置文件，如果重启网卡，使配置生效
/etc/sysconfig/network-scripts/ifcfg-eth0
重启网卡
ifdown eth0
ifup eth0
重启网络服务
service network restart

给一个网卡配置多个ip
查看配置 /etc/sysconfig/network-scripts/ifcfg-eth0

查看当前主机名
hostname 
修改主机名 hostname [name]
重启后仍然生效 vim /etc/sysconfig/network
NETWORKING=yes
HOSTNAME=..

设置DNS需要修改哪个配置文件
/etc/resolv.conf

ls
ls -l 列出长字符串，包括文件熟悉和权限数据
ls -a 列出全部文件，连同隐藏文件
ls -d 列出目录本身，而不是列出目录的文件数据
ls -h 将文件容量用易读的方式列出来
ls -R 连同子目录的内容一起列出

grep命令
grep [-acinv] [--color=auto] '' filename

-a 将binary文件用text文件的方式查找数据
-c 计算找到的次数
-i 忽略大小写
-v 反向选择，即列出没有找到的行

--color=auto是把找到的关键字加上颜色


find命令

find [PATH] [option] [action]
-mtime n 在n天之前的一天内被更改的文件
-mtime +n 在n天之前(不含n天本身) 被更改的文件
-mtime -n 在n天之内(含n天本身) 被更改的文件
-newer file 列出比file还要新的文件名

-user name 
-group name 
-uid n 列出问卷所有者为用户ID为n的文件
-gid n 列出文件所属用户组为用户组ID为n的文件

-name filename 支持正则表达式
-size [+-size] 查找比size还要大或小的文件
-type TYPE TYPE的值主要有一般文件f 设备文件(b c) 目录(d) 连接文件(l) socket(s) FIFO管道文件(p)

-perm mode 查找文件权限刚好等于mode的文件，mode用数字表示
-perm -mode 查找文件权限必须要全部包含mode权限的文件
-perm +mode 查找文件权限包含任意mode的权限的文件

cp
cp -a 连同文件特性一起复制
-p 连同文件属性一起的复制，常常用于备份
-i 如果目标文件已经存在，在覆盖时会先询问操作的进行
-r 递归持续复制，用于目录的复制行为
-u 目标文件与源文件有差异时才会复制

mv -f 强制
-i 如果目标存在，会询问是否复制
-u 如果目标已经存在，且比目标文件新，才会更新

rm -f 
rm -i 互动，在删除钱会询问用户是否操作
-r 递归删除，是一个非常危险的参数

ps
-A 显示所有进程
-a 不与terminal有关的所有进程
-u 有效用户的相关进程
-x 一般与-a一起使用，可以列出比较完整的信息
-l 较长，详细列出

ps aux 系统所有新城的数据
ps ax 不与terminal有关的进程
ps -lA 系统所有进程数据
ps axjf 一部分进程数状态

kill -signal pID
1 启动 sighup
2 强行中断 sigint 
9 强制中断进程执行 sigkill
15 正常方式总结 sigterm
17 暂停 sigstop

killall -i 
-e
-I 忽略大小写

file 显示文件基本数据
因为在Linux下文件的类型并不是以后缀为分的

tar 文件打包
-c 新建打包文件
-t 查看打包文件的内容包含哪些文件名exi
tar -jcv -f filename;;
