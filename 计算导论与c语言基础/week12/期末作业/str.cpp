#include<iostream>
using namespace std;
int main()
{
  char str[13],substr[3];
  int index=0,max=0,len=0;
  while(cin>>str>>substr)
  {
    max=str[0];
    for(int i=0;str[i]!='\0';i++)
    {
      if(max<str[i])
      {
        max=str[i];
        index=i;
      }
      len++;
    }
    for(int i=index+1;i<len;i++)
    str[i+3]=str[i];
    for(int i=0;i<3;i++)
    str[index+i+1]=substr[i];
    cout<<str<<endl;
  }
  return 0;
}
