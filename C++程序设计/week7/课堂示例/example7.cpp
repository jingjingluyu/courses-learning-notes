/*第四课*/
/*寻找string中的字符*/
string s1("hello worlld"); //定义了一个string类型的s1用hello world进行初始化
cout<<s1.find("ll")<<endl;    //2
cout<<s1.find("abc")<<endl;   //4294967295
cout<<s1.rfind("ll")<<endl;   //9
cout<<s1.rfind("abc")<<endl;  //4294967295
cout<<s1.find_first_of("abcde")<<endl;  //1
cout<<s1.find_first_of("abc")<<endl; //4294967295
cout<<s1.fing_last_of("abcde")<<endl; //11
cout<<s1.find_last_of("abc")<<endl; //4294967295
cout<<s1.find_first_not_of("abcde")<<endl;  //0
cout<<s1.find_first_not_of("hello world")<<endl; //4294967295
cout<<s1.find_last_not_of("abcde")<<endl; //10
cout<<s1.find_last_not_of("hello world")<<endl; //4294967295
/********************************************************************/
/*输出重定向*/
#include<iostream>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  freopen("test.txt","w",stdout); //将标准输出cout重定向到test.txt文件
  if(y==0) //除数为0则在屏幕上输出错误信息
    cerr<<"error."<<endl; //调试信息，出现在屏幕上。没有被重定向
  else
    cout<<x/y; //正确结果，输出结果到test.txt
  return 0;
}
/********************************************************************/
/*输入重定向*/
#include<iostream>
using namespace std;
int main(){
  double f;
  int n;
  freopen("t.txt","r",stdin); //cin被改为从t.txt中读取数据
  cin>>f>>n;
  cout<<f<<","<<endl;
  return 0;
}
/********************************************************************/
/*istream类成员*/
#include<iostream>
using namespace std;
int mian(){
  int x;
  char buf[100];
  cin>>x;
  cin.getline(buf,90);
  cout<<buf<<endl;
  return 0;
}
/*输入：
  12 abcd回车
  输出
   abcd (空格+abcd)

  输入：
  12 回车
  程序立即结束，输出
  空行
  因为getline读到留在流中的‘\n’就会返回 但里面仍然存储了\0
