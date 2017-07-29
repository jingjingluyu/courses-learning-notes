/*字符串指针举例*/

/*字符串的复制*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  char a[]="How are you?",b[20];
  char *p1,*p2;
  for(p1=a,p2=b;*p1!='\0';p1++,p2++)
    *p2=*p1;
  *p2='\0';
  cout<<"string a is:"<<a<<endl;
  cout<<"string b is:"<<b<<endl;
  return 0;
}
/**********************************************/

 int main()
 {
   int a=5;
   int *pa=&a;

   int b[6]={1,2,3,4,5,6};
   int *pb=b;

   char c[6]={'h','e','l','o','\0'};
   char *pc=c;

   cout<<a<<endl;            //5
   cout<<pa<<endl<<endl;    //0x0013ff7c

   cout<<b<<endl;           //0x0013FF60
   cout<<pb<<endl<<endl;     //0x0013FF60

   cout<<c<<endl;           //hello
   cout<<pc<<endl;         //hello
   //cout<<static_cast<void*>(c)<<endl;      0x0013FF54
   //cout<<static_cast<void*>(pc)<<endl;     0x0013FF54
   return 0;
 }
 /**************************************************/

/*字符串指针举例*/
#include<iostream>
using namespace std;
int main()
{
  char buffer[10]="ABC";
  char *pc;
  pc="hello";      //这是可以的，只能访问值但不能修改。
  cout<<pc<<endl;  //hello
  pc++;
  cout<<pc<<endl;  //ello
  cout<<*pc<<endl;  //e
  pc=butter;
  cout<<pc;      //ABC
  return 0;
}
