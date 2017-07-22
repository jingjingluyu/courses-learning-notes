#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  int year=0,month=0,day=0;
  char dummy;                  
  cin>>year>>dummy>>month>>dummy>>day;
  if(year%4==0&&year%100!=0||year%400==0)
  {
    if(month==2)
    {
      if(day==29)
      {
        day=1;month++;
      }
    }
  }
  else
  {
    if(month==2)
    {
      if(day==28)
      {
        day=1;month++;
      }
    }
  }
  if(month==12)
  {
      if(day==31)
      {day=1;month=1;year++;}
  }
  else if(month==1||month==3||month==5||month==7||month==8||month==10)
  {
      if(day==31)
      {day=1;month++;}
      else
      day++;
  }
  else if(month==4||month==6||month==9||month==11)
  {
    if(day==30)
    {day=1;month++;}
    else
    day++;
  }
  cout<<year<<"-";
  cout<<setfill('0')<<setw(2)<<month<<"-";
  cout<<setfill('0')<<setw(2)<<day<<endl;
  return 0;
}
