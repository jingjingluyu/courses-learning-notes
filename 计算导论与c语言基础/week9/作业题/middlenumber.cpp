#include<iostream>
using namespace std;
int main()
{
  int n=0,num=0,temp=0,mid=0;
  cin>>n;
  int a[n];
  if(n!=0)
  {
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
      for(int j=1+i;j<n;j++)
      {
        if(a[i]>a[j])
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
    }
    /*for(int i=0;i<n;i++)
    {
      cout<<a[i]<<endl;
    }*/
    if(n==1)
    cout<<a[0]<<endl;
    else
    {
      if(n%2!=0)
      {
        n=(n-1)/2;
        mid=a[n];
      }
      if(n%2==0)
      {
        mid=(a[n/2]+a[n/2-1])/2;
      }
      cout<<mid<<endl;
    }
    return 0;
   }
}
