#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  char dou;
  cin>>a>>dou>>b>>dou>>c;
  if(c==a+b)
    cout<<"+"<<endl;
  else if(c==a-b)
    cout<<"-"<<endl;
  else if(c==a*b)
    cout<<"*"<<endl;
  else if(c==a/b)
    cout<<"/"<<endl;
  else if(c==a%b)
    cout<<"%"<<endl;
  else
    cout<<"error"<<endl;
  return 0;
}
