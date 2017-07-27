/*其实是括号匹配问题*/



#include<iostream>
using namespace std;
int game(char str[],int num)
{
    char boy=str[0];     //让boy为第一个字符
    if(str[num]!=boy)   //判断第num个字符是否为boy，不是则为girl字符。
      return num;       //返回女生下标，退出递归。
    else
    {
      int girl=game(str,num+1);  //新开辟一个内存，继续往下查看字符，直到有女生字符，返回num值
      cout<<num<<" "<<girl<<endl;  //新的内存中num变了，可返回后元内存中的num没变。保存了之前的num
      return game(str,girl+1);
    }
}
int main()
{
  char str[100];
  cin>>str;
  game(str,0);
  return 0;
}
