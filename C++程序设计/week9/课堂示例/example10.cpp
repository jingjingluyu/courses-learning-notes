/*第五课*/
/*作用在整形数组容器上的例子*/
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<iterator>
using namespace std;
int main(){
  int a[]={8,7,10};
  list<int> ls(a,a+3);
  while(next_permutation(ls.begin(),ls.end())){
    list<int>::iterator i;
    for(i=ls.begin();i!=ls.end();++i)
      cout<<*i<<" ";
    cout<<endl;
  }
}
/*输出
8 10 7
10 7 8
10 8 7 */
/**********************************************************/

/*按个位数大小排序，按降序排序
  输出：
  111 2 14 78 9
  111 78 14 9 2*/
#include<iostream>
#include<algorithm>
using namespace std;
class namespace std;
class MyLess{
  public:
    bool operator()(int n1,int n2)
    {
      return (n1%10)<(n2%10);
    }
};
int main(){
    int a[]={14,2,9,111,78}
    sort(a,a+5,MyLess());
    int i;
    for(i=0;i<5;i++)
      cout<<a[i]<<" ";
    cout<<endl;
    sort(a,a+5,greater<int>());//greater<int>(),用>比较，谁数学上大，反而小
    for(i=0;i<5;i++)
      cout<<a[i]<<" ";
}
/**********************************************************/
/*binary_search*/
#include<vector>
#include<bitset>
#include<iostream>
#include<numeric>
#include<list>
#include<algorithm>
using namespace std;
bool Greater10(int n)
{
  return n>10;
}
int main()
{
  const int SIZE=10;
  int a1[]={2,8,1,50,3,100,8,9,10,2};
  vector<int> v(a1,a1+SIZE);
  ostream_iterator<int> output(cout," ");
  vector<int>::iterator location;
  location=find(v.begin(),v.end(),10);
  if(location!=v.end())
  {
    cout<<endl<<"1)"<<location - v.begin();
  }
  location=find_if(v.begin(),v.end(),Greater10); //大于10的
  if(location!=v.end())
    cout<<endl<<"2)"<<location - v.begin();
  sort(v.begin(),v.end()); //需要先进行排序再二分查找
  if(binary_search(v.begin(),v.end(),9))
  {
    cout<<endl<<"3)"<<"9 found";
  }
}
/*输出：
 1）8
 2）3
 3）9 found*/
