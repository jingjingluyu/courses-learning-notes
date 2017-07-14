#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int juzhen[5][5],temp[1][5]={0},n=0,m=0,t=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>juzhen[i][j];
		}
	}
	cin>>n>>m;
	if(n>4||m>4||n<0||m<0)
	cout<<"error"<<endl;
	else
	{
		for(int j=0;j<5;j++)
		{	
			temp[0][j]=juzhen[n][j];
		        juzhen[n][j]=juzhen[m][j];
		        juzhen[m][j]=temp[0][j];
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cout<<setw(4)<<juzhen[i][j];
			}
			cout<<endl;
		}
	}		
return 0;
}
