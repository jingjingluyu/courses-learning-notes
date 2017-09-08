/*第三课*/
/*static_cast示例*/
#include<iostream>
using namespace std;
class A
{
public:
  operator int() {return 1;}
  operator char*(){return NULL;}
};
int main()
{
  A a;
  int n;char *p="New Dragon Inn";
  n=static_cast<int>(3.14); //n的值变为3，强制转换成int
  n=static_cast<int>(a); //调用a.operator int,n的值变为1
  p=static_cast<char*>(a); //调用a.operator char*,p的值变为NULL
  n=static_cast<int>(p); //编译错误，static_cast不能将指针转换成整型
  p=static_cast<char*>(n); //编译错误，static_cast不能将整型转换成指针
  return 0;
}
//类型强制转换运算符被重载为函数的时候是不写返回值类型的，被重载的类型是什么，返回值就是什么
/*************************************************************************/
/*reinterpret_cast示例*/
#include<iostream>
using namespace std;
class A
{
public:
  int i;
  int j;
  A(int n):i(n),j(n){}
};
int main()
{
  A a(100);
  int &r=reinterpret_cast<int&>(a); //强行让r引用a
  r=200;//把a.i变成了200
  cout<<a.i<<","<<a.j<<endl; //输出200，100
  int n=300;
  A*pa=reinterpret_cast<A*>(&n); //强行让pa指向n
  pa->i=400; //n变成400
  pa->j=500; //此条语句不安全，很可能导致程序崩溃
  cout<<n<<endl; //输出400
  long long la=0x12345678abcdLL;
  pa=reinterpret_cast<A*>(la); //la太长，只取低32位0x5678abcd拷贝给pa
  unsigned int u=reinterpret_cast<unsigned int>(pa); //pa逐个比特拷贝到u
  cout<<hex<<u<<endl; //输出5678abcd
  typedef void(*PF1)(int); //参数是int返回值是void
  typedef int(*PF2)(int,char*);
  PF1 pf1; PF2 pf2;
  pf2=reinterpret_cast<PF2>(pf1); //两个不同类型的函数指针之间可以互相转换
}
/*************************************************************************/
/*dynamic_cast示例*/
#include<iostream>
#include<string>
using namespace std;
class Base
{ //有虚函数，因此是多态基类
public:
  virtual ~Base(){}
};
class Derived:public Base { };
int main()
{
  Base b;
  Derived d;
  Derived * pd;
  pd=reinterpret_cast<Derived*>(&b);
  if(pd==NULL) //此处pd不会为NULL。
  //reinterpret_cast不检查安全性，总是进行转换
    cout<<"unsafe reinterpret_cast"<<endl; //不会执行
  pd=dynamic_cast<Derived*>(&b);
  if(pd==NULL)
  //结果会是NULL，因为&b不是指向派生类对象，此转换不安全
    cout<<"unsafe dynamic_cast1"<<endl; //会执行
  Base *pd=&d;
  pd=dynamic_cast<Derived*>(pb); //安全的转换
  if(pd==NULL) //此处pd不会为NULL
    cout<<"unsafe dynamic_cast2"<<endl; //不会执行
  return 0;
}
