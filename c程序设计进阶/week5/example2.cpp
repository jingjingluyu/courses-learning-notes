/*再谈一维数组的地址*/
#include<iostream>
using namespace std;
int main()
{
  int a[4]={1,3,5,7}
  cout<<a<<endl;          //0028F7C4 指向第一个元素的指针
  cout<<a+1<<endl;       //指向第二个元素的指针
  cout<<&a<<endl;        //a是一个常量 0028F7C4指向整个数组的指针
  cout<<&a+1<<endl;      //跨越整个数组
  cout<<*(&a)<<endl;     //返回的结果是&a指向的内容，相当于打印a  0028F7C4
  cout<<*(&a)+1<<end;   //相当于a+1
  return 0
}
