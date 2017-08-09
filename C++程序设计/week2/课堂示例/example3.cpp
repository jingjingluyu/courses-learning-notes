/*类*/
/*写一个程序，输入矩形的宽和高，输出面积和周长
  矩形的属性——宽和高
      两个变量，分别代表宽和高
  对矩形的操作
      设置宽和高
      计算面积
      计算周长*/
/*封装 举行类
  int w;
  int h; //成员变量
  Area();
  Perimeter();
  Init(...);     //成员函数
  类的成员：成员变量 成员函数*/

class CRectangle
{
  public:  //访问范围说明符
    int w,h;
  void Init(int w_,int h_)
  {
    w=w_;
    h=h_;
  }
  int Area()
  {
    return w*h;
  }
  int Perimeter()
  {
    return 2*(w+h);
  }
}; //注意；
int main()
{
  int w,h;
  CRectangle r;  //r是一个对象
  cin>>w>>h;
  r.Init(w,h);
  cout<<r.Area()<<endl<<r.Perimeter();
  return 0;
}

/*************************************************************/

/*类成员访问范围*/
class CEployee
{
  private:
    char szName[30];  //名字
  public:
    int salary;
    void setName(char * name);   //类的成员函数内部
    void getName(char * name);
    void averageSalary(CEmployee e1,CEmployee e2);
};
void CEmployee::setName(char *name)
{
  strcpy(szName,name); //ok
}
void CEmployee::getName(char *name)
{
  strcpy(name,szName); //ok
}

void CEmployee::averageSalary(CEmployee e1,CEmployee e2)
{
  salary=(e1.salary+e2.salary)/2;
}
int main()
{
  CEmployee e;
  strcpy(e.szName,"Tom1234567889"); //编译错误，不能访问私有成员
  e.setName("Tome"); //ok
  e.salary=5000;  //ok
  return 0;
}
