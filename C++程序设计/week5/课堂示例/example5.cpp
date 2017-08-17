/*直接基类和间接基类*/
#include<iostream>
using namespace std;
class Base{
public:
  int n;
  Base(int i):n(i){
    cout<<"Base"<<n<<"constructed"<<endl;
  }
  ~Base(){
    cout<<"Base"<<n<<"destructed"<<endl;
  }
};
class Derived:public Base
{
public:
  Derived(int i):Base(i){
    cout<<"Derived constructed"<<endl;
  }
  ~Derived(){
    cout<<"Derived destructed"<<endl;
  }
};
class MoreDerived:public Derived{
public:
  MoreDerived():Derived(4){
    cout<<"More Derived constructed"<<endl;
  }
  ~MoreDerived(){
    cout<<"More Derived destructed"<<endl;
  }
};
int mian()
{
  MoreDerived Obj;
  return 0;
}
/*输出结果：
   Base 4 constructed
   Derived constructed
   More Derived constructed
   More Derived destructed
   Derived destructed
   Base 4 destructed*/
