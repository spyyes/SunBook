输入输出流和文件操作
标准流对象：cin cout
    cerr：不适用缓冲区，直接向显示器输出信息
    clog：先放在缓冲区

//输出重定向
freopen("test.txt", "w", stdout); //将标准输出定向到文件

输出流
流插入运算符
cout <<endl; //刷新缓冲区
cout << flush; //刷新缓冲区

cout.put('Q');
cout.put('A').put('a');

输入流
int x
while(cin>>x){

}

while((c = cin.get()) != EOF){
    cout.put(c);
}

cin.eof() //返回输入是否结束的标志
cin.getline()
cin.get()

cin.putback()
cin.ignore(int nCount = 1, int delim = EOF);

char buffer[80];
cin.read(buffer, 20);
cout.write(buffer, cin.gcount()); //gcount()返回上次读入的字节数

流操纵算子 
#include <iomanip>
整数流的
cout << hex << n << dec << n << oct << n;
浮点数
cout << setprecision(5) << ... //指定有效位数
cout << setiosflags(ios::fixed) << setprecision(5)<< //制定小数点位置
cout << resetiosflags(ios::fixed) //取消指定小数点位置
cout << scientific << //科学计数法输出
cout << showpos << //非负数现实正号
cout << noshowpos << ...

设置域宽
cin >> setw(5) 
cout << setw(5) << setfill('*')  << left << //不足位数用，如果不够右边填充
<< internal 
cout 
在每次读入输出之前都要设置宽度

ofstream outFile("a.txt", ios::out|ios::binary);
ios::out 输出到文件，删除原有内容
ios::app 输出到文件，保留原有内容

或者

ofstream fout;
fout.open("a.txt", ios::out|ios::binary);
if(!fout){
    cerr<<""<<endl;
}

fout.tellp();//写指针位置
fout.seekp(10L);
fout.seekp(10L, ios::beg);
ios::cur;
ios::end; //从尾部数location
可以为负
fout.write()
fout.close();

fin.tellg();
seekg();
read()
fin.close();



