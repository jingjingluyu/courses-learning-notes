/* 习题课
括号匹配简化版
匹配的括号=（匹配的括号）*n
匹配的括号=（匹配的括号）匹配的括号

A=B*n ==  A=BA

*/
#include<iostream>
using namespace std;
bool b;
int f(char str[],int s)
{
  if(strlen(str)=='s')
    return (b=ture,-1); //返回逗号后面的值，但逗号前面的式子也会执行。
  else
  {
    if(str[s]=='(')
    {
      int n;
      (b,n)=f(str,s+1)
      if(b==false)
        return (b=flase,n)
      else
      {
        if(str[n]==')')
          return f(str,n+1);
        else
          return (b=false,n)
      }
    }
    else
      return(b=ture,s)
  }
}
int main()
{
  cin>>str;
  bool b,int n=f(str,0);
  if(b==true&&n==-1)
    cout<<"yes"<<endl;
  else
  ...
}


/*双递归
F(x+1)=G(x)+1
G(x+1)=F(x)+1

奇数偶数
0是偶数
如果x是偶数，那么x+1是奇数
如果x是奇数，那么x+1是偶数
*/

cin>>x;
if(isEven(x))
 cout<<"ture"<<endl;
 else

isOdd(x)
{
  return isEven(x-1);
}

isEven(x)
{
  return x==0||isOdd(x-1);
}
