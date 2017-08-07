#include<iostream>
using namespace std;
void change(char *p)   //把大写字母都换成小写字母
{
  for(int i=0;*(p+i)!='\0';i++)
  {
    if(*(p+i)>=65 && *(p+i)<=90)
    {
      *(p+i)+=32;
    }
  }
}
void number(char *q,int *r)   //把26个字母依次对应到数组a[0]-a[25]中，并统计出现的次数。
{
  for(int i=0;*(q+i)!='\0';i++)
  {
    if(*(q+i)>='a'&& *(q+i)<='z')
      (*(r+(*(q+i)-97)))++;
  }
}
void second(int *f,char *p)  //找第二多的字母，思路先找到出现次数最多的，在出现次数最多的=0，再找一次最大的就是第二大的
{
  int max=*f,temp=0,second=0;
  for(int j=0;j<26;j++) //找到最大的
  {
    if(max<*(f+j))
    {
        max=*(f+j);
        temp=j;
    }
  }
  for(int j=0;j<26;j++) //看是否有多个最大的，有都设为0
  {
    if(max==*(f+j))
      *(f+j)=0;
  }
  second=*f;
  for(int j=0;j<26;j++)
  {
    if(second<*(f+j))
    {
        second=*(f+j);
    }
  }
  int k=0;
  char str2[26];   //存放第二多的字母
  for(int i=0;i<26;i++)
  {
    if(second==*(f+i))      //把多个第二多的字母存到一个字符数组中
    {
      str2[i]=i+97;
    }
  }

  int str3[26];   //用来存放下标
  for(int i=0;i<26;i++)       //找到先输入的字符
  {
    for(int j=0;*(p+j)!='\0';j++)
    {
      if(str2[i]==*(p+j))
      {
        str3[i]=j;
        break;
      }
      else
        str3[i]=501;
    }
  }
  int indexmin=str3[0],indexa=0;  //找到最小的下标
  for(int i=0;i<26;i++)
  {
     if(indexmin>=str3[i])
     {
       indexmin=str3[i];
       indexa=i;
     }
  }
  cout<<(char)(indexa+97-32)<<"+"<<(char)(indexa+97)<<":"<<second<<endl;
}
int main()
{
  char str[500];
  int a[26];
  cin.getline(str,500);
  change(str);
  number(str,a);
  second(a,str);
  return 0;
}
