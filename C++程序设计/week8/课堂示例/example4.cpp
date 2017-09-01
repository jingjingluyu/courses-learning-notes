/*第三课*/
/*list容器使用*/
#include<list>
#include<iostream>
#include<algorithm>
using namespace std;
class A{
private:
  int n;
public:
  A(int n_){ n=n_;}
  friend bool operator<(const A & a1,const A & a2);
  friend bool operator==(const A & a1,const A & a2);
  friend ostream & operator<<(ostream & o,const A & a);
};
bool operator<(const A &a1,const A & a2){
  return a1.n<a2.n; //结果
}
bool operator==(const A &  a1,const A & a2){
  return a1.n==a2.n;
}
ostream & operator << (ostream & o,const A & a){
  o<<a.n;
  return o;
}
//定义函数模板PrintList，打印列表中的对象
template<class T>
void PrintList(const list<T> & lst){
  int tmp=lst.size();
  if(tmp>0){
    typename list<T>::const_iterator i; //定义了一个迭代器i
    i=lst.begin();
    for(i=lst.begin();i!=lst.end();i++)
      cout<<*i<<",";
  } //与其他顺序容器不同，list容器只能使用双向迭代器，
}   //因此不支持大于/小于比较运算符，[]运算符和随机移动
    //typename用来说明list<T>::const_iterator是个类型
    // 在VS中不写也可以
int main(){
  list<A> lst1,lst2;
  lst1.push_back(1);lst1.push_back(3);
  lst1.push_back(2);lst1.push_back(4);lst1.push_back(2);
  lst2.push_back(10);lst2.push_back(20);
  lst2.push_back(30);lst2.push_back(30);
  lst2.push_back(30);lst2.push_back(40);lst2.push_back(40);
  cout<<"1)";PrintList(lst1);cout<<endl; //
  cout<<"2)";PrintList(lst2);cout<<endl;
  lst2.sort(); //list容器的sort函数 重排序
  cout<<"3)";PrintList(lst2);cout<<endl;
  lst2.pop_front(); //除去第一个首元素
  cout<<"4)";PrintList(lst2);cout<<endl;
  lst1.remove(2); //删除所有和A(2)相等的元素
  cout<<"5)";PrintList(lst1);cout<<endl;
  lst2.unique(); //删除所有和前一个元素相等的元素
  cout<<"6)";PrintList(lst2);cout<<endl;
  lst1.merge(lst2); //合并lst2到lst1并清空lst2
  cout<<"7)";PrintList(lst1);cout<<endl;
  cout<<"8)";PrintList(lst2);cout<<endl;
  lst1.reverse(); //reverse逆序重排
  cout<<"9)";PrintList(lst1);cout<<endl;
  lst2.push_back(100);lst2.push_back(200);
  lst2.push_back(300);lst2.push_back(400);
  list<A>::iterator p1,p2,p3;  //三个迭代器指向find算法所返回的查找的对应元素所在位置的迭代器
  p1=find(lst1.begin(),lst1.end(),3); //3所在的迭代器
  p2=find(lst2.begin(),lst2.end(),200);
  p3=find(lst2.begin(),lst2.end(),400);
  lst1.splice(p1,lst2,p2,p3);//将[p2,p3)插入p1之前 并从lst2中删除[p2,p3)
  cout<<"11)";PrintList(lst1);cout<<endl;
  cout<<"12)";PrintList(lst2);cout<<endl;
}
/*输出：
1)1,3,2,4,2,
2)10,20,30,30,30,40,40,
3)10,20,30,30,30,40,40,
4)20,30,30,30,40,40,
5)1,3,4,
6)20,30,40,
7)1,3,4,20,30,40,
8)
9)40,30,20,4,3,1,
11)40,30,20,4,200,300,3,1,
12)100,400,
*/
