/*第二课*/
/*Lambda表达式*/
//1)
int main()
{
  int x=100,y=200,z=300;
  cout<<[](double a,double b){return a+b;}(1.2,2.5)<<endl;
  auto ff=[=,&y,&z](int n)
  {
    cout<<x<<endl;
    y++;z++;
    return n*n;
  };
  cout<<ff(15)<<endl;
  cout<<y<<","<<z<<endl;
}
/*输出
3.7 100 225 201 301*/
/*********************************************************************************/

//2)
int a[4]={4,2,11,33};
sort(a,a+4,[](int x)->bool{return x%10<y%10;});//Lambda表达式可以将排序规则写在这
for_each(a,a+4,[](int x){cout<<x<<" ";});
/*输出结果
  11 2 33 4*/
/*********************************************************************************/

//3)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<int> a{1,2,3,4};
  int total=0;
  for_each(a.begin(),a.end(),[&](int & x){total+=x;x*=2;});
  cout<<total<<endl; //输出10
  for_each(a.begin(),a.end(),[](int x){cout<<x<<" ";});
  return 0;
}
/*********************************************************************************/
/*实现递归求斐波那契数列第n项：*/
function<int(int)>fid=[&fib](int n)
{return n<=2?1:fid(n-1)+fib(n-1)+fib(n-2);};}；

cout<<fib(5)<<endl; //输出5

function<int(int)> 表示返回值为int，有一个 int参数的函数
