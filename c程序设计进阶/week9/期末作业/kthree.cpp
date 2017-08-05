#include<iostream>
using namespace std;
void juge(int m,int k)
{
  int num=0,x=m;
  while(m>0)
  {
    if(m%10==3) //先判断有几个3，用求余数的方法。
    {
       num++;
       m=(m-3)/10;
    }
    else
    {
      m=(m-m%10)/10;
    }
  }
  if(num==k&&x%19==0)
      cout<<"YES"<<endl;
  else
      cout<<"NO"<<endl;
}
int main()
{
  int m,k,result=0;
  cin>>m>>k;
  juge(m,k);
  return 0;
}
