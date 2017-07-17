#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  double x,y,d,tempd,a[n],b[n];
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    a[i]=x;
    b[i]=y;
  }
  d=pow((a[0]-a[1]),2)+pow((b[0]-b[1]),2);
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      tempd=pow((a[i]-a[j]),2)+pow((b[i]-b[j]),2);
      if(tempd>=d)
      d=tempd;
    }
  }
  d=sqrt(d);
  cout<<fixed<<setprecision(4)<<d<<endl;
  return 0;
}
