/*问题描述
  给定从公元2000年1月1日开始逝去的天数，请编写程序给出这一天是哪年哪月哪日星期几。
  注意闰年：闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年份是例外，他们不是闰年。
  例如：1700，1800，1900和2100不是闰年，而1600，2000和2400是闰年。
  注意：每个月的天数不一样。

  输入输出要求
  输入多组数据，每组一个正整数，表示从2000年1月1日开始已经过去的天数。
  对输入的每个天数，输出一行，该行包含对应的日期和星期几。格式为：“YYYY-MM-DD DayOfWeek”
  其中”DayOfWeek”必须是：Sunday,Monday,Tuesday,Wednesday,Thursday,Friday and Saturday.
  输入最后一行是-1，不必处理。可以假设结果的年份不会超过9999.

  思路
  days
  计算出星期几
  减掉每年的天数 （year）   1.判断是否是闰年 2.减掉相应天数 直到剩下天数不够一年
  减掉每个月的天数 (month)  减掉每个月的天数，直到剩下天数不够一月
  day
  */

#include<iostream>
using namespace std;
int days;                                   //全局变量
int get_dayofweek();
int get_year();
int get_month(int);
int main()
{
  int year,month,dayofweek;int leap_year;
  char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
  while((cin>>days)&&days!=-1)
  {
    dayofweek=get_dayofweek();
    year=get_year();
    leap_year=(year%4==0&&year%100!=0||year%400==0);
    month=get_month(leap_year);
    cout<<year<<"-"<<month<<"-"<<++days<<“<<week[dayofweek];
  }
  return 0;
}
int get_dayofweek()
{
  int dayofweek;
  dayofweek=days%7;
  return dayofweek;
}
int get_year()
{
  int i=2000,leap_year;
  while(1)
  {
    leap_year=(i%4==0&&i%100!=0||i%400==0);
    if(leap_year==1&&days>=366)
    {
      days=days-366;i++;continue;
    }
    else if(leap_year==0&&days>=365)
    {
      days=days-365;i++;continue;
    }
    else
     break;
  }
  return i;
}
int get_month(int leap_year)
{
  int pmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int rmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
  int j=0;
  while(1)
  {
    if(leap_year==1&&days>=rmonth[j])
    {
      days=days-rmonth[j];
      j++;
    }
    else if(leap_year==0&&days>=pmonth[j])
    {
      days=days-pmonth[j];
      j++;
    }
    else break;
  }
  return ++j;
}
