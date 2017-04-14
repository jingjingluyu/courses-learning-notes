#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num[6],a,b;
    for(int i=0;i<6;i++)
    {
        cin>>num[i];
    }
    for(int i=0;i<6;i++)
    { 
        if(num[i]%2!=0) 
        {
            a=num[i];
            for(int j=0;j<6;j++)
            { 
                if(a<=num[j]&&num[j]%2!=0)
                {
                    a=num[j];
                }
            }
        }
        else
        {
            b=num[i];
            for(int j=0;j<6;j++)
            { 
                if(b>=num[j]&&num[j]%2==0)
                {
                    b=num[j];
                }
            }
         }
      }
      //cout << "a = " << a << endl;
      //cout << "b = " << b << endl;
      if(a>b)
      cout<<a-b<<endl;
      else
      cout<<b-a<<endl;
      return 0;
}
              
    
