#include <iostream>
using namespace std;
class A {
public:
    int val;
    A(int n=0){val=n;}   //构造函数，初始化 n=0;表示缺省构造函数，也就是当构造函数里什么都没有时，相当于传入参数0 A(){} 
    int & GetObj()
    {
      return val;
    }
};
int main()
{
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;     //因为a.GetObj()可以直接赋值而且成功改变了val的值，说明GetObj()是一个引用
    cout << a.val << endl;
    return 0;
}
