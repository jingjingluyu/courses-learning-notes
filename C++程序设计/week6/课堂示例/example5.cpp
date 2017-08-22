/*构造函数和析构函数调用虚函数*/
#include<iostream>
using namespace std;
class myclass{
public:
  virtual void hello(){cout<<"hello from myclass"<<endl;}
  virtual void bye(){cout<<"bye from myclass"<<endl;}
};
class son:public myclass{
public:
  void hello(){cout<<"hello from son"<<endl;}   //派生类中和基类中虚函数同名同参数表的函数，不加virtual也自动成为虚函数
  son(){hello();} //不是多态
  ~son(){bye();} //自己没有就继承myclass中的bye
};
class grandson:public son{
public:
  void hello(){cout<<"hello from grandson"<<endl;}
  void bye(){cout<<"bye from grandson"<<endl;}
  grandson(){cout<<"constructing grandson"<<endl;}
  ~grandson(){cout<<"destructing grandson"<<endl;}
};
int main(){
  grandson gson;//先执行构造函数，自顶向下
  son *pson;
  pson=&gson;
  pson->hello(); //多态
  return 0;
}
/*结果 hello from son
constructing grandson
hello from grandson
destructing grandson
bye from myclass
当一个派生类的对象初始化时，先执行基类对象的构造函数，在执行基类对象的构造函数期间没派生类的对象还没有初始化，
如果在基类的构造函数中调用了虚函数，又允许虚函数是多态，那么在基类的就会调用派生类的虚函数，会用带派生类的对象，
但还没有初始化好，所以会出错。
