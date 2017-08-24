#include <iostream>
using namespace std;
class A {
    private:
        int nVal;
    public:
        void Fun()
        { cout << "A::Fun" << endl; }
        void Do()
        { cout << "A::Do" << endl; }
};
class B:public A {
    public:
        virtual void Do()
        { cout << "B::Do" << endl; }
};
class C:public B {
    public:
    void Do( )
    { cout << "C::Do" <<endl; }
    void Fun()
    { cout << "C::Fun" << endl; }
};
void Call( B & p //开始填的A &p ，这样就直接调用A中的Fun和Do，不会引发多态，类似见example5
  // 在此处补充你的代码
         )  {
    p.Fun();  p.Do();
}
int main()  {
    C c;    Call(c);
    return 0;
}
