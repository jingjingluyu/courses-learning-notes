/*第三课*/
/*priority_queue*/
#include<queue>
#include<iostream>
using namespace std;
int main()
{
  priority_queue<double> priorities;
  priorities.push(3.2);
  priorities.push(9.8);
  priorities.push(5.4);
  while(!priorities.empty()){
    cout<<priorities.top()<<" ";
    priorities.pop();
  }
  return 0;
}
