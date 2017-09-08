/*第四课*/
/*用try、catch处理异常*/
#include<iostream>
using namespace std;
int main()
{
  double m,n;
  cin>>m>>n;
  try{
    cout<<"before dividing."<<endl;
    if(n==0)
      throw -1; //抛出int类型异常，出现异常就停止运行，往catch中走，如果没有抛出异常，所有的catch就不会被执行
    else
      cout<<m/n<<endl;
    cout<<"after dividing."<<endl;
  }
  catch(double d)
  {
  cout<<"catch(double)"<<d<<endl;
  }
  catch(int e)
  {
   cout<<"catch(int)"<<e<<endl;
  }
  cout<<"finished"<<endl;
  return 0;
}
/*******************************************************************/
/*捕获任何异常的catch块*/
#include<iostream>
using namespace std;
int main()
{
  double m,n;
  cin>>m>>n;
  try{
    cout<<"before dividing."<<endl;
    if(n==0)
      throw -1; //抛出整形异常
    else if(m==0)
      throw -1.0; //抛出double型异常
    else
      cout<<m/n<<endl;
    cout<<"after dividing."<<endl;
  }
  catch(double d)
  {
    cout<<"catch(double)"<<d<<endl;
  }
  catch(...) //捕获任何类型的异常，从上到下依次 匹配
  {
    cout<<"catch(...)"<<endl;
  }
  cout<<"finished"<<endl;
  return 0;
}
/*输出
9 0
before dividing.
catch(...)
finished*/
/*******************************************************************/
/*异常再抛出*/
#include<iostream>
#include<string>
using namespace std;
class CException
{
public:
  string msg;
  CException(string s):msg(s){ }
};
double Derived(double x,double y)
{
  if(y==0)
    throw CException("devied by zero"); //对于异常没有catch
  cout<<"in Devide"<<endl;
  return x/y;
}
int CountTax(int salary)
{
  try{
    if(salary<0)
      throw -1;
    cout<<"counting tax"<<endl;
  }
  catch(int)
  {
    cout<<"salary<0"<<endl;
  }
  cout<<"tax counted"<<endl;
  return salary*0.15;
}
int main()
{
  double f=1.2;
  try{
    CountTax(-1);
    f=Devide(3,0); //
    cout<<"end of try block"<<endl;
  }
  catch(CException e) //e是复制品derived by zero
  {
    cout<<e.msg<<endl;
  }
  cout<<"f="<<f<<endl;
  cout<<"finished"<<endl;
  return 0;
}
/*输出：
salary <0
tax counted
devided by zero
f=1.2
finished*/
