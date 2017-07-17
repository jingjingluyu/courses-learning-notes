#include<iostream>
using namespace std;
int main()
{
  int a;
  while(cin>>a)
  {
    if((a%3==0)&&(a%5==0)&&(a%7==0))
    cout<<3<<' '<<5<<' '<<7<<endl;
    if((a%3!=0)&&(a%5!=0)&&(a%7!=0))
    cout<<"n"<<endl;
    if((a%3==0)&&(a%5==0)&&(a%7!=0))
    cout<<3<<' '<<5<<endl;
    if((a%3==0)&&(a%5!=0)&&(a%7==0))
    cout<<3<<' '<<7<<endl;
    if((a%3!=0)&&(a%5==0)&&(a%7==0))
    cout<<5<<' '<<7<<endl;
    if((a%3==0)&&(a%5!=0)&&(a%7!=0))
    cout<<3<<endl;
    if((a%3!=0)&&(a%5==0)&&(a%7!=0))
    cout<<5<<endl;
    if((a%3!=0)&&(a%5!=0)&&(a%7==0))
    cout<<7<<endl;
  }
  return 0;
}
