/*全局变量*/
#include<iostream>
using namespace std;
int excel_number=0;             //全局变量
void excel_number(float score)  //score局部变量在excel_number中
{
  if(score>85)
  {
    excel_number++；
  }
}
int main()
{
  float score=0;
  for(int i=0;i<100;i++)
  {
    cin>>score;
    excel_number(score);
  }
}
int main()
{
  float score=0;                 //局部变量，在main中
  for(int i=0;i<100;i++)         //局部变量i
  {
    cin>>score;
    excel_number(score);
  }
  cout<<excel_number<<endl;
  return 0;
}

/**************************************************************************/

/*当全局变量与局部变量同名*/
#include<iostream>
using namespace std;
int a=0,b=0;                        //全局变量a,b
void exchange(int a,int b)          //局部变量a,b
{
  int p;
  if(a<b)
  {
    p=a;a=b;b=p;
  }
}
int main()
{
  cin>>a>>b;
  exchange(a,b);
  cout<<a<<" "<<b<<endl;
  return 0;
}

/**************************************************************************/

/*数组名做参数*/
#include<iostream>
using namespace std;
void change(int a[])
{
  a[0]=30;a[1]=50;
}
int main()
{
  int a[2]={3,5};
  change(a);
  cout<<a[0]<<" "<<a[1]<<endl;   //输出30，50
  return 0;
}
