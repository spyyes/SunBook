虚函数：有virtual 关键字的成员函数
只用在函数声明时，不用在写函数体时
在父类和之类都要声明

区分 重载 & 覆盖 & 多态

多态表现
虚函数的用途：
通过基类指针|引用调用同名虚函数时：
（1）若指向基类对象，那么被调用的是基类虚函数
（2）若指向派生类对象，那么被调用的是派生类虚函数

多态的作用：
能够增强程序的可扩充性，即程序需要修改或增加功能的时候，需要改动和增加的代码较少。
注意：在构造和析构函数中调用虚函数，不是多态。
派生类和基类中虚函数同名同参数表的函数，不加virtual也自动成为虚函数。

qsort(pShapes, n, sizeof(CShape *), Mycompare);

int MyCompare(const void * s1, const void * s2){
    CShape ** c1 = (CShape **) s1;
    a1 = 
}

注意：虚函数的访问权限：
如果基类中是private，派生类是public，也会编译出错。

多态的实现原理：
通过基类指针或引用调用一个虚函数时，编译时不确定调用的是基类还是派生类的函数，运行时才确定。这叫做“动态联编”。
多态实现的关键在于 虚函数表。
每一个有虚函数的类都有一个虚函数表。该类的任何对象都存放着虚函数表的指针。虚函数表列出了该类的虚函数地址。
多出来的4个直接就是用来存放虚函数表的地址的。

多态的函数调用语句被编译成一系列根据基类指针指向的对象中存放的虚函数表的地址，在虚函数表中查找虚函数地址，并调用虚函数指令。

虚析构函数：
用于：
通过基类指针删除派生类对象，通常只会调用基类的析构函数。
解决办法：把基类的析构函数声明为virtual，派生类的可以不声明。

一般来说，如果一个类定义成了虚函数，那么也应该将析构函数定义成虚函数。
或者，一个类打算作为基类使用，那么也应该将析构函数定义成虚函数。

不允许用虚函数作为构造函数

纯虚函数：没有函数体的虚函数
virtual void Print() = 0;
包含纯虚函数的类叫做抽象类。
只能作为基类，不能创建对象。
如果A是抽象类，那么A a;//编译错误
但是可以定义指针和引用指向派生类对象。

在抽象类的成员函数内部可以调用纯虚函数。
但是构造函数或析构函数不能调用纯虚函数。

只有实现了基类的所有纯虚函数，才能成为非抽象类。
