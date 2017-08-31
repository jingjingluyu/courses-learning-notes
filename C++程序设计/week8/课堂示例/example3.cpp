/*第三课*/
/*vector容器的使用*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int i;
  int a[5]={1,2,3,4,5}; //静态数组
  vector<int> v(5); //动态数组 用构造函数进行初始化 通过传递int 型的参数5，v容器中包含了5个元素
  cout<<v.end()-v.begin()<<endl; //返回首元素和末尾元素后一位置的迭代器 相减
  for(i=0;i<v.size();i++)
    v[i]=i; //可以用[] <
  v.at(4)=100; //访问某个元素
  for(i=0;i<v.size();i++)
    cout<<v[i]<<",";
  cout<<endl;
  vector<int> v2(a,a+5); //构造函数 定义容器起始位置和末尾位置
  v2.insert(v2.begin()+2,13); //在begin()+2位置插入13 insert插入函数
  for(i=0;i<v2.size();i++)
    cout<<v2.at(i)<<",";
}
/*输出
5
0,1,2,3,100,
1,2,13,3,4,5,*/
/********************************************************/
/*二维动态数组*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
  vector< vector<int> > v(3);
  for(int i=0;i<v.size();++i)
  {
    for(int j=0;j<4;++j)
      v[i].push_back(j);
  }
  for(int i=0;i<v.size();++i){
    for(int j=0;j<v[i].size();++j)
      cout<<v[i][j]<<" ";
      cout<<endl;
  }
  return 0;
}
