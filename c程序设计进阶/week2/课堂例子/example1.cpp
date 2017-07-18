#include<iostream>
using namespace std;
int absolut(int n) //求一个数的绝对值，括号里为输入参数及其类型，并且指定函数返回值类型。n：形式参数，形参。定义函数时的参数。
{                  //函数体，一定在函数体重返回一个值
  if(n<0)
    return(-n);
  else
    return n;
}
int main()
{
  int m=-123,result=0;
  result=absolut(m);//m：实际参数，实参。实际调用函数传回的值
  cout<<result;
  return 0;
}

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*定义没有参数的函数*/
#include<iostream>
using namespace std;
int get_int()
{
  int n=0;
  cout<<"Please input an integer:"<<endl;
  cin>>n;
  return n;
}
int main()
{
  int result=0;
  result=get_int();
  cout<<result;
  return 0;
}

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*没有返回值*/
#include<iostream>
using namespace std;
void delay(int n)  //延时,void空返回值
{
  for(int i=0;i<n*100000;i++);
}
int main()
{
  for(int j=0;j<100;j++)
  {
    cout<<j<<endl;
    delay(1000);
  }
  return 0;
}

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*既没有返回值，又没有参数*/
#include<iostream>
using namespace std;
void show()
{
  cout<<"*************"<<endl;
}
int main()
{
  show();
  return 0;
}

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

/*compare.cpp*/
#include<iostream>
#include"max.h"      //为什么用双引号？默认的搜索路径，双引号先搜索当前函数库，尖括号搜索系统函数库
using namespace std;
int main()
{
  cout<<max(3,4);
  return 0;
}
/*max.h*/
float max(float a,float b)
{
  if(a>b)
    return a;
  else
    return b;
}
