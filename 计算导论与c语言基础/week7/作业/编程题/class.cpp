#include<iostream>
using namespace std;
int main()
{
    double f;
    cin>>f;
    if(f>=95&&f<=100)
    cout<<"1"<<endl;
    if(f>=90&&f<95)
    cout<<"2"<<endl;
    if(f>=85&&f<90)
    cout<<"3"<<endl;
    if(f>=80&&f<85)
    cout<<"4"<<endl;
    if(f>=70&&f<80)
    cout<<"5"<<endl;
    if(f>=60&&f<70)
    cout<<"6"<<endl;    
    if(f<60)
    cout<<"7"<<endl;
    return 0;
}
