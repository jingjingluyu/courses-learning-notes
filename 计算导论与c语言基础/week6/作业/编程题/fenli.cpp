#include<iostream>
using namespace std;
int main()
{ 
    int n,bai,shi,ge;
    cin>>n;
    bai=n/100;
    n=n-bai*100;
    shi=n/10;
    n=n-shi*10;
    ge=n;
    cout<<bai<<endl;
    cout<<shi<<endl;
    cout<<ge<<endl;
    return 0;
}
