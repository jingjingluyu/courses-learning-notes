#include<iostream>
using namespace std;
int main()
{
	int n,k,sum;
	int result=0;
	int a[1000];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum=a[i]+a[j];
			if(sum==k)
			result=result+1;
		}
	}
	if(result>0)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
	return 0;
}

	
