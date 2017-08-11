/*第四课*/
/*友元函数*/
class CCar; //提前声明CCar类，以便后面CDriver类使用
class CDriver{
public:
  void ModifyCar(CCar *pCar);//改装汽车
};
class CCar{
private:
  int price;
  friend int MostExpensiveCar(CCar car[],int total);//声明友元
  friend void CDriver::ModifyCar(CCar *pCar);//声明友元
};
void CDriver::ModifyCar(CCar *pCar)
{
  pCar->price+=1000; //汽车改装后价值增加
}
int MostExpensiveCar(CCar cars[],int total)//求最贵汽车的价格
{
  int tmpMax=-1;
  for(int i=0;i<total;i++)
    if(cars[i].price>tmpMax)
      tmpMax=cars[i].price;
    return tmpMax;
}
int main()
{
  return 0;
}
/*********************************************************************************/
/*this指针*/
/*从C++程序到C程序的翻译*/
class CCar{                          struct CCar{
public:                                   int price;
  int price;                         };
  void SetPrice(int p);              void SetPrice(struct CCar *this,
};                                            int p)
void CCar::SetPrice(int p)           {this->price=p;}
{                                    int main(){
  price=p;                                struct CCar car;
}                                         SetPrice(&car,20000);
int mian()                                return 0;
{                                    }
  CCar car;
  car.SetPrice(20000);
  return 0;
}
/********************************************************************************/
class Complex{
public:
  double real,imag;
  void Print(){cout<<real<<","<<imag;}
  Complex(double r,double i)：real(r),imag(i)
  {}
  Complex AddOne(){
    this->real++;//等价于real++;
    this->Print(); //等价于Print
    return *this; //返回c1自身
  }
};
int main(){
  Complex c1(1,1),c2(0,0);
  c2=c1.AddOne();//this 指向c1
  return 0;
}//输出 2，1
/********************************************************************************/
class A{
  int i;
public:
  void Hello(){cout<<"hello"<<endl;} // void Hello(A *this){cout<<"hello"<<endl;}
}; //若this
int main()
{
  A *p=NULL; //空指针p未指向任何对象
  p->Hello(); //Hello(p);
}//输出hello

/*但是void Hello(A *this){cout<<this->i<<"hello"<<endl;}
错误，this是空指针没法指向i
*/
