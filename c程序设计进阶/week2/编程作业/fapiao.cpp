#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  int id,num;
  char classes;
  double money=0,allcost[3]={0},costa=0,costb=0,costc=0;
  for(int i=0;i<3;i++)
  {
    cin>>id>>num;
    for(int j=0;j<num;j++)
    {
      cin>>classes>>money;
      if(classes=='A')
        costa=costa+money;
      if(classes=='B')
        costb=costb+money;
      if(classes=='C')
        costc=costc+money;
      allcost[id-1]=allcost[id-1]+money;
    }
  }
  for(int i=0;i<3;i++)
  {
    cout<<i+1<<" "<<fixed<<setprecision(2)<<allcost[i]<<endl;
  }
  cout<<'A'<<" "<< fixed<<setprecision(2)<<costa<<endl;
  cout<<'B'<<" "<< fixed<<setprecision(2)<<costb<<endl;
  cout<<'C'<<" "<< fixed<<setprecision(2)<<costc<<endl;
  return 0;
}
