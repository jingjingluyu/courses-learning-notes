#include<iostream>
using namespace std;
int main()
{
  int num=0,tempend=0,tempid=0,an=1,b=0,bid=0,result1=0,result2=0;
  int id[100],a[100];
  double start[100],end[100],finall[100];
  cin>>num;
  for(int i=0;i<num;i++) {
    cin>>id[i]>>start[i]>>end[i];
  }

  for(int i=0;i<num-1;i++)            //把繁殖数据从大到小排列
  {
    for(int j=i+1;j<num;j++)
    {
      if(end[i]<end[j])
      {
        tempend=end[i];
        end[i]=end[j];
        end[j]=tempend;
        tempid=id[i];            //把对应的ID也从大到小排列
        id[i]=id[j];
        id[j]=tempid;
      }
    }
  }
  for(int i=0;i<num;i++)
  {
    finall[i]=end[i]/start[i];
  }
  a[0]=id[0];
  cout<<"a[0]="<<a[0]<<endl;     //从大到小排列的最大值肯定为A最小值肯定为B,A的id从大到小.
  for(int i=1;i<num-1;i++)
  {

    result1=finall[i-1]-finall[i];
    result2=finall[i]-finall[num-1];
    if(result1<result2)
    {
      a[i]=id[i];
      an=an+1;
    }
   else
    {
      bid=i;
      break;
    }
  }
  cout<<an<<endl;
  int k=0;
  k=an-1;
  for(int i=k;i>=0;i--)
  {
    cout<<a[i]<<endl;
  }
  b=num-bid;
  cout<<b<<endl;
  for(int i=(num-1);i>=bid;i--)
    cout<<id[i]<<endl;
  return 0;
}
