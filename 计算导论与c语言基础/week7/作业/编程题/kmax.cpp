#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int n,k; 
    int a[n],b[k];
    cin>>n;
    cin>>k;
   
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }   
    for(int j=0;j<k;j++)
    {
        b[j]=a[j];
    }
    for(int i=k;i<n;i++)
    {   
        for(int j=0;j<k;j++)
        {
            
            if(a[i]>b[j])
            {
               int min=b[0];
               int num=0;
                for(int l=1;l<k;l++)
                {
                    if(min>b[l])
                    {
                        min=b[l];
                        num=l;
                    }
                }
                b[num]=a[i];
                break;           
            }
        }
    }
    int min=b[0];       
    int minnum=0;
    for(int l=1;l<k;l++)
    {
        
        if(min>b[l])
        {
            min=b[l];
            minnum=l;
        }
    }
    cout<<min<<endl;
    return 0;
}
        






        

    
