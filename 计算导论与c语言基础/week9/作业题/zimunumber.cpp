#include<iostream>
using namespace std;
int main()
{
	char s[80];
	int a=0,e=0,i=0,o=0,u=0;
	cin.getline(s,80);
	for(int j=0;s[j]!='\0';j++)
	{
		if(s[j]=='a')
		a=a+1;
		else if(s[j]=='e')
		e=e+1;
		else if(s[j]=='i')
		i=i+1;
		else if(s[j]=='o')
		o=o+1;
		else if(s[j]=='u')
		u=u+1;
	}
	cout<<a<<' '<<e<<' '<<i<<' '<<o<<' '<<u<<endl;
	return 0;
}
