#include<iostream>
using namespace std;
int main()
{
  int a,b,result;
  char t;
  cin>>a>>b>>t;
  if((t!='+')&&(t!='-')&&(t!='*')&&(t!='/'))
  cout<<"Invalid operator"<<endl;
  if((t=='/')&&(b==0))
  cout<<"Divided by zero"<<endl;
  else
  {
    switch(t)
   {
     case'+':result=a+b;cout<<result<<endl;break;
     case'-':result=a-b;cout<<result<<endl;break;
     case'*':result=a*b;cout<<result<<endl;break;
     case'/':result=a*b;cout<<result<<endl;break;
   }
  }
  return 0;
}
