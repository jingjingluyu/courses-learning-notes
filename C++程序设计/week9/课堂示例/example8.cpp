/*第四课*/
/*关于ostream_iterator,istream_iterator的例子*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
  int a[4]={1,2,3,4};
  My_ostream_iterator<int> oit(cout,"*");
  copy(a,a+4,oit); //输出 1*2*3*4*
  ofstream oFile("test.txt",ios::out);
  My_ostream_iterator<int> oitf(oFile,"*");
  copy(a,a+4,oitf);  //向test.txt文件中写入 1*2*3*4*
  oFile.close();
  return 0;
}
//如何编写My_ostream_iterator？
/*copy的源代码：
template<class _II,class _OI>
inline _OI copy(_II _F,_II _L,_OI _X){
  for(;_F!=_L;++_X,++_F)
    *_X=*_F;
  return (_X);
}
上面的程序中调用语句“copy(a,a+4,oit)”实例化后得到copy 如下：
*/
My_ostream_iterator<int> copy(int* _F,int* _L,My_ostream_iterator<int> _X) //实例化
{
  for(;_F!=_L;++_X,++F) //++ * = 重载
    *_X=*_F; //一个函数调用的表达式出现在等号的左边，返回值是引用
  return (_X);
}
/*My_ostream_iterator类应该重载”++“和”*”运算符 “=”也应该被重载*/
#include<iterator>
template<class T>
class My_ostream_iterator:public iterator<output_iterator_tag,T>{
private:
  string sep; //分隔符*
  ostream & os; //记录 cout
public:
  My_ostream_iterator(ostream & o,string s):sep(s),os(o){}
  void operator++(){}; //++只需要有定义即可，不需要做什么
  My_ostream_iterator & operator * (){return *this;}
  My_ostream_iterator & operator = (const T & val)
  {os<<val<<sep;return *this;}
}
