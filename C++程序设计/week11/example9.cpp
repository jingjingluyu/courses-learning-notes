/*bad_cast*/
#include<iostream>
#include<stdexcept>
#include<typeinfo>
using namespace std;
class Base
{
  virtual void func(){}
};
class Derived:public Base
{
public:
  void Print(){}
};
void PrintObj(Base & b)
{
  try{
    Derived &rd=dynamic_cast<Derived&>(b);
     //b引用的是派生类就安全，引用基类对象就不安全，rd是基类对象rd.Print当做派生类来做了，print就会访问只属于派生类，不属于基类的对象
    //此转换若不安全，会抛出bad_cast异常，并且自己不处理取catch
    rd.Print();
  }
  catch(bad_cast& e)
  {
    cerr<<e.what()<<endl; //bad_cast& e中有个信息用 what()可以调出来输出：Bad dyname_cast!
  }
}
int main()
{
  Base b;
  PrintObj(b);
  return 0;
}
/*******************************************************************/
/*bad_alloc*/
#include<iostream>
#include<stdexcept>
using namespace std;
int main()
{
  try{
    char *p=new char[0x7fffffff]; //无法分配这么多空间，会抛出异常
  }
  catch(bad_alloc&e)
  {
    cerr<<e.what()<<endl; //bad allocation
  }
  return 0;
}
/*******************************************************************/
/*out_of_range*/
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
using namespace std;
int main()
{
  vector<int> v(10);
  try{
    v.at(100)=100; //抛出out_of_range异常
  }
  catch(out_of_range&e)
  {
    cerr<<e.what()<<endl;
  }
  string s="hello";
  try{
    char c=s.at(100); //抛出out_of_range异常
  }
  catch(out_of_range&e)
  {
    cerr<<e.what()<<endl;
  }
  return 0;
}
/*输出结果：
invalid vector<T>subscript
invalid string position*/
