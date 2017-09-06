/*第四课*/
/*算法*/
#include<iostream>
#include<algorithm>
using namespace std;
class A{
public:
  int n;
  A(int i):n(i){}
};
bool operator<(const A &a1,const A& a2){
  cout<<"<called"<<endl;
  if(a1.n==3&&a2.n==7)
    return true;
  return false;
}
int main()
{
  A aa[]={3,5,7,2,1};
  cout<<min_element(aa,aa+5)->n<<endl;
  cout<<max_element(aa,aa+5)->n<<endl;
  return 0;
}
/*输出
<called
<called
<called
<called
3
<called
<called
<called
<called
7*/

/*******************************************************************/

#include<vector>
#include<iostream>
#include<numeric>
#include<list>
#include<algorithm>
#include<iterator>
using namespace std;
class CLessThen9{
public:
  bool operator()(int n){ return n<9; } //小于9就返回ture
};
void outputSquare(int value){cout<<value * value<<" ";} //平方
int calculateCube(int value){return value * value * value;}//立方
int main()
{
  const int SIZE=10;
  int a1[]={1,2,3,4,5,6,7,8,9,10};
  int a2[]={100,2,8,1,50,3,8,9,10,2};
  vector<int> v(a1,a1+SIZE);
  ostream_iterator<int> output(cout," "); //ostream_iterator是list里自己定义的类模板 实例化
  random_shuffle(v.begin(),v.end()); //随机 变序算法 伪随机计算机不
  cout<<endl<<"1)";
  copy(v.begin(),v.end(),output);//通过copy进行输出 output不是一个容器但也可以这么用
  copy(a2,a2+SIZE,v.begin()); //把a2的内容拷贝到v中，要求目标区间有足够的空间
  cout<<endl<<"2)";
  cout<<count(v.begin(),v.end(),8);
  cout<<endl<<"3)";
  cout<<count_if(v.end().CLessThen9());//CLessThen9是一个类的名字，加括号就是成对象的名字 op(e)=op(9)
  cout<<endl<<"4)";
  cout<<*(min_element(v.begin(),v.end()));
  cout<<endl<<"5)";
  cout<<*(max_element(v.begin(),v.end()));
  cout<<endl<<"6)";
  cout<<accumulate(v.begin(),v.end(),0); //求和
  cout<<endl<<"7)";
  fot_each(v.begin(),v.end(),outputSquare);
  vector<int>cubes(SIZE);
  transform(a1,a1+SIZE,cubes.begin(),calculateCube);// 将结果放到cubes.begin()
  cout<<endl<<"8)";
  copy(cubes.begin(),cubes.end(),output);
  return 0;
}
/*输出：
1)7 1 4 6 8 9 5 2 3 10
2)2
3)6
4)1
5)100
6)193
7)10000 4 64 1 2500 9 64 81 100 4
8)1 8 27 64 125 216 343 512 729 1000
*/
