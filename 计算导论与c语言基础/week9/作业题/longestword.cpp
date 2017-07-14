#include<iostream>
using namespace std;
int main()
{
	int num=0,i=0,j=0,num1=0,wordstar=0,wordstar1=0;	
	char str[500];
	cin.getline(str,500);
	for(i=0;str[i]!='.';i++)
	{      
		if(str[i]!=' ')
		{
		 	num1=num1+1;
		}
		else
		{
			if(num1>num)
			{
				num=num1;  
		 		wordstar=wordstar1;
			}
			wordstar1=i+1;
			num1=0;
		}
	}
	if(num1>num)	
	wordstar=wordstar1;
        for(wordstar;str[wordstar]!=' '&&str[wordstar]!='.';wordstar++)
	cout<<str[wordstar];
	cout<<endl;
	return 0;
}
		
	
	
