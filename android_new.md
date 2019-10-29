### 安卓应用代码结构

```sh
src: 
  MainActivity.java 源文件对应的活动类
  gen 由编译器生成的.R文件，引用了所有项目中的资源，不能被修改。
  bin 由APT构建的.apk包文件，以及运行安卓
  res/drawable 一般存放图片文件
  res/layout
  res/values 
  AndroidManifest.xml 应用程序的清单，描述了应用程序的基础特性，定义各种组件
```

#### 访问资源

- 资源在安卓程序被编译，生成一个R类，包含了res/目录下资源的ID， findViewByID(R.string.hello)
-  在xml中访问 `"@string/hello"`

### Activity

```
  onCreate()
  onRestart() 
  onStart()
  onResume()
  Activity Running
  onPause()
  onStop()
  onDestroy()
```


Log.d()用来生成日志信息， import android.util.Log;

### Service

是后台运行的组件，有两种状态，`Started`和`Bound`。

Bound : 安卓应用程序组件通过bindService()绑定服务，那么服务就是Bound状态，提供了一个客户服务器接口来允许组件与服务进行交互，如发送请求、获取结果、甚至通过IPC进行跨进程通信。

#### 创建自己的Android 服务

### 广播接收器

> 用于响应其他应用程序或系统的广播消息。

无论什么时候Android设备被启动，都将被广播接收器MyReceiver所拦截。

```
sendBroadcast() //创建并发送意图
sendStickyBroadcast() //持久意图
```

在MyReceriver extends BroadcastReceiver中实现`onReceive`函数。

每个你想拦截的意图都需要使用`<receiver../>`标签在AndroidManifest.xml中注册。

修改`res/layout/activity_main.xml`文件中的默认内容来包含一个广播意图的按钮。

### 内容提供者

> 通过请求从一个应用程序向其他的应用程序提供数据，这些请求由ContentResolver方法来处理。

被实现为`ContentProvider`类的子类，需要实现一系列标准的API，以便其他应用程序来执行事务。

要查询内容提供者，需要给定内容URL。

创建内容提供者，需要继承类ContentProviderbase来创建一个内容提供者类，需要定义URL地址。接下来，需要创建数据库保存内容，通常Android使用SQLite数据库，并在框架中重写onCreate()方法来使用SQLiteOpenHelper方法创建或打开数据库。

使用`<provider../>`标签在AndroidManifest.xml中注册内容提供者。

### 碎片

碎片有自己的生命周期，与Android活动很相似。

### 意图与过滤器

安卓意图是一个要执行的操作的抽象描述，可以通过`startActivity`来启动一个活动，broadcastIntent来发送广播到任何它感兴趣的广播接受器组件。

意图本身是一个被动的数据接口，保存着要执行操作的抽象描述。

意图分为两种类型，显式意图和隐式意图。

