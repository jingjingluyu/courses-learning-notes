#include<iostream>
using namespace std;
int main()
{
  int k,num=0,m=0,n=0,result[100];
  cin>>k;
  for(int i=0;i<k;i++)
  {
    int a[100][100];
    int (*p)[100]; //不可以[m]即使m在前面输入了值
    cin>>m>>n;
    p=a;         //此处也可以换成p=&a[0];
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<n;k++)
      cin>>a[j][k];
    }
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<n;k++)
      {
        if(j==0||j==m-1)
          num=num+*(*(p+j)+k);
        else if(j!=0&&j!=m-1)
        {
          if(k==0||k==n-1)
            num=num+*(*(p+j)+k);
        }
      }
    }
   result[i]=num;
   num=0;
  }
  for(int i=0;i<k;i++)
    cout<<result[i]<<endl;
return 0;
}
