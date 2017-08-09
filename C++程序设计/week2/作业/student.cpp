#include<iostream>
using namespace std;
class information
{
  private:
    char name[3];
    int age;
    int id;
    int score;
  public:
    void setname(char a[],int k)
    {
      for(int i=0;i<k;i++)
       name[i]=a[i];
    }
    void setage(int age_)
    {
      age=age_;
    }
    void setid(int id_)
    {
      id=id_;
    }
    void average(int s1,int s2,int s3,int s4)
    {
      score=(s1+s2+s3+s4)/4;
    }
    void out()
    {
      cout<<name<<age<<","<<id<<","<<score<<endl;
    }
};

int main()
{
  information s;
  char c;
  int s1,s2,s3,s4;
  int age,id,k=0;
  char name[10];
  for(int i=0;i<10;i++)
  {
    cin>>name[i];
    k++;
    if(name[i]==',')
      break;
  }
  name[k]='\0';
  cin>>age>>c>>id>>c>>s1>>c>>s2>>c>>s3>>c>>s4;
  s.setname(name,k);
  s.setage(age);
  s.setid(id);
  s.average(s1,s2,s3,s4);
  s.out();
  return 0;
}
