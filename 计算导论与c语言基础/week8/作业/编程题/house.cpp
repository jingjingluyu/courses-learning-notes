#include<iostream>
using namespace std;
int main()
{
 	double n,k,house,money;
	int m;
	while(cin>>n>>k)
	{
		house=200;
		for(int i=1; ;i++)
		{
			if(i>1)
			house=house*(1+k*0.01);
			money=n*i;
                	if(money>house && i<=20)
			{
				m=i;				
				cout << m << endl;
				break;
			}	
			else if(i>20)
			{
				cout << "Impossible" << endl;
				break;	
			}
		}
	}
	return 0;
}  
