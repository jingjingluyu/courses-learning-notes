#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,m=0,l=0,h=0,k=0;
    double b,bb,bbb,bbbb;
    cin>>n;
    int age[100];
    for(int i=0;i<n;i++)
    cin>>age[i];
    for(int i=0;i<n;i++)
    {       
        if(age[i]>=1&&age[i]<=18)
        { 
            m=m+1;    
        }       
        if(age[i]>=19&&age[i]<=35)
        {            
            l=l+1;
        }
        if(age[i]>=36&&age[i]<=60)
        {           
            h=h+1;
        }
        if(age[i]>60)
        {
            k=k+1;
        }
    }
    b=((double)m)*100/n;
    cout<<"1-18: "<<fixed<<setprecision(2)<<b<<"%"<<endl;
    bb=(double)l*100/n;
    cout<<"19-35: "<<fixed<<setprecision(2)<<bb<<"%"<<endl;
    bbb=(double)h*100/n;
    cout<<"36-60: "<<fixed<<setprecision(2)<<bbb<<"%"<<endl;
    bbbb=(double)k*100/n;
    cout<<"60-: "<<fixed<<setprecision(2)<<bbbb<<"%"<<endl;
    return 0;
}

