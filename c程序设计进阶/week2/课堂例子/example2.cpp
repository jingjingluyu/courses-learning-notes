#include<iostream>
using namespace std;
void change(int c,int d)  //不返回任何值，执行后释放掉
{
  c=30;d=50;
}
int main()
{
  int a=3,b=5;
  change(a,b);
  cout<<a<<" "<<b;       //main()中的a,b没被修改
  return 0;
}

/**************************************************************/

/*形参和实参的字母一样，但互不干涉*/
#include<iostream>
using namespace std;
void change(int a,int b)  //不返回任何值，执行后释放掉
{
  a=30;b=50;
}
int main()
{
  int a=3,b=5;
  change(a,b);
  cout<<a<<" "<<b;       //main()中的a,b没被修改
  return 0;
}

/**************************************************************/

#include<iostream>
using namespace std;
void exchange(int a,int b)
{
  int p;
  if(a<b)
  {
    p=a;a=b;b=p;
  }
}
int main()
{
  int a=3,b=5;
  exchange(a,b);
  cout<<a<<" "<<b<<endl;  //仍然是3，5
  return 0;
}
