/*类型转换构造函数*/
class Complex{
    public:
      double real,inag;
      Complex(int i){        //类型转换构造函数
        cout<<"IntConstructor called"<<endl;
        real=i;imag=0;
      }
      Complex(double r,double i)  //构造函数
      {
        real=r;imag=i;
      }
};
int main(){
    Complex c1(7,8);
    Complex c2=12; //"="是初始化，不是赋值。初始化过程，调用类型转换构造函数不生成临时对象。
                   //只会把12作为参数传给int i
    c1=9; //是赋值语句。等号两边不同类型，c1是Complex类型，9是整型常量。
          //调用类型转换构造函数，首先生成临时对象，生成成一个临时对象Complex。对象9被自动转换成一个临时对象Complex对象，赋值给c1
    cout<<c1.real<<","<<c1.imag<<endl;//输出IntConstructor called IntConstructor called 9，0
    return 0;
}
/*******************************************************************************/
/*析构函数*/
class String
{
private:
  char *p;
public:
  String(){   //构造函数
    p=new char[10];
  }
  ~ String();  //析构函数
};
String::~String(){
  delete []p;  //delet p,只delete一个对象
}
/*******************************************************************************/
/*对象数组的每个元素都被调用*/
class Ctest{
public:
  ~Ctest(){ cout<<"destructor called"<<endl;}
};
int main(){
  Ctest array[2];
  cout<<"End Main"<<endl; //输出 End Main destructor called destructor called
  return 0;
}
/*******************************************************************************/
