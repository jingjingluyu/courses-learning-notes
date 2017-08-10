/*静态成员变量函数*/
class CRectangle
{
private:
  int w,h;
  static int nTotalArea;//静态成员变量
  static int nTotalNumber;
public:
  CRectangle(int w_,int h_);
  ~CRectangle();
  static void PrintTotal();//静态成员函数
}；
/*************************************************/
/*考虑一个需要随知道矩形总数和总面积的图形处理程序
   可以用全局变量来记录总数和总面积
   用静态成员将这两个变量封装进类中，就更容易理解和维护*/
class CRectangle
{
  private:
    int w,h;
    static int nTotalArea;
    static int nTotalNumber;
  public:
    CRectangle(int w_,int h_);
    ~CRectangle();
    static void PrintTotal();
};

CRectangle::CRectangle(int w_,int h_)
{
  w=w_;
  h=h_;
  nTotalNumber++;
  nTotalArea+=w*h;
}
CRectangle::~CRectangle()
{
  nTotalNumber--;
  nTotalArea-=w*h;
}
void CRectangle::PrintTotal()
{
  cout<<nTotalNumber<<","<<nTotalArea<<endl;
}
int CRectangle::nTotalNumber=0;
int CRectangle::nTotalArea=0;
//必须在定义类的文件中对静态成员变量进行一次说明
//或初始化。否则编译能通过，链接不能通过。
int main()
{
  CRectangle r1(3,3),r2(2,2);
  //cout<<CRectangle::nTotalNumber;// Wrong,私有
  CRectangle::PrintTotal();//输出2,13
  r1.PrintTotal();//不意味着PrintTotal作用在r1上面 输出2，13
  return 0;
}
CRectangle::CRectangle(CRectangle & r)
{
  w=r.w;h=r.h;
  nTotalNumber++;
  nTotalArea+=w*h;
}
/****************************************************************/
void CRectangle::Prin ()
{
  cout<<w<<","<<nTotalNumber<<","<<nTotalArea<<endl; //wrong
}
CRectangle::PrintTotal();//解释不通，w到底是属于哪个对象的？
