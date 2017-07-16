#include<iostream>
using namespace std;
int main()
{
	int cell[100][100],n,num=0,num1,num2,num3,num4;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cell[i][j];
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			num1=cell[i-1][j]-cell[i][j];
			num2=cell[i+1][j]-cell[i][j];
			num3=cell[i][j-1]-cell[i][j];
			num4=cell[i][j+1]-cell[i][j];
			if((num1>=50)&&(num2>=50)&&(num3>=50)&&(num4>=50))
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}			
			













































































































