/*把 M 个同样的苹果放在 N 个同样的盘子里，
允许有的盘子空着不放，问共有多少种不同的分法？
注意：5，1，1和1，5，1是同一种分法
输入：7 3
输出：8
问题：M个苹果 放入N个盘子，多少种方法？
假设：有一个函数f（m，n）能告诉我答案；

如果：n/盘子数 > M/苹果数
     砍掉多余的盘子 使其为下面的情况
     M/苹果数 >= n/盘子数
    1. 有盘子空着：f(m, n)=f(m,n-1) 至少有一个盘子空着
    2. 没有盘子空着：f(m, n)=f(m-n,n) 每只盘子至少有一只苹果，减掉后，又变为n>M,减掉，又变为M>n.
     之和*/


#include<iostream>
using namespace std;
int count(int m,int n)
{
  if(m<=1||n<=0) return 1;
  if(m<n)
    return count(m,m);
  else
    return count(m,n-1)+count(m-n,n);
}
void main()
{
  int apples,plates;
  cin>>apples>>plates;
  cout<<count(apples,plates);
}
