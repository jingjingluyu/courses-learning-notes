/*如何“限制”指针的功能*/
/*指向符号常量的指针 */

#include<iostream>
using namespace std;
int sum(const int arry[],int n)  //const 定义符号常量的指针
{
  for(int i=0;i<10-1;i++)
  {
    *(arry+1)=*arry+*(arry+1); //错误，不可以赋值
    arry++;
  }
  return *arry;
}
int main()
{
 int a[10]={1,2,3,4,5,6,7,8,9,10}
 cout<<sun(a,10);
 return 0;
}
/*****************************************************************/
/*用途*/
void mystrcpy(char *dest,const char *src)
{....}
int main()
{
  char a[20]="How are you !"
  char b[20];
  mystrcpy(b,a);
  cout<<b<<endl;
  return 0;
}
/*****************************************************************/
#include<iostream>
using namespace std;
int main()
{
  const int a=78;const int b=28;int c=18;
  const int *pi=&a;
  *pi=58;      //error,*p不能被赋值
  pi=&b;       //可以给pi重新赋值
  *pi=68;       //error,*p不能被赋值
  pi=&c;
  *pi=88;         //error,*p不能被赋值
  return 0;
}
