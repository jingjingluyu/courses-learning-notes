#include<iostream>
using namespace std;
int main()
{
  int n,num=0,m;
  cin>>n;
  char domitory[n][n],tempdo[n][n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>domitory[i][j];
      tempdo[i][j]=domitory[i][j];
    }
  }
  cin>>m;
  for(int d=2;d<=m;d++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(domitory[i][j]=='@')
        {
          if(i==0)
          {
            if(j==0)
            {
              if(domitory[i][j+1]!='#'&&domitory[i][j+1]!='@')
                {tempdo[i][j+1]='@';}
              if(domitory[i+1][j]!='#'&&domitory[i+1][j]!='@')
                {tempdo[i+1][j]='@';}
            }
            else if(j==(n-1))
            {
              if(domitory[i][j-1]!='#'&&domitory[i][j-1]!='@')
                {tempdo[i][j-1]='@';}
              if(domitory[i+1][j]!='#'&&domitory[i+1][j]!='@')
                {tempdo[i+1][j]='@';}
            }
            else
            {
              if(domitory[i][j-1]!='#'&&domitory[i][j-1]!='@')
                {tempdo[i][j-1]='@';}
              if(domitory[i][j+1]!='#'&&domitory[i][j+1]!='@')
                {tempdo[i][j+1]='@';}
              if(domitory[i+1][j]!='#'&&domitory[i+1][j]!='@')
                {tempdo[i+1][j]='@';}
            }
          }
        else if(i==(n-1))
        {
          if(j==0)
          {
            if(domitory[i][j+1]!='#'&&domitory[i][j+1]!='@')
              {tempdo[i][j+1]='@';}
            if(domitory[i-1][j]!='#'&&domitory[i-1][j]!='@')
              {tempdo[i-1][j]='@';}
          }
          else if(j==(n-1))
          {
            if(domitory[i][j-1]!='#'&&domitory[i][j-1]!='@')
              {tempdo[i][j-1]='@';}
            if(domitory[i-1][j]!='#'&&domitory[i-1][j]!='@')
              {tempdo[i-1][j]='@';}
          }
          else
          {
            if(domitory[i][j-1]!='#'&&domitory[i][j-1]!='@')
              {tempdo[i][j-1]='@';}
            if(domitory[i][j+1]!='#'&&domitory[i][j+1]!='@')
              {tempdo[i][j+1]='@';}
            if(domitory[i-1][j]!='#'&&domitory[i-1][j]!='@')
              {tempdo[i-1][j]='@';}
          }
        }
        else
        {
          if(j==0)
          {
            if(domitory[i-1][j]!='#'&&domitory[i-1][j]!='@')
              {tempdo[i-1][j]='@';}
            if(domitory[i][j+1]!='#'&&domitory[i][j+1]!='@')
              {tempdo[i][j+1]='@';}
            if(domitory[i+1][j]!='#'&&domitory[i+1][j]!='@')
              {tempdo[i+1][j]='@';}
          }
          else if(j==(n-1))
          {
            if(domitory[i-1][j]!='#'&&domitory[i-1][j]!='@')
              {tempdo[i-1][j]='@';}
            if(domitory[i][j-1]!='#'&&domitory[i][j-1]!='@')
              {tempdo[i][j-1]='@';}
            if(domitory[i+1][j]!='#'&&domitory[i+1][j]!='@')
              {tempdo[i+1][j]='@';}
          }
          else
          {
            if(domitory[i-1][j]!='#'&&domitory[i-1][j]!='@')
              {tempdo[i-1][j]='@';}
            if(domitory[i][j-1]!='#'&&domitory[i][j-1]!='@')
              {tempdo[i][j-1]='@';}
            if(domitory[i][j+1]!='#'&&domitory[i][j+1]!='@')
              {tempdo[i][j+1]='@';}
            if(domitory[i+1][j]!='#'&&domitory[i+1][j]!='@')
              {tempdo[i+1][j]='@';}
           }
         }
       }
     }
   }
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     domitory[i][j]=tempdo[i][j];
   }
 }
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<n;j++)
   {
     if(domitory[i][j]=='@')
       num++;
     }
  }
  cout<<num<<endl;
return 0;
}
