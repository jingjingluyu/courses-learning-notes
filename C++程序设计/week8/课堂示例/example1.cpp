/*第一课*/
/*迭代器示例*/

#include<vector>
#include<iostream>
using namespace std;
int main(){
  vector<int> v; //一个存放int元素的数组，一开始里面没有元素 vector容器类的对象v
  v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); //push_back尾部添加
  vector<int>::const_iterator i;  //常量迭代器 通过i可以访问所指向的内容
  for(i=v.begin();i!=v.end();++i) //v.begin返回值是一个迭代器指向第一个元素 v.end是最后一个元素后面一个位置
    cout<<*i<<",";  //1,2,3,4
  cout<<endl;
  vector<int>::reverse_iterator r; //反向迭代器
  for(r=v.rbegin();r!=v.rend();r++) //++操作会指向前一个元素
    cout<<*r<<",";  //4，3，2，1
  cout<<endl;
  vector<int>::iterator j; //非常量迭代器
  for(j=v.begin();j!=v.end();j++)
    *j=100;
  for(i=v.begin();i!=v.end();i++)
    cout<<*i<<","; //100,100,100,100
}
/**********************************************************************/
/*第二课*/
/*遍历vector*/
vector<int> v(100); //整形数组里面有100个元素
int i;
for(i=0;i<v.size();i++)
  cou<<v[i];  //根据下标随机访问，遍历，v.size()代表v中元素的个数
vector<int>::const_iterator ii; //定义常量迭代器
for(ii=v.begin();ii!=v.end();ii++)
  cout<<*i;
for(ii=v.begin();ii<v.end();ii++) //随机访问迭代器是可以用<比较的
  cout<<*ii;
  //间隔一个输出
ii=v.begin();
while(ii<v.end()){
  cout<<*ii;
  ii=ii+2;
}
/**********************************************************************/
/*遍历list的正确方法*/
list<int> v;
list<int>::const_iterator ii;
for(ii=v.begin();ii!=v.end();++ii)
  cout<<*ii;
/*错误的做法*/
for(ii=v.begin();ii<v.end();ii++)
  cout<<*ii;
//双向迭代器不支持<,list没有[]成员函数,不支持随机访问
for(int i=0;i<v.size();i++)
  cout<<v[i]; //错
/**********************************************************************/
/*find算法示例*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
  int array[10]={10,20,30,40};
  vector<int> v;
  v.push_back(1); v.push_back(2);
  v.push_back(3); v.push_back(4);
  vector<int>::iterator p;
  p=find(v.begin(),v.end(),3); //在整个v容器中找3
  if(p!=v.end())
    cout<<*p<<endl; //3
  p=find(v.begin(),v.end(),9);
  if(p==v.end())
    cout<<"not found"<<endl; //not found
  p=find(v.begin()+1,v.end()-2,1); //整个容器：[1,2,3,4],查找区间：[2,3)
  if(p!=v.end())
    cout<<*p<<endl; //3
  int *pp=find(array,array+4,20); //数组名是迭代器
  cout<<*pp<<endl; //20
}
