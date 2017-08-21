/*第三课
成员对象和封闭类*/

class CTyre{  //轮胎类
private:
 int radius;  //半径
 int width; //宽度
public:
 CTye(int r int w):radius(r),width(w){ } //初始化列表，类似radius=r,width=w。
 };
 class CEngine{     //引擎类
 };
 class CCar{   //汽车类->"封闭类"
 private:
   int price;  //价格
   CTyre tyre; //不同类的对象
   CEngine engine;
 public:
   CCar(int p,int tr,int tw);
 };
 CCar::CCar(int p,int tr,int w):price(p),tyre(tr,w){

 };
 int main(){
   CCar car(20000,17,225);
   //如果CCar类不定义构造函数，则CCar car; error 编译出错 编译器不知道 car.tyre该如何初始化
//car.engine 的初始化没有问题，本身没有参数：用默认构造函数
   return 0;
 }
 /*********************************************************************************/
 /*封闭类例子程序*/
class CTyre{
public:
  CTyre(){cout<<"CTyre contructor"<<endl;}
  ~CTyre(){cout<<"CTyre destructor"<<endl;}
};
class CEngine{
public:
  CEngine(){cout<<"CEngine contructor"<<endl;}
  ~CEngine(){cout<<"CEngine destructor"<<endl;}
};
class CCar{
private:
  CEngine engine;
  CTyre tyre;
public:
  CCar(){cout<<"CCar contructor"<<endl;}
  ~CCar(){cout<<"CCar destructor"<<endl;}
};
int main(){
  CCar car;
  return 0;
}
/*结果
CCar中的成员对象按顺序：
CEngine contructor
CTyre contructor
CCar封闭类自身的构造函数：
CCar contructor
int main 中car要消亡时：
封闭类的析构函数首先被调用：
CCar destructor
按逆序：
CTyre destructor
CEngine destructor
*/
