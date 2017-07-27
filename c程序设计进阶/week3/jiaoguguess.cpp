#include<iostream>
using namespace std;
int even(int n);
int odd(int n);
int even(int n)
{
  int result=0;
  result=n/2;
  cout<<n<<"/2="<<result<<endl;
  n=result;
  if(result==1)
    return 1;
  else if(result%2==0&&result!=1)
    return even(n);
  else if(result%2!=0)
    return odd(n);
}
int odd(int n)
{
  int result=0;
  result=n*3+1;
  cout<<n<<"*3+1="<<result<<endl;
  n=result;
  if(result%2!=0)
    return odd(n);
  else if(result!=1&&result%2==0)
   return even(n);
  else if(result==1)
    return 1;
}
int main()
{
  int n,end=0;
  cin>>n;
  if(n%2==0)
    end=even(n);
  if(n%2!=0&&n!=1)
    end=odd(n);
  if(end==1||n==1)
    cout<<"End"<<endl;
  return 0;
}
