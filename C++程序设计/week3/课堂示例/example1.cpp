/*第一课*/
/*重载成员函数*/
#include<iostream>
using namespace std;
class Location
{
  private:
      int x,y;
  public:
      void init(int x=0,int y=0);  //初始化
      void valueX(int val){x=val;}  //给x赋值
      int valueX(){return x;}
};
void Location::init(int X,int Y)
{
  x=X;  //x=5
  y=Y;  //y=0
}
int main()
{
  Location A;
  A.init(5);
  A.valueX(5); //一个参数对应第一个value
  cout<<A.valueX()； //5
  return 0；
}
/*****************************************************************************/
/*构造函数*/
class Complex{
 private:
       double real, imag;
 public:
       void Set(double r,double i);
}; //编辑器自动生成默认构造函数
Complex c1; //默认构造函数被调用
Complex *pc=new Complex;//默认构造函数被调用


class Complex{
 private:
       double real, imag;
 public:
       Complex(double r,double i=0);  //构造函数
};
Complex::Complex(double r,double i){
  real=r,imag=i;
}
Complex c1; //error,缺少构造函数的参数
Complex *pc=new Complex;//error,没有参数
Complex c1(2);//OK,第二个参数可以缺省掉
Complex c1(2,4),c(3,5);
Complex *pc=new Complex(3,4);

/*可以由多个构造函数*/
class Complex{
 private:
       double real, imag;
 public:
       void Set(double r,double i);
       Complex(double r,double i);
       Complex(double r);
       Complex(Complex c1,Complex c2);
};
Complex::Complex(double r,double i)
{
  real=r;imag=i;
}
Complex::Complex(double r)
{
  real=r;imag=0;
}
Complex::Complex(Complex c1,Complex c2);
{
  real=c1.real+c2.real;
  imag=c1.imag+c2.imag;
}
Complex c1(3),c2(1,0),c3(c1,c2);//c1(3,0) c2(1,0) c3(4,0)

/*****************************************************************************/
/*构造函数在数组中的使用*/
 class CSample{
        int x;
  public:
        CSample(){
          cout<<"Constructor 1 Called"<<endl;
        }
        CSample(int n){
          x=n;
          cout<<"Constructor 2 Called"<<endl;
        }
 };
int main()
{
  CSample array1[2]; //调用无参构造函数函数  Constructor 1 Called Constructor 1 Called
  cout<<"step1"<<endl;
  CSample array2[2]={4,5}; //调用有参构造函数 Constructor 2 Called Constructor 2 Called
  cout<<"step2"<<endl;
  CSample array3[2]={3}; //第一个有参，第二个无参 Constructor 2 Called  Constructor 1 Called
  cout<<"step3"<<endl;
  CSample *array4=new CSample[2];//调用无参构造函数函数  Constructor 1 Called Constructor 1 Called
  delete []array4;
  return 0;
}


class Test{
   public:
        Test(int n){}           //(1)
        Test(int n,int m){}     //(2)
        Test(){}               //(3)
};
Test arry1[3]={1,Test(1,2)}; //三个元素分别用（1）（2）（3）初始化
Test arry2[3]={Test(2,3)，Test(1,2),1};  //三个元素分别用（2）（2）（1）初始化
Test *pArray[3]={new Test(4)，new Test(1,2)};
/*指针数组，内容初始化，就不会引发对象生成,因为里面的每个元素都是指针不是对象，
  也就不会调用构造函数*/
//new出来的类型是Test* ,new出来的对象的地址来初始化，前两个元素指向new出来的对象
   //最后的元素没有初始化，咩有任何对象生成，所以（1）（2）
