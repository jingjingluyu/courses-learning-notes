/*第一课*/
/*运算符重载为普通函数*/
class Complex{
public:
  Complex(double r=0.0,double i=0.0){ //构造函数初始化
    real=r;
    imaginary=i;
  }
  double real;
  double imaginary;
}
Complex operator+(const Complex & a,const Complex & b)
{
  return Complex(a.real+b.real,a.imaginary+b.imaginary);
} //类名(参数表)就代表一个对象
Complex a(1,2),b(2,3),c;
c=a+b;//相当于，operator+(a+b)
/*重载为普通函数时，参数个数为运算符目数*/
/*******************************************************************************/
/*运算符重载为成员函数*/
class Complex{
public:
  Complex(double r=0.0,double m=0.0):
     real(r),imaginary(m){} //constructor
  Complex operator+(const Complex &); //addition a+b a认为是对象 +b是操作数只传递操作数 a.qurator+
  Complex operator-(const Complex &);  //subtraction
private:
  double real; //real part
  double imaginary; //imaginary part
};
/*重载为成员函数是时，参数个数为运算符目数减一*/
//Overloaded addition operator
Complex Complex::operator+(const Complex & operator2){
  return Complex(real+operand2.real,imaginary+operand2.imaginary);
}
//Overloaded subtraction operator2
Complex Complex::operator-(const Complex & operand2){
  return Complex(real-operand2.real,imaginary-operand2.imaginary);
}
int main(){
  Complex x,y(4.3,8.2),z(3.3,1.1);
  x=y+z;//相当于x=y.operator+(z);
  x=y-z;//相当于x=y.operator-(z);只传入一个参数，后面的参数
  return 0;
}
