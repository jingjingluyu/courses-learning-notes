/*1-1定义结构体类型的变量*/
#include<iostream>
using namespace std;
struct student
{
  int id_num; //学号
  char name[10]; //名字
};
int main()
{
  student mike={123,{'m','i','k','e','\0'}}; //对变量进行初始化，内存中的存储方式，类似于多维数组，
                                              //123整型占4个字节，mike占5个字节
  mike.id_num=20130000+mike.id_num;        //引用结构体变量中包含的子变量
  for(int i=0;mike.name[i]!='\0';i++)
    mike.name[i]=toupper(mike.name[i]);   //把字母变为大写
  cout<<mike.id_num<<" "<<mike.name<<endl;
  return 0;
}
/****************************************************************************/
/*1-2结构体变量赋值*/
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
  student mike2;  //未进行初始化
  mike2=mike1;     //把一个结构体变量付给另一个结构体变量，相当于copy一份给对方，与普通变量一样。
  mike2.id_num=20130000+mike2.id_num;
  for(int i=0;mike2.name[i]!='\0';i++)
    mike2.name[i]=toupper(mike2.name[i]);
  cout<<mike1.id_num<<" "<<mike1.name<<endl;  //123 mike
  cout<<mike2.id_num<<" "<<mike2.name<<endl;  //20130123 MIKE
  return 0;
}
/****************************************************************************/
/*1-2结构体做函数参数*/
#include<iostream>
using namespace std;
struct student
{
  int id_num; //学号
  char name[10]; //名字
};
void renew(student one)    //one 接纳 mike copy了一份给one,对one 的修改不影响mike
{
  one.id_num=20130000+one.id_num;
  for(int i=0;one.name[i]!='\0';i++)
    one.name[i]=toupper(one.name[i]);
  cout<<one.id_num<<" "<<one.name<<endl;    //20130123 MIKE
}
int main()
{
  student mike={123,{'m','i','k','e','\0'}};
  renew(mike);
  cout<<mike.id_num<<" "<<mike.name<<endl;  //123 mike
  return 0;
}
/****************************************************************************/
/*1-2结构体做函数返回值*/
#include<iostream>
using namespace std;
struct student
{
  int id_num; //学号
  char name[10]; //名字
};
student newone()
{
  student one={20130123,{'M','I','K','E','\0'}}; //one 是局部变量，函数被调用完毕，one不存在
  return one;
}
int main()
{
  student mike=newone(); //one copy 一份副本给mike
  cout<<mike.id_num<<" "<<mike.name<<endl;
  return 0;
}
