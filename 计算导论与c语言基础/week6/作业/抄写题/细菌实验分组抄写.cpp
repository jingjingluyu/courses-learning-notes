#include <iostream>
using namespace std;
int main()
{
  int n;
  int id[100];//细菌编号
  double rate[100];//rate记录细菌的繁殖率
  cin >> n;
  for(int i=0;i<n;i++)
  {
     int initial,final;
     cin >> id[i] >> initial >> final;
     rate[i] = (double)final / initial;
   }
   //对整个细菌排序
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n-i-1;j++)
      {
        if(rate[j+1]>rate[j])
        {
           int tmpId=id[j];
           id[j]=id[j+1];
           id[j+1]=tmpId;
           double tmpRate =rate[j];
           rate[j]=rate[j+1];
           rate[j+1]=tmpRate;
         }
       }
    }
 double maxDiff=0;//记录最大的差
 int maxDiffIndex =0;//和最大的下标
 for(int i=0;i<n-1;i++)
 {
    double diff=rate[i]-rate[i+1];//找到AB分界点
    if(maxDiff<diff)
    {
       maxDiff=diff;
       maxDiffIndex=i;
     }
  }
//输出繁殖率较大的那组细菌
cout<<maxDiffIndex+1<<endl;//下标加一为编号
for(int i=maxDiffIndex;i>=0;i--)
  {
    cout<<id[i]<<endl;
   }//倒序输出
//输出繁殖率较小的那组细菌
cout<<n-maxDiffIndex-1<<endl;
for(int i=n-1;i>=maxDiffIndex+1;i--)
 {
   cout<<id[i]<<endl;
  }
return 0;
}












 



