/*返回指针的函数*/
/*打印出第二行第三行的值*/
#include<iostream>
using namespace std;
int *get(int arr[][4],int n,int m)    //int arr[][4] = int (*arr)[4]
{
  int *pt;
  pt=*(arr+n-1)+m-1;
  return(pt);
}
void main()
{
  int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  int *p;
  p=get(a,2,3);      //返回数组【2】【3】的地址
  cout<<*p<<endl;
}
/*****************************************************************/
/*返回指针的函数*/
#include<iostream>
using namespace std;
int *genInt1()
{
  int value1=20;   //局部变量
  return &value1;   //返回地址
}
int main()
{
  int *p;
  p=getInt1();
  cout<<*p<<endl;  //p所指的内存空间已经释放掉了，结果无法完全预测，不稳定的值
}
/*****************************************************************/
/*判断程序的执行结果*/
#include<iostream>
using namespace std;
int *genInt1()
{
  int value1=20;   //局部变量
  return &value1;   //返回地址
}
int *getInt2()     //getInt1被释放掉，内存用这部分来来存储getInt2
{
  int value2=30;
  return &value2;
}
int main()
{
  int *p,*q;
  p=getInt1();
  q=getInt2();
  cout<<*p<<endl;  //p所指的内存空间已经释放掉了，结果无法完全预测，不稳定的值,大多数的值是30
}
/*****************************************************************/
/*确保返回地址的意义*/
/*返回全局变量的地址*/
#include<iostream.h>
int value1=20;
int value2=30;
int *getInt1()
{
  return &value1;
}
int *getInt2()
{
  return &value2;
}
int main()
{
  int *p,*q;
  p=getInt1()
  q=getInt2()
  cout<<*p<<endl;  //稳定的值
  return 0;
}
/*****************************************************************/
/*返回静态局部变量的地址，而非动态局部变量的地址*/
#include<iostream.h>
using namespace std;
int *getInt1()
{
  static int value1=20;
  return &value1;
}
int *getInt2()
{
  static int value2=30;
  return &value2;
}
int main()
{
  int *p,*q;
  p=getInt1()
  q=getInt2()
  cout<<*p<<endl;  //稳定的值
  return 0;
}
