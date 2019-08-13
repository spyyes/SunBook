# C++新特性

auto 智能指针

std::shared_ptr 定义于头文件 <memory>

template< class T > class shared_ptr; 是进行动态内存管理的工具。
		

### 强类型枚举　－C++11

**解决的问题**

传统Ｃ++中枚举常量被暴露在外层的作用域中。若是同一个作用域下有两个不同的枚举类型，但含有相同的枚举量也是不可以的，比如：

```c++
enum Side{Right,Left};
enum Thing{Wrong,Right};
```

这样的是不能用的。

另一个缺陷是传统枚举值总是被隐式的转换为整型，用户无法自定义类型。

**强类型枚举**

使用`enum class`语法来声明。

- 枚举值不会被隐式转换为整数，也无法和整数值进行比较。会触发编译错误。

- 枚举类型使用的类型默认为int，也可以指定其他类型。

  ```c++
  enum class Enum:unsigned int{VAL1, VAL2};
  ```

- 在使用枚举类型的枚举名时，必须指明所属的范围。比如`Enum::Val1`

- 枚举类型的前置声明也可。

  ```c++
  enum class Color:char; //前置声明枚举类
  void Foo(Color * p); //前置声明的使用
  enum class COlor:char{RED, GREEN, BLACK}; //前置声明的相应定义
  ```

  

### auto关键字

使用auto关键字可以要求编译器对变量类型进行自动推导。

**优势：**（1）简化代码；（2）避免类型声明的麻烦；（3）精度自动匹配，但是仍然不能达到自动扩充位数的效果。

**注意事项：**

- 可以使用valatile，pointer（*），reference（&），rvalue reference（&&） 来修饰auto
- 用auto声明的变量必须初始化
- 函数和模板参数不能被声明为auto
- 定义在堆上的变量，使用了auto的表达式必须被初始化
- 定义在一个auto序列的变量必须始终推导成同一类型

​	`auto x1 = 5, x2 = 5.0, x3='r';  // This is too much....we cannot combine like this`

