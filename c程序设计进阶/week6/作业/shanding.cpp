#include<iostream>
using namespace std;
int main()
{
  int m,n;
  cin>>m>>n;
  int a[20][20]; //具体数不能是字母，m，n也不行
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  }
  for(int i=0;i<m;i++)
  {
    if(i==0)
    {
      for(int j=0;j<n;j++)
      {
        if(j==0)
        {
          if( a[i][j]>= a[i][j+1] &&  a[i][j] >= a[i+1][j] )
            cout<<i<<' '<<j<<endl;
        }
         else if(0<j<n-1)
        {
          if( a[i][j]>= a[i][j-1]  &&  a[i][j]>= a[i+1][j]  && a[i][j]>= a[i][j+1])
            cout<<i<<' '<<j<<endl;
        }
        else if(j==n-1)
        {
          if( a[i][j]>= a[i][j-1]  && a[i][j]>= a[i+1][j] )
            cout<<i<<' '<<j<<endl;
        }
      }
    }
    else if(0<i<m-1)
    {
      for(int j=0;j<n;j++)
      {
        if(j==0)
        {
          if( a[i][j]>= a[i][j+1] && a[i][j] >= a[i-1][j] && a[i][j] >= a[i+1][j])
            cout<<i<<' '<<j<<endl;
        }
        else if(0<j<n-1)
        {
          if( a[i][j]>= a[i][j-1] && a[i][j] >= a[i+1][j] && a[i][j]>= a[i][j+1] && a[i][j] >= a[i-1][j])
            cout<<i<<' '<<j<<endl;
        }
        else if(j==n-1)
        {
          if( a[i][j]>=a[i][j-1] && a[i][j]>= a[i+1][j] && a[i][j] >= a[i-1][j] )
            {
              cout<<i<<' '<<j<<endl;
            }
        }
      }
    }
    else if(i==m-1)
    {
      for(int j=0;j<n;j++)
      {
        if(j==0)
        {
          if( a[i][j]>= a[i][j+1] && a[i][j] >= a[i-1][j] )
            cout<<i<<' '<<j<<endl;
        }
        else if(0<j<n-1)
        {
          if( a[i][j] >= a[i-1][j] && a[i][j]>= a[i][j-1] && a[i][j]>= a[i][j+1])
            cout<<i<<' '<<j<<endl;
        }
        else if(j==n-1)
        {
          if(a[i][j] >= a[i-1][j] && a[i][j] >= a[i-1][j] )
              cout<<i<<' '<<j<<endl;
        }
      }
    }
  }
  return 0;
}
