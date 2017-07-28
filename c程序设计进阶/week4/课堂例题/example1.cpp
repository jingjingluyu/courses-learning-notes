/*指针变量示例*/


#include<iostream>
using namespace std;
int main()
{
  int iCount=18;
  int *iPtr=&iCount;
  *iPtr=58;
  cout<<iCount<<endl;
  cout<<iPtr<<endl;
  cout<<&iCount<<endl;
  cout<<*iPtr<<endl;
  cout<<&iPtr<<endl;
  return 0;
}
/*****************************************************/
#include<iostream>
using namespace std;
int main()
{
  int a=0,b=0,temp;
  int *p1=NULL,*p2=NULL; //空指针，给指针变量赋予初始值
  cin>>a>>b;        //a=3,b=7
  p1=&a;
  p2=&b;
  if(*p1<*p2)    //*p1=a,*p2=b;
  {
    temp=*p1;*p1=*p2;*p2=temp;  //a=7,b=3;
  }
  cout<<"max="<<*p1<<",min="<<*p2<<endl;
  return 0;
}
/********************************************************/
#include<iostream>
using namespace std;
int main()
{
  int a=0,b=0;
  int *p1=NULL,*p2=NULL; //空指针，给指针变量赋予初始值
  int *temp=NULL;
  cin>>a>>b;        //a=3,b=7
  p1=&a;
  p2=&b;
  if(*p1<*p2)    //*p1=a,*p2=b;
  {
    temp=p1;p1=p2;p2=temp;  //把p1和p2的内容互换，p1指向b p2指向a
  }
  cout<<"max="<<*p1<<",min="<<*p2<<endl;//7,3
  return 0;
}
/*********************************************************/

#include<iostream>
using namespace std;
int main()
{
  int n=0;
  int *p=&n;
  cout<<p<<endl;      //00C6FED8
  p++;
  cout<<p<<endl;       //00C6FEDC
  return 0;
}
