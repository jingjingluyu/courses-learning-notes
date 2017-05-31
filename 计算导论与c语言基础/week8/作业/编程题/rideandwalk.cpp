#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mi[n];
    double timeb,timew;
    for(int i=0;i<n;i++)
    {
        cin>>mi[i];
    }
    for(int i=0;i<n;i++)
    {
        timeb=(double)50+(double)mi[i]/3.0;
        timew=(double)mi[i]/1.2;
        if(timeb>timew)
            cout<<"Walk"<<endl;
        else if(timeb<timew)
            cout<<"Bike"<<endl;
        else
            cout<<"All"<<endl;
    }
    return 0;
}
