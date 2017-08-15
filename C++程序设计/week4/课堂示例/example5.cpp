/*第三课*/
/*流插入运算符的重载*/
/*假定下面程序输出为 5hello,该补写些什么*/
class CStudent{
public: int nAge;
};
int main(){
  CStudent s;
  s.nAge=5;
  cout<<s<<"hello";
  return 0;
}
ostream & operator<<(ostream & o,const CStudent & s){ //&引用节省开销不调用复制构造函数
  o << s.nAge; //cout=o
  return o; //返回值的类型还是cout ，引用
}
/******************************************************************************/
/*假定c是Complex复数类的对象，现在希望写”cout<<c;",就能以“a+bi”的形式输出c的值，
写“cin>>c;”,就能从键盘接受”a+bi"形式的输入，并且使得c.real=a,c.imag=b。*/
int main(){
  Complex c;
  int n;
  cin>>c>>n;
  cout<<c<<","<<n;
  return 0;
}
/*运行结果如下：
输入 13.2+133i 87
输出 13.2+133i,87*/
#include<iostream>
#include <string>
#include <cstdlib>
using naemspace std;
class Complex{
  double real,imag;
public:
  Complex(double r=0,double i=0):real(r),imag(i){}; //构造函数赋初值
  friend ostream & operator<<(ostream & os,const Complex & c);
  friend istream & operator>>(istream & is,const Complex & c);
}
ostream & operator<<(ostream & os,const Complex & c)
{
  os<<c.real<<"+"<<c.imag<<"i";//以“a+bi”形式输出
  return os;
}
istream & operator>>(istream & is,const Complex & c);
{
  string s;
  is>>s; //将”a+bi"作为字符串读入，“a+bi”中间不能有空
  int pos=s.find("+",0);
  string sTmp=s.substr(0,pos);//分离出代表实部的字符串
  c.real=atof(sTmp.c_str());
  //atof库函数能将const char*指针指向的内容转换成float
  sTmp=s.substr(pos+1,s.length()-pos-2);
  //分离出代表虚部的字符串
  c.imag=atof(sTmp.c_str());
  return is;
}
