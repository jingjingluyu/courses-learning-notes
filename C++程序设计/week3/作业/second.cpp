#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n){v=n;} //初始化
    Sample(Sample&a1){
      v=10;
    }
// 在此处补充你的代码
};
int main() {
    Sample a(5);
    Sample b = a;//相当于Sample b(a),当用一个对象去初始化同类的另一个对象，调用复制构造函数。
    cout << b.v;
    return 0;
}
