/*第一课*/
/*多态的表现形式一*/
class CBase{
public:
  virtual void SomeVirtualFunction(){}
};
class CDerived:public CBase{
public:
  virtual void SomeVirtualFunction(){}
};
int main(){
  CDerived ODerived;
  CBase *p= &ODerived; //指向派生类对象
  p->SomeVirtualFunction();//调用哪个虚函数取决于p指针指向哪种类型的对象
  return 0;
}
/*多态的表现形式二*/
class CBase{
public:
  virtual void SomeVirtualFunction(){}
};
class CDerived:public CBase{
public:
  virtual void SomeVirtualFunction(){}
};
int main(){
  CDerived ODerived;
  CBase & r=ODerived;// r引用派生类的对象
  r.SomeVirtualFunction();//调用哪个虚函数取决于r引用哪种类型的对象
  return 0;
}
/*多态简单示例*/
class A{
public:
  vritual void Print()
  {cout<<"A::Print"<<endl;}
};
class B:public A{
public:
  virtual void Print(){cout<<"B::Print"<<endl;}
};
class D:public A{
public:
virtual void Print(){cout<<"D::Print"<<endl;}
};
class E:public B{
  virtual void Print(){cout<<"E::Print"<<endl;}
};
int main(){
  A a;B b; E e; D d;
  A * pa=&a; B * pb=&b;
  D * pd=&d; E * pe=&e;
  pa->Print(); //A::Print
  pa=pb;
  pa->Print(); //B::Print
  pa=pd;
  pa->Print();//D::Print
  pa=pe;
  pa->Print();//E::Print
  return 0;
}
