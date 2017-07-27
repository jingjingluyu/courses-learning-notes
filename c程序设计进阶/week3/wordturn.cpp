#include<iostream>
using namespace std;
void turn(char str[],int num);
void turn(char str[],int num)
{
  if(str[num]=='\0')
  {
    cout<<endl;
    return;
  }
  else
  {
    if(str[num]==' ')
    {
      cout<<' ';
      return turn(str,num+1);
    }
    else
    {
      int i=num;
      int next;
     for( ;str[i]!=' '&&str[i]!='\0';i++)
     {

     }
     next=i;
     for(i=i-1;i>=num;i--)
      cout<<str[i];
     return turn(str,next);
    }
  }
}

int main()
{
  char str[500];
  cin.getline(str,500);
  turn(str,0);
  return 0;
}
