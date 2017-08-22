/*第二课 多态的又一例子*/
#include<iostream>
using namespace std;
class Base{
public:
  void fun1(){fun2();} //等价于 this->fun2() this是基类指针 要看this指向的对象 fun2()是虚函数 多态
  virtual void fun2(){cout<<"Base::fun2()"<<endl;}
};
class Derived:public Base{
public:
  virtual void fun2(){cout<<"Derived:fun2()"<<endl;}
};
int main(){
  Derived d;
  Base*pBase=&d; //pBase指向派生类的 所以this指向派生类的对象
  pBase->fun1(); //pBase
  return 0;
}
//结果输出 Derived:fun2()
//在非构造函数，非析构函数的成员函数中调用虚函数，是多态
