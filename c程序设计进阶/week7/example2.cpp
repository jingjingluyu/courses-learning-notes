/*1-3指向结构体的指针*/
#include<iostream>
using namespace std;
struct student
{
  int id_num; //学号
  char name[10]; //名字
};
int main()
{
  student mike={123,{'m','i','k','e','\0'}};
  student *one=&mike;
  cout<<(*one).id_num<<" "<<(*one).name; //还可以写成：cout<<one->id_num<<" "<<one->name;
  return 0;
}
/****************************************************************************/
/*1-3指向结构体变量的指针做函数参数*/
#include<iostream>
using namespace std;
struct student
{
  int id_num; //学号
  char name[10]; //名字
};
void renew(student *one)            //拿到了main中的地址
{
  one->id_num=20130000+one->id_num;   //修改one指向的内容
  for(int i=0;one->name[i]!='\0';i++)
    one->name[i]=toupper(one->name[i]);
}
int main()
{
  student mike={123,{'m','i','k','e','\0'}};
  renew(&mike);  //把地址当做参数传递给renew
  cout<<mike.id_num<<" "<<mike.name;    //20130123  MIKE
  return 0;
}
/****************************************************************************/
/*1-3结构体数组*/
#include<iostream>
using namespace std;
struct student
{
  int id_num; //学号
  char name[10]; //名字
};
int main()
{
  student myclass[3]=
  {
    123,{'m','i','k','e','\0'},
    133,{'t','o','m','\0'},
    143,{'j','a','c','k','\0'}};
  student *one=myclass; //指向数组首元素的指针
  cout<<one->id_num<<" "<<one->name<<endl;  //123 mike
  one++； //印证++,会跨过多大
  cout<<one->id_num<<" "<<one->name<<endl; //133 tom
  return 0；
}
