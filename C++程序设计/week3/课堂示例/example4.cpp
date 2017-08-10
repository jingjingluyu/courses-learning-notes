/*构造函数和析构函数调用时机*/
class Demo{
  int id;  //私有的
public:
  Demo(int i)  //用构造函数初始化id
  {
    id =i;
    cout<<"id="<<id<<"Constructed"<<endl;
  }
  ~Demo()
  {
    cout<<"id="<<id<<"Destructed"<<endl;
  }
};
Demo d1(1); //全局变量 输出id=1 Constructed
void Func(){
  static Demo d2(2); //静态变量 id=2 Constructed
  Demo d3(3);  //id=3 Constructed
  cout<<"Func"<<end;   //d2是静态的消亡在整个程序结束时 id=3 Destructed
}
int main(){
  Demo d4(4); //输出id=4 Constructed
  d4=6; // 类型转换构造函数，生成临时对象temp，temp之后再消亡 输出 输出id=6 Constructed id=6 Destructed
  cout<<"main"<<endl;
  {                 //作用域{}，生命周期，离开作用域消亡
    Demo d5(5);     //id=5 Constructed id=5 Destructed
  }
  Func();
  cout<<"main ends"<<endl; //d4:id=6 Constructed id=6 Destructed  d2:id=2 Destructed d1:id=1 Destructed
  return 0;
}
