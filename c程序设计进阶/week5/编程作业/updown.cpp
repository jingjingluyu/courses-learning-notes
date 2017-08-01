/*以遍历到最长为界限*/
#include<iostream>
using namespace std;
int main()
{
  int a[100][100],x,y;
  int row,col;
  cin>>row>>col;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
      cin>>a[i][j];
  }
   for(int i=0;i<row+col-1;i++)    //i<row+col-1为什么？
   {
     y=i > col-1 ? col-1 : i;   //如果？前的式子成立结果为？后面的值不成立为：后面的值。寻找边界
     x=i-y;                   //这个位置怎么想的？
     while(x<row&&y>=0)   //就把每一斜线位置的元素输出
     {
       cout<<a[x][y]<<endl;
       x++;      //根据每一个斜线位置的坐标官谢
       y--;
     }
   }
 return 0;
 }
