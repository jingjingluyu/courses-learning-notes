/*week1 第一课*/
/*函数指针的使用方法*/
#include<stdio.h>
void PrintMin(int a,int b)
{
  if(a<b)
    printf("%d",a);
  else
    printf("%d",b);
}
int main()
{
  void (*pf)(int,int)
  int x=4,y=5;
  pf=PrintMin; //PrintMin赋值给pf;
  pf(x,y); //pf调用所指向的函数；
  return 0;
}
/*****************************************************************/
/*函数指针和qsort库函数
 实例：
 调用qsort库函数，将一个unsigned int数组按照个位数从小到大进行排序。比如8，23，15三个数，
 按个位数从小到大排序，就应该是23，15，8
*/
#include<stdio.h>
#include<stdlib.h>
int MyCompare(const void *elem1,const void *elem2) //将比较的指的地址传给*elem1 *elem2
{
  unsigned int *p1,*p2;
  p1=(unsigned int *)elem1; //"* elem1"非法 强制类型转换
  p2=(unsigned int *)elem2; //"* elem2"非法
  return (*p1%10)-(*p2%10);
}
#define NUM 5
int main()
{
  unsigned int an[NUM]={8,123,11,10,4};
  qsort(an,NUM,sizeof(unsigned int),MyCompare); //函数名字和指针匹配
  for(int i=0;i<NUM;i++)
    printf("%d",an[i]);
  return 0;
}
