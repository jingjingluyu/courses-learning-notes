/*指针变量做函数参数*/


#include<iostream>
using namespace std;
void Rank(int *q1,int *q2)  //q1,q2指向a,b。q1,q2的操作就是对a，b的操作
{
  int temp;
  if(*q1<*q2)
  {
    temp=*q1;
    *q1=*q2;
    *q2=temp;
  }
}
int main()
{
  int a,b,*p1,*p2;
  cin>>a>>b;     //输入3,5
  p1=&a;p2=&b;
  Rank(p1,p2);    //把指向a，b的指针传递给Rank，copy把地址传过去q1，q2
  cout<<a<<" "<<b<<endl;  //输出5,3
  return 0;
}

/*******************************************************************/
/*数组名作函数参数*/
/*可否将数组名作为实参付给指针形参*/
#include<iostream>
using namespace std;
void sum(int *p,int n)
{
  int total=0;
  for(int i=0;i<n;i++)
  {
    total+=*p++;
  }
  cout<<total<<endl;
}
int main()
{
  int a[10]={1,2,3,4,5,6,7,8,9,10}
  sum(a,10);       //可以
  return 0;
}


/*******************************************************************/
/*可否将多维数组名作为实参付给指针形参*/
/*例：
    有一个3*4的矩阵，求所有元素中的最大值*/
int maxvalue( int (*p)[4] )
{
  int max=p[0][0];
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<4;j++)
    {
      if(p[i][j]>max)
        max=p[i][j];
      return max;
    }
  }
}
int main() 
{
  int a[3][4]={{1,3,5,7},{9,11,13,15},{2,4,6,8}};
  cout<<"The Max value is"<<maxvalue(a);//指向二维数组第一个小数组的指针
  return 0;
}

/*******************************************************************/
/*"数组名做形参可以吗"*/

 #include<iostream>
 using namespace std;
 int sum(int arry[],int n)
 {
   for(int i=0;i<10-1;i++)
   {
     *(arry+1)=*arry+*(arry+1); //求和把和存放在最后一个元素，并且修改了元素的值
     arry++;
   }
   return *arry;
 }
int main()
{
  int a[10]={1,2,3,4,5,6,7,8,9,10}
  cout<<sun(a,10);
  return 0;
}
