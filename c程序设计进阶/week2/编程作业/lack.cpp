#include<iostream>
using namespace std;
int check(int lacks[])
{
  int a=0,b=0,c=0,d=0;
  a=(lacks[1]==1)+(lacks[3]==4)+(lacks[0]==3);
  b=(lacks[3]==1)+(lacks[1]==4)+(lacks[0]==2)+(lacks[2]==3);
  c=(lacks[3]==4)+(lacks[1]==3);
  d=(lacks[0]==1)+(lacks[2]==4)+(lacks[3]==2)+(lacks[1]==3);
  if(a==1&&b==1&&c==1&&d==1)
    return 1;
  else
    return 0;
}
int main()
{
  int lacks[4],result=0;                   //lack[0]至lack[3]分别代表pyh，dth，th, hzh，
  for(int i=1;i<5;i++)           //遍历四大湖的各种情况
  {
    for(int j=1;j<5;j++)
    {
      for(int k=1;k<5;k++)
      {
        for(int l=1;l<5;l++)
        {
          if(i==j||i==k||i==l||j==k||j==l||k==l)
            continue;
          lacks[0]=i;
          lacks[1]=j;
          lacks[2]=k;
          lacks[3]=l;
          result=check(lacks);
          if(result==1)
          {
            for(int m=0;m<4;m++)
              cout<<lacks[m]<<endl;
          }
          else
            continue;
        }
      }
    }
  }
  return 0;
}
