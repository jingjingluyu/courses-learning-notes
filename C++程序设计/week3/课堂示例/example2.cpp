/*第二课*/
/*复制构造函数*/
#include<iostream>
using namespace std;
class A
{
   public:
   A(){};
  A(A&a)
  {
     cout<<"Copy constructor called"<<endl;
   }
};
void Func(A a1){}
int main()
{
   A a2;
   Func(a2);
   return 0;
}
/****************************************************/
#include<iostream>
using namespace std;
class A
{
   public:
     int v;
     A(int n){v=n;}; //构造函数
     A(const A&a){
          v=a.v;   //复制
          cout<<"Copy constructor called"<<endl;

     }
};
A Func(){
    A b(4);
    return b;  //调用复制构造函数，b作为参数，输出Copy constructor called，
                //返回值是用复制函数初始化的,如果没有用v=a.v;就不是4了
}
int main(){
     cout<<Func().v<<endl; return 0;
}
