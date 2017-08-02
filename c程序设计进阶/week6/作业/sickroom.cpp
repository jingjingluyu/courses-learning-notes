
#include<iostream>
#include<iomanip>
using namespace std;
int  seclect(float *q,int *p,float level,int num)
{
  int indextemp=0,result=0;
  float tempnum;
  for(int i=0;i<num-1;i++)
  {
    for(int j=i+1;j<num;j++)
    {
      if(*(q+j)>*(q+i))
      {
        tempnum=*(q+i);       //下标跟着内容调整
        *(q+i)=*(q+j);
        *(q+j)=tempnum;
        indextemp=*(p+i);
        *(p+i)=*(p+j);
        *(p+j)=indextemp;
      }
    }
  }
  for(int i=0;i<num;i++)
  {
    if(*(q+i)>level)
    {
      cout<<setfill('0')<<setw(3)<<*(p+i)<<" "<<fixed<<setprecision(1)<<*(q+i)<<endl;
      result++;
    }
  }
  if(result==0)
    cout<<"None."<<endl;
 return 0;
}
int main()
{
  int num,a[50],x;
  float b[50],y;
  float level;
  cin>>num>>level;
  for(int i=0;i<num;i++)
  {
      cin>>x>>y;  //记住输入两组数据不能直接cin>>a[i]>>b[i];
      a[i]=x;
      b[i]=y;
  }
  seclect(b,a,level,num);
  return 0;
}
