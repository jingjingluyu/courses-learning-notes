/*进制转换
 将123转换成等值的二进制数：
 除以2的商（取整）  余数
 123/2=61         1
  61/2=30         1
  30/2=15         0
  15/2=7          1
   7/2=3          1
   3/2=1          1
   1/2=0          1
自下而上收集余数：1111011 */

#include<iostream>
using namespace std;
void convert(int x)
{
  if((x/2)!=0)
  {
    convert(x/2);
    cout<<x%2;   //放在调用之后，因为要倒序输出
  }
  else
    cout<<x;
}
int main()
{
  int x;
  cin>>x;
  convert(x);
  return 0;
}


/**************************************************/

/*汉诺塔问题
64个一个比一个小的金盘从一根柱子上移到另一只柱子上。移动过程中的规则：
每次只移动一只盘子，且大盘子不得落在小盘子上面。
要实现：move（3，A,B,C)
需进行：move（2，A,C,B)
       move  from A to C
       move（2，B,A,C)

要实现：move（n，A,B,C)
需进行：move（n-1，A,C,B)
      move  from A to C
      move（n-1，B,A,C)
      */
#include<iostream>
using namespace std;
void move(int m,char x,char y,char z) //将m个盘子从A经过B移动到C
{
  if(m==1)
  {
    cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl;
  }
  else
  {
    move(m-1,x,z,y)
    cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl; //最后一个大盘子移动
    move(m-1,y,x,z)
  }
}
int main()
{
  int n;
  cout<<"请输入盘子数n=";
  cin>>n;
  cout<<"再三根柱子上移"<<n<<"只盘子的步骤为："<<endl;
  move(n,'A','B','C');
  return 0;
}
