/*第三课*/
/*抽象函数*/
class A{
public:
  virtual void f()=0；//纯虚函数
  void g(){ this->f();} //ok 成员函数 允许调用纯虚函数
  A(){ }//f();错误 在构造函数中不可以调用纯虚函数
}；
class B:public A{
public:
  void f(){ cout<<"B:f()"<<endl; } //具体实现了f B就不是抽象类了
};
int main(){
  B b;
  b.g(); //由于在B中具体实现了f，所以调用B中f
  return 0;
}
//输出结果： B:f()
