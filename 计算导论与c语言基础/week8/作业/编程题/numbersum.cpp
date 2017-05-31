#include<iostream>
using namespace std;
int main()
{
    int a,sum=0;
    int num[5];
    cin>>a;
    for(int i=0;i<5;i++)
    cin>>num[i];
    for(int j=0;j<5;j++)
    {
        if(a>num[j])
        {
            sum=sum+num[j];
        }
    }
    cout<<sum<<endl;
    return 0;
}

