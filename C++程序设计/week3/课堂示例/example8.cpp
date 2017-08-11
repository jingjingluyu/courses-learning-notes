/*常量成员函数*/
class Sample
{
public:
  int value;
  void GetValue() const;
  void fune(){};
  Sample(){}
}；
void Sample::GetValue() const
{
  value=0;//wrong 不能修改成员变量的值
  fune(); //wrong 不能调用同类的非常量成员函数
}
int main(){
  const Sample o;
  o.value=100;//err.常量对象不可被修改
  o.func();//err.常量对象上面不能执行非常量成员函数
  o.GetValue();//ok.常量对象上可以执行常量成员函数
  return 0；
} //在Dec C++中，要为Sample类编写无参构造函数才可以，Visual Studio 2010中不需要
/****************************************************************************/
/*常量成员函数的重载*/
class CTest{
private:
  int n;
public:
  CTest(){n=1;}
  int GetValue() const{return n;}
  int GetValue(){return 2*n;}
};
int main(){
  const CTest objTest1;
  CTest objTest2;
  cout<<objTest1.GetValue()<<","<<objTest2.GetValue(); //输出1，2
  return 0;
}
