/*第四课*/
/*写出MyMax模板*/
#include<iostream>
#include<iterator>
using namespace std;
class MyLess{
public:
  bool operator()(int a1,int a2){
    if((a1%10)<(a2%10))  //个位数小就算小
      return true;
    else
      return false;
  }
};
bool MyCompare(int a1,int a2)
{
  if((a1%10)<(a2%10)) //找个位数大的
    return false;
  else
    return true;
}
template<class T,class Pred>
T MyMax(T first,T last,Pred myless) //T的类型是个迭代器  myless指明比大小的规则
{
  T tempMax=first;
  for(;first!=last;++first)
    if(myless(*tempMax,*first)) //返回值是ture，更新tempMax
      tempMax=first;
  return tempMax;
};
int main()
{
  int a[]={35,7,13,19,12};
  cout<< * MyMax(a,a+5,MyLess())<<endl; //MyMax可以是个函数指针也可以是个函数对象，指向返回值 此时调用MyLess比较函数
  cout<< * MyMax(a,a+5,MyCompare)<<endl; //个位数最小 ，此时调用MyCompare比较函数
  return 0;
}
