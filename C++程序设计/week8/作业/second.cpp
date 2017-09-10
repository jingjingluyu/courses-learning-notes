#include<iostream>
#include<list>
#include<map>
#include<string>
using namespace std;
void Creatlist(map<int,list<int> > &m,int id)
{
  m[id]=list<int>();
}
void Addnum(map<int,list<int> > &m,int id,int num)
{
  m[id].push_back(num);
}
void Mergelist(map<int,list<int> > &m,int id1,int id2)
{
  m[id1].sort();
  m[id2].sort();
  m[id1].merge(m[id2]);
}
void Uniquenum(map<int,list<int> > &m,int id)
{
  m[id].sort();
  m[id].unique();
}
void Outnum(map<int,list<int> > &m,int id)
{
  m[id].sort();
  list<int>::iterator i;
  for(i=m[id].begin();i!=m[id].end();i++)
  {
    cout<<*i<<" ";
  }
  cout<<endl;
}
int main()
{
  int n;
  cin>>n;
  map<int,list<int> > m;
  for(int i=0;i<n;i++)
  {
    string cmd;
    cin>>cmd;
    if(cmd=="new")
    {
      int id;
      cin>>id;
      Creatlist(m,id);
    }
    else if(cmd=="add")
    {
      int id,num;
      cin>>id>>num;
      Addnum(m,id,num);
    }
    else if(cmd=="merge")
    {
      int id1,id2;
      cin>>id1>>id2;
      Mergelist(m,id1,id2);
    }
    else if(cmd=="unique")
    {
      int id;
      cin>>id;
      Uniquenum(m,id);
    }
    else if(cmd=="out")
    {
      int id;
      cin>>id;
      Outnum(m,id);
    }
  }
  return 0;
}
