/*已知n,求n！*/

#include<iostream>
using namespace std;
int fact(int n)
{
  if(n==1)
    return 1;
  else
    return n*fact(n-1);
}
int main()
{
  cout<<fact(4)<<endl;
  return 0;
}



/***********************************************/
/*深入理解递归的过程*/
#include<iostream>
using namespace std;
int recur()
{
  char c;
  c = cin.get()   //从键盘读入，可以把空格回车都读入，不能跳过输入结束标志
  if(c!='\n')
   recur()
  cout<<c;
  return 0;
}
int main()
{
  recur()
  return 0;
}

/*main()——recur1-a-recur2-b-recur3-c-recur4—'\n'  读入
                                           |
  main()——recur1-a-recur2-b-recur3-c-recur4-'\n'  输出*/

/*结果：输入：abc换行
     输出：换行
          cba*/
          
