/*约瑟夫问题
 问题描述
  编号为1-N的N个人围坐在一起形成一个圆圈，从第P个人开始，
   依次按照顺时针的方向报数，数到第M的人出列，直到最后剩下一个人。
  请写出一个程序，对于给定的N,P,M，计算并打印出依次出列的人的编号。*/
/*双向循环链表*/
#include<iostream>
using namespace std;
struct Node
{
  int num;
  Node *ahead;
  Node *next;
};
Node *Create(int N);
Node *Search(Node *head,int P);
Node *Release(Node *head,int M);
Node *Create(int N)            //创建包含N个节点的双向循环链表
{
  int n=1;
  Node *node=new Node;
  node->num=n;
  Node *head=node;            //指向第一个节点
  Node *tail=head;          //指向最后一个节点 ,这个有点不清楚
  while(n++<N)
  {
    node=new Node;        //建新节点
    node->num=n;          //赋值
    tail->next=node;      //介入新节点
    node->ahead=tail;
    tail=tail->next;    //尾巴后移
  }
  tail->next=head;      //尾巴处理
  head->ahead=tail;
  return head;
}
Node *Search(Node *head,int P)    //从head开始寻找第P个结点
{
  while(head->num!=P)
  {
    head=head->next;
  }
  return head;
}
Node *Release(Node *head,int M) //释放head开始的第M个结点
{
  int count=1;
  Node *temp=head;
  while(count<M)    //寻找第M个结点
  {
    temp=temp->next;
    count++;
  }
  temp->ahead->next=temp->next;     //移除第M个节点
  temp->next->ahead=temp->ahead;    //移除第M个节点
  cout<<temp->num<<",";
  head=temp->next;              //把开始节点设为下一个点 
  delete temp;                      //释放第M个节点所占内存空间
  return head;
}
int main()
{
  int N,P,M=0;                    //N-起始节点数，P-开始结点
  cin>>N>>P>>M;                //每次释放第M个结点
  Node *head=Create(N);       //创建N个结点的环
  head=Search(head,P);       //找到第P个结点
  while(head->next!=head)    //不断释放第M个元素
  {                          //直到只剩一个元素
    head=Release(head,M);  //释放第M个节点
  }
  cout<<head->num;
  return 0;
}
