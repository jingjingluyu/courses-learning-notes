/*第五课*/
/*unique算法*/
int main()
{
  int a[5]={1,2,3,2,5};
  int b[6]={1,2,3,2,5,6};
  ostream_iterator<int> oit(cout,",");
  int *p=remove(a,a+5,2);
  cout<<"1)";copy(a,a+5,oit);cout<<endl;  //输出1） 1，3，5，2，5， 首先 2看成空位置
  cout<<"2)"<<p-a<<endl;  //输出2）3
  vector<int> v(b,b+6);
  remove(v.begin(),v.end(),2);
  cout<<"3)";copy(v.begin(),v.end(),oit);cout<<endl; //输出3） 1，3，5，6，5，6，
  cout<<"4)";cout<<v.size()<<endl;//v中的元素没有减少，输出4）6
  return 0;
}
/************************************************************************************/
/*next_permutation的例子*/
#include<iostream>
#include<algorithm>
#include<string>
int main(){
  string str="231";
  char szStr[]="324";
  while(next_permutation(str.begin(),str.end())){ //返回值为true就找到下一个排列，为false则找不到
    cout<<str<<end;  //会修改值 最后str是321
  }
  cout<<"****"<<endl;
  while(next_permutation(szStr,szStr+3)){
    cout<<szStr<<endl;
  }
  sort(str.begin(),str.end());//sort后又变为132输出
  cout<<"****"<<endl;
  while (next_permutation(str.begin(),str.end())) {
    cout<<str<<endl;
  }
  return 0;
}
/*输出：
312
321
****
342
423
432
****
132
213
231
312
321*/
