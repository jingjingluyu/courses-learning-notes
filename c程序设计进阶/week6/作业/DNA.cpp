#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  cin.get();
  char a[256],b[n][256];
  for(int i=0;i<n;i++)
  {
     cin.getline(a,256);
     for(int j=0;a[j]!='\0';j++)
     {
      switch(a[j])
      {
        case'A':b[i][j]='T';break;
        case'T':b[i][j]='A';break;
        case'G':b[i][j]='C';break;
        case'C':b[i][j]='G';break;
        default:break;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;b[i][j]!='\0';j++)
      cout<<b[i][j];
      cout<<endl;
  }
  return 0;
}
