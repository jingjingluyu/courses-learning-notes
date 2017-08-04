student *create()
{
  student *head,*temp;int num=0;
  head=new student;
  temp=head;
  cin>>num;
  while(num!=-1)
  {
    n++;
    temp->id=num;
    temp->next=new student;
    temp=temp->next;
    cin>>num;
  }
  if(n==0)
    head==NULL;
  else
    temp->next=NULL;
  return head;
}
/****************************************************************************/
/*链表元素的遍历*/
#include<iostream>
using namespace std;
struct student
{
    int id;
    student *next;
};
student *creat();
int main()
{
  student *pointer=create();
  while(pointer->next!=NULL)
  {
    cout<<pointer->id<<endl;
    pointer=pointer->next;
  }
  return 0;
}
