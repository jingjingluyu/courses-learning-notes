#include <iostream>
using namespace std;
int main()
{
  int n,x,y;
  cin>>n>>x>>y;
  int m;
  if(y%x==0)
  { 
  m=y/x;
  }
  else
  {
  m=y/x+1;
  }
  if(m>=n)
  {
     n=0;
     cout<<n<<endl;
  }
  else 
  {
    n=n-m;
    cout<<n<<endl;
   }
return 0;
}
 
  
