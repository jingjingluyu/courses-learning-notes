/*切饼问题：
q(0)=1
q(1)=1+1=2
q(2)=1+1+2=4
q(3)=1+1+2+3=7
q(4)=1+1+2+3+4=11
....
q(n)=q(n-1)+n
循环的思想for */

/*
q(n)=q(n-1)+n
q(n-1)=q(n-2)+n-1
.....
递推思想
但必须要知道边界条件：q(0)=1
*/

#include<iostream>
using namespace std;
int q(int n)
{
  if(n==0)
    return 1;
  else
    return(n+q(n-1));
}
int main()
{
  cout<<q(4)<<endl;
  return 0;
}

/****************************************************/

/*菲波那切数列
1，1，2，3，5，8，13，21，34，55，89，144...
fab(n)=f(n-1)+f(n-2);  通项公式
fab(1)=1,fab(2)=1;
*/

int f(int n)
{
  if(n==1)
    return 1;
  if(n==2)
    return 1;
  else
    return(f(n-1)+f(n-2))
}
