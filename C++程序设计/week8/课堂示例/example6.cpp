/*第四课*/
/*greater的应用*/
#include<list>
#include<iostream>
using namespace std;
class MyLess{
public:
  bool operator()(const int & c1,const int & c2)
  {
    return(c1%10)<(c2%10);
  }
};
template<class T>
void Print(T first,T last){
  for(;first!=last;++first)cout<<*first<<",";  //输出first到last区间的所有元素
}
/*template<class T>
struct great:public binary function<T,T,bool>
{
  bool operator()(const T &x,const T&y)const
  {
    return x>y; //与传统不同 x>y是x<y的意思
  }
}*/
int main()
{
  const int SIZE=5;
  int a[SIZE]={5,21,14,2,3};
  list<int> lst(a,a+SIZE);
  lst.sort(MyLess()); //MyLess中()的规则比大小
  Print(lst.begin(),lst.end());
  cout<<endl;
  lst.sort(greater<int>()); //greater<int>()是个对象 greater是个类模板 数学上的大是当做小，其实是降序排列
  Print(lst.begin(),lst.end());
  cout<<endl;
  return 0;
}
