/*a第一课*/
/*预备知识：pair模板*/
template<class _T1,class _T2>
struct pair //里面的所有成员都是公有的
{
  typedef _T1 first_type; //把T1定义成 first_type类型
  typedef _T2 second_type;
  _T1 first; //成员变量
  _T2 second;
  pair():first(),second(){} //如果first和second都是成员对象的话，都是无参构造函数初始化。
  pair(const _T1&_a,const _T2&_b):first(_a),second(_b){}
  template<class _U1,class _U2> //函数模板，
  pair(const pair<_U1,_U2>&_p):first(_p.first),second(_p.second){}
};
/*第三个构造函数用法示例：
pair<int,int>
p(pair<double,double>(5.5,4.6);
//p.first=5,p.second=4
*/
/*************************************************************************************/
/*multiset的用法*/
#include<set>
using namespace std;
class A{};
int main(){
  multiset<A> a; //模板类
  a.insert(A());//error
}
//multiset<A> 等价于 multiset<A,less<A>> a;插入元素时，multiset会将被插入元素的已有元素
//进行比较。由于less模板是用<进行比较的，所以，这都要求A的对象能用<比较，即适当重载了<


/*正确*/
#include<iostream>
#include<set>//使用multiset须包含此文件
using namespace std;
template<class T>
vois Print(T first,T last)
{
  fot(;first!=last;++first) cout<<*first<<" ";
  cout<<endl;
}
class A {
private:
  int n;
public:
  A(int n_){n=n_;}
  friend bool operator<(const A&a1,const A&a2){return a1.n<a2.n;}
  friend ostream & operator<<(ostream &o,const A&a2){o<<a2.n;return 0;}
  friend class MyLess;
};
struct MyLess{
  bool operator()(const A&a1,const A&a2)
  //按个位数比大小
  {return(a1.n%10)<(a2.n%10);}
};
typedef multiset<A> MSET1; //MSET1用“<”比较大小
typedef multiset<A,MyLess> MSET2; //MSET2用 MyLess::operator()比较大小
int main()
{
  const int SIZE=6;
  A a[SIZE]={4,22,19,8,33,40};
  MSET1 m1;
  m1.insert(a,a+SIZE);
  m1.insert(22);
  cout<<"1)"<<m1.count(22)<<endl; //输出1） 2
  cout<<"2)";Print(m1.begin(),m1.end()); //输出2） 4 8 19 22 22 33 40
  MSET1::iterator pp=m1.find(19);
  if(pp!=m1.end()) //条件为真说明找到
    cout<<"found"<<endl; //本行会被执行，输出found
  cout<<"3)";cout<<*m1.lower_bound(22)<<","<<*m1.upper_bound(22)<<endl; //返回迭代器指向的元素 ，左闭右开其实是不包括22
  //输出3）22，23
  pp=m1.erase(m1.lower_bound(22),m1.upper_bound(22));
  //pp指向被删除元素的下一个元素 ，左闭右开
  cout<<"4)";Print(m1.begin(),m1.endl()); //输出 4）4 8 19 33 40
  cout<<"5)";cout<<*pp<<endl; //输出5） 33
  MSET2 m2; //m2里的元素按n的个位数从小到大排
  m2.insert(a,a+SIZE);
  cout<<"6)";Print(m2.begin(),m2.end()); //输出 6） 40 22 33 4 8 19
  return 0；
}
