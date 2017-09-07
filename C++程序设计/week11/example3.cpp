/*第一课*/
/*空指针nullptr*/
#include<memory>
#include<iostream>
using namespace std;
int main()
{
  int *p1=NULL;
  int *p2=nullptr;
  shared_ptr<double>p3=nullptr;
  if(p1==p2)
    cout<<"equal 1"<<endl;
  if(p3==nullptr)
    cout<<"equal 2"<<endl;
  if(p3==p2); //error 类型不同
  if(p3 == NULL)
    cout<<"equal 4"<<endl;
  bool b=nullptr; //b=false
  int i=nullptr; //error,nullptr 不能自动转换成整型
  return 0;
}
/*去掉出错的语句后输出：
  equal 1
  equal 2
  equal 4*/
/************************************************/
/*基于范围的for循环*/
#include<iostream>
#include<vector>
using namespace std;
struct A{
  int n;
  A(int i):n(i){  }
};
int main()
{
  int ary[]={1,2,3,4,5};
  for(int &e:ary) //对于ary里的每一个元素，用e代替，e是引用会改变值
    e*=10;
  for(int e:ary) //不是引用 不能改值
    cout<<e<<",";
  cout<<endl;
  vector<A> st(ary,ary+5);
  for(auto & it:st)
    it.n*=10;
  for(A it:st)
    cout<<it.n<<",";
  return 0;
}
/*输出
10,20,30,40,50,
100,200,300,400,500,*/
/************************************************/
