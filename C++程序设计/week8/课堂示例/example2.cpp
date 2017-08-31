/*第二课*/
/*STL中相等概念演示*/
#include<iostream>
#include<algorithm>
using namespace std;
class A
{
  int v;
public:
  A(int n):v(n){}
  bool operator<(const A & a2)const{ //规定了小于号的规则
    cout<<v<<"<"<<a2.v<<"?"<<endl;
    return false; //意味着任意两个class A的对象都不会一个小于另一个
  }
  bool operator==(const A & a2)const{ //判断是否相等
    cout<<v<<"=="<<a2.v<<"?"<<endl; //没有被调用
    return v==a2.v;
  }
};
int main()
{
  A a[]={A(1),A(2),A(3),A(4),A(5)};
  cout<<binary_search(a,a+4,A(9));  //折半查找
  return 0;
}
/*输出：如果x<y不成立 y<x不成立那么认为 x=y

3<9?
2<9?
1<9?
9<1?
1*/
