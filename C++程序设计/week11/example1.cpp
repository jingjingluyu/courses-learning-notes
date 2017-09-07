 /*第一课*/
/*统一的初始化方法*/
int arr[3]{1,2,3}; //初始化
vector<int> iv{1,2,3};
map<int,string> mp{{1,"a"},{2,"b"}};
string str{"Hello World"};
int *p=new int[20]{1,2,3}; //后为0
struct A{
  int i,j;
  A(int m,int n):i(m),j(n){ }
};
A func(int m,int n){return {m,n};}
int main()
{
  A*pa=new A{3,7};
}
/********************************************************/
/*成员变量默认初始值*/
class B
{
public:
  int m=1234; //直接赋初始值
  int n;
};
int main()
{
  B b;
  cout<<b.m<<endl; //输出1234
  return 0;
}
/********************************************************/
/*auto关键字*/
//1
auto i=100; //i是int
auto p=new A(); //p是A*
auto k=34343LL; //k是long long
map<string,int,greater<string> >mp;
for(auto i=mp.begin();i!=mp.end();++i)
  cout<<i->first<<","<<i->second;
  //i的类型是：map<string,int,greater<string> >::iterator 用auto替换类型

//2
class A{};
A operator +(int n,const A&a)
{
  return a;
}
template<class T1,class T2>
auto add(T1 x,T2 y)->decltype(x+y) //add的返回值是decltype(x+y) 类型
{
  return x+y;
}
auto d=add(100,1.5); //d是double d=101.5
auto k=ass(100,A());//k是A类型
/********************************************************/
/*求表达式的类型*/
int i;
double t;
struct A*a=new A();
decltype(a) x1; //x1 is A*
decltype(i) x2; //x2 is int
decltype(a->x) x3; //x3 is double
decltype((a->x)) x4=t; //x4 is double&
/********************************************************/
