#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big  {
public:
    int v; Base b;
    Big(int a):v(a),b(a){}//初始化
    Big( Big & d):v(d.v),b(d.v){} //复制构造函数
// 在此处补充你的代码
};
int main()  {
    Big a1(5); //初始化
    Big a2 = a1; //复制构造函数
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}
