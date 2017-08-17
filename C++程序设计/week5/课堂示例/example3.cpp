/*第二课*/
/*基类和派生类有同名成员的情况*/
class base{
  int j;
public:
  int i;
  void func();
};
class derived:public base{
public:
  int i;
  void access();
  void func();
};
void derived::access()
{
  j=5; //error ，j是base类中的私有成员，不能被调用
  i=5; //引用的是派生类的i
  base::i=5; //引用的是基类的i
  func(); //派生类的
  base::func(); //基类的
}
derived obj;
obj.i=1; //派生类
obj.base::i=1;
/*Obj占用的存储空间
    Base::j
    Base::i
    i */
/*****************************************************************/
/*保护成员*/
class Father{
private:int nPrivate; //私有成员
public:int nPublic; //公有成员
protected:int nProtected; //保护成员
};
class Son:public Father{
  void AccessFather(){
    nPublic=1;  //ok;
    nPrivate=1; //wrong
    nProtected=1;  //ok 访问从基类继承的protected成员
    Son f;
    f.nProtected=1; //wrong f不是当前对象
  }
};
int main(){
  Father f;
  Son s;
  f.nPublic=1; //ok
  s.nPublic=1; //ok
  f.nProtected=1; //error
  f.nPrivate=1; //error
  s.nProtected=1; //error
  s.nPrivate=1; //error
  return 0;
}
