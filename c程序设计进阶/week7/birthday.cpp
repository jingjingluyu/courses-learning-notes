/*生日相同问题
 description
     在一个有100人的大班级中，存在多个生日相同的同学概率
     非常大。现给出每个学生的学号，出生月日。请列出所有生
     日相同的同学。
 input
    第一行为整数n，表示有n个学生，n<100。
    此后每行包含一个字符串和两个整数，分别表示学生的学号
    （字符串长度小于10）和出生月（1<=m<=12）日（1<=d<=31）。
    学号、月、日之间用一个空格分隔。
Output
    对每组生日相同的同学，输出一行，
    其中前两个数字表示月和日，后面跟着所有在当天出生的学生的学号，
     数字、学号之间都用给一个空格分隔。
    对所有的输出，要求按日期从前到后的顺序输出。
    对生日相同的学号，按输入顺序输出。*/
/*数组统计*/
 struct student
 {
 char ID[10];
 int month;
 int day;
}stu[100];
void main()
{
  int i,j,k,n,flag,cont[100]={0};
  cout<<"how many students ?";
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>stu[i].ID>>stu[i].month>>stu[i].day;
  for(int m=1;m<=12;m++)
    for(int d=1;d<=31;d++)
    {
      flag=0;j=0;
      for(int i=0;i<n;i++)
      {
        if(stu[i].month==m&&stu[i].day==d)
        {
          count[++j]=i;flag++;//count[j]用于记录生日相同同学的学号 
        }
      }
      if(flag>1)
      {
        cout<<m<<" "<<d<<" ";
        for(k=1;k<j;k++)
          cout<<stu[count[k]].ID<<" "<<endl;
      }
    }
}
