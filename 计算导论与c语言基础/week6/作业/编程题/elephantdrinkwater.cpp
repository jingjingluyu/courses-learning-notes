#include<iostream>
#define PI 3.1415926
using namespace std;
int main()
{
    int h,r,n,v;
    cin>>h>>r;
    v=PI*r*r*h;
    if(20000%v==0)
    {  
        n=20000/v;
        cout<<n<<endl;
    }
    else
    {
        n=20000/v+1;
        cout<<n<<endl;
    }
    return 0;
}
