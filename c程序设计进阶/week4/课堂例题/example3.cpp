/*用指针访问数组*/
#include<iostream>
using namespace std;
int main()
{
  int a[5]={1,2,3,4,5};
  int *p=&a[3];
  *p=100;
  cout<<*p++<<endl;  //100
  cout<<*p--<<endl;  //5
  cout<<*--p<<endl;  //3
  return 0
}

/*************************************************************/
/*倒置数组元素*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  int a[10],*p=NULL,*q=NULL;
  for(p=a;p<a+10;p++)
    cin>>*p;
  for(p=a,q=a+9;p<q;p++,q--)
  {
    temp=*p;
    *p=*q;
    *q=temp;
  }
  for(p=a;p<a+10;p++)
    cout<<stew(3)<<*p;     //0987654321
  return 0;
}
