#include<iostream>
using namespace std;
int main()
{
  int n=0,m=0;
  cin>>n>>m;
  int a[n],b[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    b[i]=a[i];
  }
  for(int i=0;i<m;i++)
  {
    a[i]=b[n-m+i];
  }
  for(int i=m;i<n;i++)
  {
    a[i]=b[i-m];
  }
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<' ';
  }
  cout<<endl;
  return 0;
}
