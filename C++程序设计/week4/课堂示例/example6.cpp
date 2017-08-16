/*第三课*/
/*自增自减运算符的重载*/
int main(){
  CDemo d(5);
  cout<<(d++)<<","; //等价于d.operator++(0);
  cout<<d<<","; //cout不支持其他任意类型的输出，想要正常输出整数，要设计一个强制类型转换符，将对象像整型数一样输出出来
  cout<<(++d)<<",";//等价于d.operator++();
  cout<<d<<endl;
  cout<<(d--)<<","; //等价于operator--(d,0);
  cout<<d<<",";
  cout<<(--d)<<","; //等价于operator--(d);
  cout<<d<<endl;
  return 0;
}
//输出结果：5，6，7，7   7，6，5，5
class CDemo{
private:
  int n;
public:
  CDemo(int i=0):n(i){} //构造函数初始化n
  CDemo operator++();  //用于前置形式
  CDemo operator++(int); //用于后置形式
  operator int() {return n;}  //强制类型转换
  friend CDemo operator--(CDemo &); //友元的全局函数，不是成员函数
  friend CDemo operator--(CDemo &,int);
};
CDemo CDemo::operator++(){ //前置++
  n++；
  return *this；
}
CDemo CDemo::operator++(int k){ //后置++
  CDemo tmp(*this);  //记录修改前的对象，把修改前的对象保存下来，输出修改前的对象
  n++;
  return tmp;//返回修改前的对象
}
CDemo operator--(CDemo & d){ //前置--
  d.n--;
  return d;
}
CDemo operator--(CDemo & d,int){ //后置--
  CDemo tmp(d);
  d.n--;
  return tmp;
}
