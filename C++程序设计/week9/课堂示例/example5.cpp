/*第二课*/
/*map示例*/
#include<iostream>
#include<map>
using namespace std;
template <class Key,class Value>
ostream & operator<<(ostream & o,const pair<Key,Value> & p)
{
  o<<"("<<p.first<<","<<p.second<<")";
  return o;
}
int main()
{
  typedef map<int,double,less<int> > mmid;
  mmid pairs;
  cout<<"1)"<<pairs.count(15)<<endl; //输出有多少个15
  pairs.insert(mmid::value_type(15,2.7));
  pairs.insert(make_pair(15,99.3)); //make_pair生成一个pair对象，想要确定是否成功参考set
  cout<<"2)"<<pairs.count(15)<<endl;
  pairs.insert(mmid::value_type(20,9.3));
  mmid::iterator i;
  cout<<"3)";
  for(i=pairs.begin();i!=pairs.end();i++)
    cout<<*i<<",";
  cout<<endl;
  cout<<"4)";
  int n=pairs[40]; //如果没有关键字为40的元素，则插入一个
  for(i=pairs.begin();i!=pairs.end();i++)
    cout<<*i<<",";
  cout<<endl;
  cout<<"5)";
  pairs[15]=6.28;//把关键字为15的元素值改为6.28
  for(i=pairs.begin();i!=pairs.end();i++)
    cout<<*i<<",";
}
/*输出：
1)0
2)1
3)(15,2.7),(20,9.3),
4)(15,2.7),(20,9.3),(40,0),
5)(15,6.28),(20,9.3),(40,0),
*/
