# Python深浅拷贝

直接赋值：对象的别名

浅拷贝(copy)：只拷贝父对象，不拷贝对象的内部子对象。

深拷贝(deep copy)：完全拷贝了父对象和子对象。

b = a.copy() ：???

深拷贝需要引入copy模块

import copy

c = copy.deepcopy(a)

b = a: 赋值引用

b = a.copy() ：浅拷贝，a b是堵路的对象，但是子对象还指向统一的对象。