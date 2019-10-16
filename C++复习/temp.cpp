#include <iostream>
#include <stdio.h>
//<cstdio>要加using namespace std;
using namespace std;
int main(){
    /* 定义常量 */
    const int MAX_VALUE = 23;
    const double Pi = 3.14;
    const char * SCHOOL_NAME = "Peking University";
    /* 定义常量指针 !!! */
    int n,m;
    const int * p = & n;
    * p = 5; //编译出错
    n = 4;
    p = & m; //ok, 常量指针的指向可以变化，但是不能通过常量指针修改指向的内容
    const int * p1; int * p2;
    p1 = p2; //ok
    p2 = p1; //error
    p2 = (int *) p1; //ok, 强制类型转换
    //不能把常量指针赋值给非常量指针，反之可以
    /* 函数参数为常量指针 */
    void MyPrintf(const char * p){
        strcpy(p, "this");//error
        printf("%s", p); //ok
    }

    /* 常值引用 */
    int n;
    const int & r = n;
    r = 5; //error
    struct A{};
    void Func(const A & r){
        r.k = 100; //error

    }
    //函数传参如果传值，拷贝实参到形参会带来开销；
    //如果传引用，又担心不小心修改实参值，就需要传常引用


    int scanf(const char *， ..)
    int printf(const char *, ..)
}

int main(){
    int a;
    char b;
    char c[20];
    double d = 0;
    float e = 0;
    long long n = 22222222222222LL;
    //注意%c也会读空格
    int n = scanf("%d%c%s%lf%f%I64d", &a, &b, c, &d, &e, &n);
    sscanf(const char * buffer, const char * format, ...)
    sprintf()；
    char * p = gets(s); //读取一行到s中，如果成功返回s的地址，失败返回NULL

    char *s; scanf("%s", s); //不安全，s不知道指向何处
}

/*动态内存分配 */
int main(){
    int * pn;
    int i = 5;
    pn = new int[i * 20];
    pn[0] = 20;
    pn[100] = 30; //编译ok，运行越界

    int *p = new int;
    *p = 5;
    delete p; //new出来需要delet掉
     
    int * p = new int[20];
    p[0] =1;
    delete[] p; //数组delete

}

// 负整数表示
//绝对值取反 + 1，补上最高位符号位

// 函数指针
//每个函数都会占用一段连续的内存空间，函数名就是函数所占内存的起始地址
//将函数入口地址赋一个指针，通过该指针就可以调用这个函数
int *(pf)(int, char);
void printmin(int a, int b){
    ...
}

int main(){
    void (*pm)(int, int);
    pm = printmin; //用函数名字给函数指针赋值
    pm(x,y);
}
void qsort(void *base, int nelem, unsigned int width, int (*pfCompare)(const void *, const void *));

#include <stdio.h>
#include <stdlib.h>
int MyCompare(const void * elem1, const void * elem2){
    unsigned int * p1, *p2;
    p1 = (unsigned int *)elem1;
    p2 = (unsigned int *)elem2;
    return *p1 - *p2;
}

#defiine N 5
int main(){
    unsigned int a[N] = {1, 2, 3, 5, 4};
    qsort(a, N, sizeof(unsigned int), MyCompare);//用函数名字给函数指针赋值
}


int main(int argc, char * argv[])
// argc 程序启动时，命令行参数的个数
// argv 指针数组，每个元素都是char*指针
// 函数名本身也是argv[0]

// 内联 & 重载 & 缺省参数
// 内联函数：函数调用需要时间。如果反复执行很多次，而且执行块，那么调用函数的开销就显得非常大

inline int MAX(){}

//函数重载：名字相同，但参数个数或类型不同；命名变得简单。编译器决定应该调用哪个函数
int MAX(double f1, double f2){}
int MAX(int n1, int n2){}
int MAX(int n1, int n2, int n3){}
// 缺省参数：最右边连续若干个参数有缺省值;优势在于提高程序可扩充性
// 如果某个写好的函数要添加新的参数，原来那些调用函数的语句，未必需要用新的参数，那么可以避免对原来那些函数调用语句的修改
void func(int x1, int x2= 2, int x3 = 3){}

// 位运算
& | ^ ~ << >>

&= //用于某些位清零，其他位不变
|= //用于某些位置1，其他位不变
^= //某些位取反，其他位不变 
n &= 0xff00;
n |= 0xff;
n ^= 0xff;

// 异或运算特点
a ^b = c;
那么 a ^ c= b;
b ^ c = a;

交换两个变量的值
int a = 5, b = 7;
a = a ^ b;
b = b ^ a;
a = a ^ b;

a << b //!!! 注意：a的值不变
//左移比乘法快的多
a <<= b;

//右移的时候永远是下取整， 因此正数绝对值变小；负数绝对值变大

-15 = 0x fff1

(a >> n) & 1
(a & (1 << n)) >> n //n < 31 ，注意如果n是31，那么结果就不对了！！因为右移补1了

// 引用

int main(){
    int a = 1, b = 2;
    int & r1 = a;
    int & r2 = r1;
    r1 = b; //!!! 注意这里是赋值，不是引用b
}

//引用用在函数传参，传递的是地址二不是值。
void swap(int * a, int * b){
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
}
int n1, n2;
swap(&a, &b);


//有了C++的引用之后可以这样写
void swap(int & a, int & b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
swap(a, b);

//如果数据很大，需要避免拷贝

// 引用可以作为函数返回值
int n = 5;
int & SetValue(){return n;}
int main(){
    SetValue() = 40;
}


//常引用，不能通过常引用修改引用的内容
const int & r = n;
//引用指向定义后，就不能再引用别的了








