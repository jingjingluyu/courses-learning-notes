#include<iostream>
using namespace std;
int main()
{
  int l=0,m=0,trees=0;
  cin>>l>>m;
  int start,end;
  int num[10001];
  for(int i=0;i<=l;i++)
  {
    num[i]=1;
  }
  for(int i=0;i<m;i++)
  {
    cin>>start>>end;
    for(int j=start;j<=end;j++)
    {
      num[j]=0;
    }
  }
  for(int i=0;i<=l;i++)
  {
    if(num[i]==1)
    trees=trees+1;
  }
  cout<<trees<<endl;
  return 0;
}
