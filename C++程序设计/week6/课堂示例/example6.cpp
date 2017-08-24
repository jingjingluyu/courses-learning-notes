/*第三课*/
/*多态实现原理*/
#include<iostream>
using namespace std;
class Base{
public:
  int i;
  virtual void Print(){cout<<"Base:Print";}
};
class Derived:public Base{
public:
  int n;
  virtual void Print(){cout<<"Drived:Print"<<endl;}
};
int main(){
  Derived d;
  cout<<sizeof(Base)<<","<<sizeof(Derived); //8 12 多出4个字节
  return 0;
}
/********************************************************************/
/*虚析构函数*/
class CSon{
public:
  ~CSon(){ };
};
class CGrandson:CSon{
public:~CGrandson(){ };
};
int main(){
  CSon *p=new CGrandson;
  delete p; //导致程序出错 没有删除CGrandson
  return 0;
}
/********************************************************************/
/*虚析构函数*/
class son{
public:
  virtual ~son(){cout<<"bye from son"<<endl;}
};
class grandson:public son{
public:
  ~grandson(){cout<<"bye from grandson"<<endl;}
};
int main(){
  son *pson;
  pson=new grandson;
  delete pson;
  return 0;
}
//输出结果：bye from grandson  bye from son
//执行grandson::~grandson(),引起执行 son::~son()!!!
