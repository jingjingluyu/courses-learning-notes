/* 右值引用和move语义*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class String{
public:
  char * str;
  String():str(new char[1]){str[0]=0;}
  String(const char *s){
    str=new char[strlen(s)+1];
    strcpy(str,s);
  }
  String(const String &s) //深拷贝
  {
    cout<<"copy constructor called"<<endl;
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
  }
  String & operator=(const String & s) //两个string对象的赋值要进行深拷贝
  {
    cout<<"copy operator=called"<<endl;
    if(str!=s.str){
      delete [] str;
      str=new char[strlen(s.str)+1];
      strcpy(str,s.str);
    }
    return *this;
  }
  //move constructor 移动构造函数
  String(String && s):str(s.str) //str指向了s.str指向的地方
  {
    cout<<"move constructor called"<<endl;
    s.str=new char[1];
    s.str[0]=0;
  }
  //move assigment
  String & operator=(String &&s)
  {
    cout<<"move operator=called"<<endl;
    if(str!=s.str){
      delete []str;
      str=s.str; //让str指向s.str
      s.str=new char[1];
      s.str[0]=0;
    }
    return *this;
  }
  ~String() {delete [] str;}
};
template<class T>
void MoveSwap(T &a,T &b)
{
  T tmp(move(a)); //std::move(a)为右值，这里会调用move constructor ,a是一个左值，经过move,变为右值。
                  //如果T tmp(a)，则调用复制构造函数。tmp指向a所指向的地方，a被改变
  a=move(b); //move(b)为右值。因此这里会调用move assigment，改变了b,因为是临时对象所以可以
  b=move(tmp);//move(temp)为右值，因此这里会调用move assigment
}
int main()
{
  //String & r=String("this"); //error
  String s;
  s=String("ok"); //String("ok")是右值
  cout<<"******"<<endl;
  String && r=String("this");
  cout<<r.str<<endl;
  String s1="hello",s2="World";
  MoveSwap(s1,s2); //有意识的避免深拷贝
  cout<<s2.str<<endl;
  return 0;
}
/*输出：
move operator=called
******
this
copy constructor called
copy operator=called
copy operator=called
hello
*/
