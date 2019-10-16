运算符重载的实质是函数重载：重载为成员函数或普通函数  

class Complex{
public:
double real, image;
Complex(double r = 0.0, double i = 0.0): real(r), image(i){}
Complex operator -(const Complex & c);
};
Complex operator + (const Complex & a, const Complex & b){
    return Complex(a.real + b.real, a.image + b.image);
}
Complex Complex::operator - (const Complex & c){
    return Complex(real - c.real, image - c.image);
}

!!! 赋值运算符 = 只能重载为成员函数
class String{
    private:
    char * str;
    public:
    String & operator = (const char * str);//参数不一定是String类型
}
String & String::operator = (const char * str){
    if(str){
        delete [] str;
    }
    if(s){
        str = new char [strlen(s) +1];
        strcpy(str, s);
    }else{
        str = NULL;
    }
    return * this;//注意是return *this
}
//重载之后才有 obj = "hello"

如果不自己定义赋值运算符，那么S1 = S2 会导致S1.str和S2.str执行一个地方
String & operator = (const String & s){
    if(str == s.str){
        return *this;
    }
    if(str){
        delete[]str;
    }
    if(s.str){
        str = new char [strlen(s.str) + 1];
        strcpy(str, s.str);
        return * this;
    }
}
注意赋值运算符的返回值是 String &，这样可以保留运算符原本的特性

因此需要重写3个函数：
String & operator = (const char * s); //从char*赋值
String & operator = (const String & s); //赋值函数
String(String & s); //复制构造函数
String(String &s){
    if(s.str){
        str = new chr 
    }
}