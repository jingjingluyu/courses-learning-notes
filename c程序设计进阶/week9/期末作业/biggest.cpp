#include<iostream>
using namespace std;
struct point     //结构体，记录每个点的横纵坐标
{
  int x;
  int y;
};
int main()
{
  int n,k=0;
  cin>>n;
  point p[100];  //存放所有点
  point max[100];  //存放极大点
  for(int i=0;i<n;i++)   //输入每个点的坐标
    cin>>p[i].x>>p[i].y;
  for(int i=0;i<n;i++)
  {
    int judge=0;
    for(int j=0;j<n;j++)
    {
      if(i==j) continue;
      else
      {
        if(p[i].x<=p[j].x &&p[i].y<=p[j].y)
          judge++;
      }
    }
    if(judge==0)
    {
      max[k].x=p[i].x;      //找极大点放在max中
      max[k].y=p[i].y;
      k++;
    }
  }
  point temp;
  for(int i=0;i<k-1;i++)   //从小到大输出
  {
     for(int j=i+1;j<k;j++)
     {
       if(max[i].x>max[j].x)
       {
         temp=max[i];
         max[i]=max[j];
         max[j]=temp;
       }
     }
   }
   for(int i=0;i<k;i++)
   {
     cout<<'('<<max[i].x<<','<<max[i].y<<')';
     if(i==k-1)
      cout<<endl;
     else
      cout<<',';
    }
    return 0;
  }
