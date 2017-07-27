/*逆波兰表达式
题目描述
 逆波兰表达式是一种把运算符前置的算数表达式：
   如 2 + 3 的逆波兰表达法为 + 2 3
   如(2 +3)* 4的逆波兰表示法为 * + 2 3 4
 编写程序求解任一仅包含+ - * /四个运算符的逆波兰表达式的值。
 输入： * + 11.0 12、0 +24.0 35.0   (11.0+12.0)*(24.0+35.0)
 输出：1357.0

  * / + 12 36 + 1 3 - 15 8
[     notation             ]
 *[  notation()][notation()]     =    notation() * notation()
  / [notation()][notation()]     =    notation() / notation()
   +[notation()][notation()]     =    notation() + notation()
                                      notation() - notation()
其他字符：将独到的字符串解释为 数*/

#include<iostream>
using namespace std;
double notation()
{
  char str[10];
  cin>>str;
  switvh(str[0])
  {
    case '+':return notation()+notation();
    case '-':return notation()-notation();
    case '*':return notation()*notation();
    case '/':return notation()/notation();
    default:return atof(str);   //字符串转换成数字
  }
}
int main()
{
  cout<<notation();
  return 0;
}

/*（（12+36）/ (1+3))*(15-8)=84
 (  notation ) * (notation)
 ((notation()/(notation())) * (()-())
 ((12)+(36)) ((1)+(3))
 */
