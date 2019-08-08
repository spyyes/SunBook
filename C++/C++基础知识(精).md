# C++ 基础要点（精）

> 易错 | 难点 | 重点

**函数传参**

函数传参如果传值，拷贝实参到形参会带来开销；如果传引用，又担心不小心修改实参值，就需要传常引用

**负整数的二进制表示法**

绝对值取反+1，补上最高位的符号位

**函数指针**

每个函数都会占用一段连续的内存空间，函数名就是函数所占内存的起始地址。将函数入口地址赋一个指针，通过该指针就可以调用这个函数。

```c++
int *(pf)(int, int); //函数指针的定义

/* 使用实例 */
int printMin(int a, int b){...}; //函数
int main(){
    int (*pm)(int, int);
    pm = printMin;
    pm(x, y);
}
```

**异或运算的特点**

```c++
//交换两个变量的值
int a = 5, b = 7;
a = a ^ b;
b = b ^ a;
a = a ^ b;

a << b //易错：a的值不变
    
a <<= b; // 左移比乘法快的多

//重点：右移的时候永远是下取整，因此正数绝对值变小；负数绝对值变大

//求最高位的值
(a & (1 << n)) >> n, n < 31
//易错：，注意如果n是31，那么结果就不对了！！因为右移补1了
```

**引用：已经初始化之后不能改变引用的对象**

```c++
int main(){
    int a = 1, b = 2;
    int & r1 = a;
    int & r2 = r1;
    r1 = b; //易错：注意这里是赋值，不是引用b
}

//引用可以作为函数返回值返回，尤其适合在数据大的时候
int n = 5;
int & SetValue(){return n;}
int main(){
    SetValue() = 40;
}

//易错：不能引用常量和表达式。
int & b = a * 5; //出错，不能引用表达式
```

### qsort

```c++
void qsort(void *base, int nelem, unsigned int width, int (*pfCompare)(const void *, const void *));

/* 使用实例 */
int MyCompare(const void * elem1, const void * elem2){
    const int * a = ( const int *) elem1;
    const int * b = ( const int *) elem2;
    return *a - *b;
}
int main(){
    int a[] = {1,2,3,4,5};
    qrost(a, 5, sizeof(int), MyCompare);
}
```

qsort返回`-1`，代表第一个应该排在第二个之前，不需要移动位置；返回0，代表都可以；返回1，代表第一个应该排在第二个后面，需要移动位置。

### 成员对象

如果某个成员前面没有关键字，则缺省地默认为私有成员

private: ** 只有在成员函数内部访问

设置私有成员：目的是“隐藏”



析构函数

static在global之前析构



new出来的对象要手动delete!!!



静态成员函数不能使用this指针

静态成员变量：所有对象共享

sizeOf不会计算静态成员变量





!!!必须在定义类的文件中对静态成员变量进行一次说明或初始化，否则编译能通过，链接不能通过



封闭类：有成员对象的类

封闭类的调用顺序：成员对象先调用，而且顺序和声明有关，和初始化顺序无关