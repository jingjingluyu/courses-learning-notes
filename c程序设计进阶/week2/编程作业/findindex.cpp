#include<iostream>
using namespace std;
int same(int x[],int n)
{
  int a=0,r=0;
  for(int i=0;i<n;i++)
  {
    if(x[i]==i)
    {
      a++;
      r=x[i];
      break;
    }
  }
  if(a>0)
  return r;
  else
  return -1;
}
int main()
{
  int x[100],result=0,n=0;
  cin>>n;
  for(int i=0;i<n;i++)
  cin>>x[i];
  result=same(x,n);
  if(result==-1)
  cout<<"N"<<endl;
  else
  cout<<result<<endl;
  return 0;
}
