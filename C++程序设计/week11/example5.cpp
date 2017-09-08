/*第二课*/
/*无序容器（哈希表）*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
  unordered_map<string,int>turingWinner; //图灵奖获奖名单 turingWinner容器记录
  turingWinner.insert(make_pair("Dijkstra",1972));
  turingWinner.insert(make_pair("Scott",1976));
  turingWinner.insert(make_pair("Wilkes",1976));
  turingWinner.insert(make_pair("Hamming",1968));
  turingWinner["Ritchie"]=1983;//如果turingWinner中没有关键字是Ritchie，就有新的元素被插入进去
  string name;
  cin>>name; //输入姓名
  unordered_map<string,int>::iterator p=turingWinner.find(name);
  //据姓名查获奖时间
  if(p!=turingWinner.end())
    cout<<p->second;
  else
    cout<<"Not Found"<<endl;
  return 0;
}
//哈希表插入和查询的时间复杂度几乎是常数
/*********************************************************************************/
/*正则表达式*/
#include<iostream>
#include<regex>//使用正则表达式须包含此文件
using namespace std;
int main()
{
  regex reg("b.?p.*k"); //regex是正则表达式类 reg对象，对其初始化，代表了一个模式
                       //b开头 .任意字符 ?任意字符出现0次或1次 p在b和p之间可以有0个或1个字符
                       //.任意字符 *刚刚出现的字符可以出现0次或任意多次 p和k之间可以出现相同的字符任意多次或没有
  cout<<regex_match("bopggk",reg)<<endl; //输出1，表示匹配成功
  cout<<regex_match("boopgggk",reg)<<endl; //输出0，表示匹配失败
  cout<<regex_match("b pk",reg)<<endl; //输出1，表示匹配成功
  regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
  //  \\d:\d 数字0-9  {3}：出现三次 （）：项 []+:字母出现一次或若干次组成  .:可以出现任意字符
  //  N/A就是N/A  \\s:空格 \\1:与第一项一模一样
  string correct="123Hello N/A Hello";
  string incorrect="123Hello 12 hello";
  cout<<regex_match(correct,reg2)<<endl; //输出1，表示匹配成功
  cout<<regex_match(incorrect,reg2)<<endl; //输出0，表示匹配失败
}
/*********************************************************************************/
