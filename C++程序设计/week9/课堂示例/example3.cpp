/*第二课*/
/*multimap示例*/
#include<iostream>
#include<map>
using namespace std;
int main()
{
  typedef multimap<int,double,less<int> >mmid; //less<int>比大小规则
  mmid pairs;
  cout<<"1)"<<pairs.count(15)<<endl;
  pairs.insert(mmid::value_type(15,2.7));//typedef pair<const Key,T>value_type;相当于生成了一个pair对象
  pairs.insert(mmid::value_type(15,99.3));
  cout<<"2)"<<pairs.count(15)<<endl; //求关键字等于某值的元素个数
  pairs.insert(mmid::value_type(30,111.11));
  pairs.insert(mmid::value_type(10,22.22));
  pairs.insert(mmid::value_type(25,33.333));
  pairs.insert(mmid::value_type(20,9.3));
  for(mmid::const_iterator i=pairs.begin();i!=pairs.end();i++)
    cout<<"("<<i->first<<","<<i->second<<")"<<",";
}
