/*第三课*/
/*类模板的定义*/
template<class T1,class T2>
class Pair{
public:
  T1 key;  //关键字
  T2 value; //值
  Pair(T1 k,T2 v):key(k),value(v){}; //构造函数
  bool operator<(const Pair<T1,T2>&p)const; //运算符重载<
};
template<class T1,class T2>
bool Pair<T1,T2>::operator<(const Pair<T1,T2> & p)const
//Pair的成员函数 operator<
{return key<p.key;} //更小的值
int main()
{
  Pair<string,int>student("Tom",19); //T1,T2
  //实例化出一个类Pair<string,int>
  cout<<student.key<<" "<<student.value;
  return 0;
}
//Tom 19
/********************************************************/
/*函数模板作为类模板成员*/
#include<iostream>
using namespace std;
template<class T> //类模板的类型参数和函数模板的类型参数不能一致
class A{ // 类模板
public:
  template<class T2>
  void Func(T2 t){cout<<t;} //成员函数模板
};
int main(){
  A<int> a;
  a.Func('K'); //成员函数模板Fune被实例化
  return 0;
}
