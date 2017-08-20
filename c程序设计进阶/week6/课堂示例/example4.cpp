/*静态局部变量vs动态局部变量*/
#include<iostream>
voide function()
{
  int a=0;     //动态局部变量
  static int b=0;   //只会执行一次，不需要每次都执行 =以前定义： auto int a=0;
  a=a+1;
  b=b+1;
  cout<<"a="<<a<<endl; //a一直为1
  cout<<"b="<<b<<endl; //b一直在加，不需要在新生成b
}
int main()
{
  for(int i=0;i<5;i++)
  {
    function();
    cout<<"Call Again!"<endl;
  }
 return 0;
}
