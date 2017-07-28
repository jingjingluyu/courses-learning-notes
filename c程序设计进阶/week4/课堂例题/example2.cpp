/*指向数组元素的指针*/

#include<iostream>
using namespace std;
int main()
{
  int a[5]={1,2,3,4,5};
  int *p=&a[3];
  cout<<*p<<endl;    //4
  *p=100;
  cout<<a[3]<<endl;   //100
  return 0;
}

/******************************************************/
#include<iostream>
using namespace std;
int main()
{
  int a[5]={10,11,12,13,14};
  cout<<a<<endl;             //0017F754
  cout<< *a<<endl;           //10
  cout<< &a[0]<<endl;        //0017F754
  cout<< a[0]<<endl;         //10
  return 0;
}
/******************************************************/
/*指针与数组*/
#include<iostream>
using namespace std;
int main()
{
  int a[5]={10,11,12,13,14}
  int *p=NULL;
  cout<<a<<endl;       //00C5FCB4  a[0]的地址
  p=a;
  cout<<p<<endl;       //00C5FCB4 a[0]的地址
  cout<<*p<<endl;      //10 a[0]
  cout<<*p++<<endl;    //10不是*(p++)而是先*p后++，后置++的含义别忘了 所以还是a[0],p再++
  cout<<*p++<<endl;    //11 a[1] p再++ 指向a[2]
  return 0;
}
/********************************************************/
/*使用指针代替数组下标*/
int main()
{
  int a[10],i;
  for(i=0;i<10;i++)
    cin>>a[i];
  for(i=9;i>=0;i--)
    cout<<setw(3)<<a[i];
  return 0;
}

int main()
{
  int a[10],i,*p=a;
  for(i=0;i<10;i++)
    cin>>*p++;
  for(p--;p>a;)
    cout<<setw(3)<<*p--;
  return 0;
}
