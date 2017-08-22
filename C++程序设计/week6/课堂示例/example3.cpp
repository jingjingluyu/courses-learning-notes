/*第二课 几何形体处理程序*/
/*几何形体处理程序：输入若干个几何形体的参数，要求按面积排序输出。输出时要指明形状。
  Input:
    第一行是几何形体数目n(不超过100)。下面有n行，每行以一个字母c开头
    若c是‘R’，则代表一个矩形，本行后面跟着两个整数，分别是矩形的宽和高；
    若c是'C'，则代表一个圆，本行后面跟着一个整数代表半径
    若c是‘T’，则代表一个三角形，本行后面跟着三个整数，代表三条边的长度

  Output:
     按面积从小到大依次数出每个几何形体的种类及面积。每行一个几何形体，输出格式为：
      几何形体名称：面积
  Sample Input:
     3
     R 3 5
     C 9
     T 3 4 5
  Sample Output:
     Triangle：6
     Rectangle:15
     Circle:254.34*/

#include<iosream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class CShape //共同拥有的属性 设为基类
{
public:
  vritual double Area()=0; //纯虚函数数 没有函数体
  vritual void PrintInfo()=0;  //输出
};
class CRectangle:public CShape
{
public:
  int w,h;
  virtual double Area();
  virtual void PrintInfo();
};
class CCircle:public CShape{
public:
  int r;
  virtual double Area();
  virtual void PrintInfo();
};
class CTriangle:public CShape{
public:
  int a,b,c;
  virtual double Area();
  virtual void PrintInfo();
};
double CRectangle::Area(){
  return w*h;
}
void CRectangle::PrintInfo(){
  cout<<"Rectangle:"<<Area()<<endl;
};
double CCircle::Area(){
  return 3.14*r*r;
}
void CCircle::PrintInfo(){
  cout<<"Circle:"<<Area()<<endl;
}
double CTriangle::Area(){
  double p=(a+b+c)\2.0;  //海伦公式
  return sqrt(p*(p-a)*(p-b)*(p-c));
}
void CTriangle::PrintInfo(){
  cout<<"Triangle:"<<Area()<<endl;
}
CShape *pShapes[100]; //基类指针数组，数组中每一个元素都是基类指针，可以指向不同的几何形体，存放各种类型的地址
int MyCompare(const void *s1,const void *s2);

int main()
{
  int i;int n;
  CRectangle *pr;
  CRectangle *pc;
  CRectangle *pt;
  cin>>n;
  for(i=0;i<n;i++){
    char c;
    cin>>c;
    switch(c){
      case'R':
        pr=new CRectangle();
        cin>>pr->w>>pr->h;
        pShapes[i]=pr;
        break;
      case'C':
        pc=new CCircle();
        cin>>pc->r;
        pShapes[i]=pc;
        break;
      case'T':
        pt=new CTriangle();
        cin>>pt->a>>pt->b>>pt->c;
        pShapes[i]=pt;
        break;
    }
  }
  qsort(pShapes,n,size(CShape*),MyCompare); //比较大小
  for(i=0;i<n;i++)
    pShapes[i]->PrintInfo();//多态
}
int MyCompare(const void *s1,const void *s2) //pShapes中的元素copy过来
{
  double a1,a2;
  CShape* * p1; //s1,s2是void*,不可写”*s1“ 来取得  s1指向的内容？？
  CShape* * p2;
  p1=(CShape**)s1; //强制类型转换 s1,s2指向pShapes数组中的元素，数组元素的类型是CShape*
  p2=(CShape**)s2; //故p1,p2都是指向指针的指针，类型为CShape**
  a1=(*p1)->Area(); //*p1的类型是Cshape*，是基类指针，故此句为多态
  a2=(*p2)->Area();
  if(a1<a2)
    return -1;
  else if(a2<a1)
    return 1;
  else
    return 0;
}
/*如果添加新的几何形体，比如五边形，则只需要从CShape派生出CPentagon，以及在main中
  switch语句中增加一个case，其余部分不变*/
