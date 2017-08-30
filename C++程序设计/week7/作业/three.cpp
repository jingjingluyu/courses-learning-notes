#include<iostream>
#include<iomanip>
using namespace std;
int main(int argc,char const *argv[])
{
int x;
cin>>x;
cout<<setbase(16)<<x<<endl; //oct 八进制 dec 十进制 hex十六进制
cout<<setbase(10)<<setfill('0')<<setw(10)<<x<<endl;
return 0;
}
