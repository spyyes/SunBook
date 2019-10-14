## Gradle

`gradle.build`详细介绍

https://blog.csdn.net/hebbely/article/details/79074460

**.iml 格式** 

Itelligi 的 配置文件格式，不是项目本身的文件。

**Lint**

Android Studio 提供了一个名为 Lint 的代码扫描工具，可帮助您发现并更正代码结构质量的问题，而无需您实际执行应用，也不必编写测试用例。

**提示cannot resolve symbol**

重启visual studio

### Adapter

Adapter是用来帮助填充数据的中间桥梁，简单点说就是：将各种数据以合适的形式显示到view上,提供
给用户看。 

**RecyclerAdapter**

适用于RecyclerView。

RecyclerView只管回收与复用View，其他的你可以自己去设置。可以看出其高度的解耦，给予你充分的定制自由（所以你才可以轻松的通过这个控件实现ListView,GirdView，瀑布流等效果）。

函数：

```
setItemAnimator 动画效果
addItemDecoration 分割线
```

### Toast

 *Toast*用于向用户显示一些帮助/提示。

### inflator

实现动态布局



include dependency library

