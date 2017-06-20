#include<iostream>
using namespace std;
int main()
{
	int num=10,sum=0,result=0,a[100],n,m=0;
	cin>>n;
	for(int i=0; ;i++)
	{
		sum=num%10+(num-num%10)/10;
		//cout<<sum<<endl;
		result=num%sum;
		if(result==0)
		{
			a[m]=num;
			m=m+1;
		}
		//cout<<m<<endl;
		num=num+1;
		if(num>n)
		break;
	}
	for(int i=0;i<m;i++)
        {
		cout<<a[i]<<endl;
	}	
	return 0;
}
