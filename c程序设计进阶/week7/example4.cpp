/*在链表中将值为n的元素删掉*/
linker *dele(student *head;int n)
{
  student *temp,*follow;
  temp=head;
  if(head==NULL)   //head为空，空表的情况
  {
    return(head);
  }
  if(head->num==n)  //第一个节点是要删除的目标
  {
    head=head->next;
    delete temp;
    return(head);
  }
  while(temp!=NULL&&temp->num!=n)//寻找要删除的目标；
  {
    follow=temp;
    temp=temp->next;
  }
  if(temp==NULL) cout<<"not found";//没找到要删除的目标；
  else
  {
    follow->next=temp->next; //删除目标节点
    delete temp;
  }
  return(head);
}
/****************************************************************************/
/*插入链表结点*/
Student *insert(student *head;int n)
{
  student *temp,*unit,*follow;         //插入结点值为n的结点
  temp=head;unit=new student;
  unit->num=n;
  unit->next=NULL;
  if(head==NULL)                      //如果链表为空直接插入
  {
    head=unit;
    return(head);
  }
  while ((temp->next!=NULL)&&（temp->num<n) //寻找第一个不小于n或者结尾的结点temp
  {
    follow=temp;temp=temp->next;
  }
  if(temp==head)                //如果temp为第一个结点
  {
    unit->next=head;head=unit;
  }
  else
  {
    if(temp->next==NULL) temp->next=unit; //如果temp为最后一个结点
    else{follow->next=unit;unit->next=temp;} //如果temp为一个中间节点
  }
  return(head)
}
