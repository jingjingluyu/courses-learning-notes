
/*位运算*/
#include<stdio.h>
int main()
{
  int n1=15;
  short n2=-15;
  unsigned short n3=0xffe0;
  char c=15;
  n1=n1>>2;  //32位 0xf  变成 0x3
  n2>>=3;  //16位 fff1 变成 fffe
  n3>>=4;  //16位 变成 ffe
  c>>=3; //0000 1111  变成1
  printf("n1=%d,n2=%x,n3=%x,c=%x",n1,n2,n3,c);
}
/*****************************************************************/
/*引用*/
/*c语言中，如何编写交换两个整形变量值的函数*/
void swap(int a,int b)
{
  int tmp;
  tmp=a;a=b;b=tmp;
}
int n1,n2;
swap(n1,n2); //n1,n2的值不会被交换

//改：

void swap(int *a,int *b)  //指针
{
  int tmp;
  tmp=*a;*a=*b; *b=tmp;
}
int n1,n2;
swap(&n1,&n2); //n1,n2的值被交换

/*有了C++的引用：*/

void swap(int &a,int &b)
{
  int tmp;
  tmp=a;a=b;b=tmp;
}
int n1,n2;
swap(n1,n2); //n1,n2的值被交换
/*****************************************************************/
/*引用作为函数的返回值*/
int n=4;
int & SetValue()  // SetValue的返回值是一个整型的引用
{
  return n; //返回值是n
}
int main()
{
  SetValue()=40; //函数调用返回的结果进行赋值
  cout<<n;  //40
  return 0;
}
