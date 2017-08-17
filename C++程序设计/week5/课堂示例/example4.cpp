/*派生类的构造函数*/
class Bug{
private:
  int nLegs;
  int nColor;
public:
  int nType;
  Bug(int legs,int color); //初始化
  void PrintBug(){}; //打印出
};
class FlyBug:public Bug{
  int nWings;
public:
  FlyBug(int legs,int color,int wings);
};
Bug::Bug(int legs,int color){
  nLegs=legs;
  nColor=color;
}
//错误的FlyBug构造函数
FlyBug::FlyBug(int legs,int color,int wings){
  nLegs=legs; //不能访问
  nColor=color; //不能访问
  nType=1; //ok
  nWings=wings;
}
//正确的FlyBug构造函数
FlyBug::FlyBug(int legs,int color,int wings):Bug(legs,color){ //初始化类表来初始化legs和color
  nWings=wings;
}
int main(){
  FlyBug fb(2,3,4);
  fb.PrintBug();
  fb.nType=1;
  fb.nLegs=2; //error.nLegs is private
  return 0;
}
/****************************************************************************************/
/*构造和析构*/
class Base{
public:
  int n;
  Base(int i):n(i)
  {
    cout<<"Base"<<n<<"constructed"<<endl;
  }
  ~Base()
  {
    cout<<"Base"<<n<<"destructed"<<endl;
  }
};
class Derived:public Base{
public:
  Derived(int i):Base(i)
  {
    cout<<"Derived constructed"<<endl;
  }
  ~Derived()
  {
    cout<<"Derived destructed"<<endl;
  }
};
int main(){ Derived Obj(3),retun 0;}
/*输出结果
   Base 3 constructed
   Derived constructed
   Derived destructed
   Base 3 destructed
   */
/****************************************************************************************/
/*包含成员对象的派生类的构造函数*/
class Skill{
public:
  Skill(int n){}
};
class FlyBug:public Bug{
  int nWings;
  Skill sk1,sk2;
public:
  FlyBug(int legs,int color,int wings);
};
FlyBug::FlyBug(int legs,int color,int wings):
  Bug(legs,color),sk1(5),sk2(color){ //表达式中可以出现FlyBug构造函数的参数、常量
    nWings=wings;
  }
