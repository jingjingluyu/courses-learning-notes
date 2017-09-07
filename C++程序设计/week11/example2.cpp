/*第一课*/
/*智能指针shared_ptr*/
#include<memory>
#include<iostream>
using namespace std;
struct A{
  int n;
  A(int v=0):n(v){}
  ~A(){cout<<n<<"destructor"<<endl;}
};
int main()
{
  shared_ptr<A>sp1(new A(2)); //sp1托管A(2)
  shared_ptr<A>sp2(sp1); //sp2也托管A（2）
  cout<<"1)"<<sp1->n<<","<<sp2->n<<endl; //输出1）2，2
  shared_ptr<A>sp3;
  A*p=sp1.get(); //p指向A(2)
  cout<<"2)"<<p->n<<endl;//输出2
  sp3=sp1; //sp3也托管A（2）
  cout<<"3)"<<(*sp3).n<<endl; //输出2
  sp1.reset(); //sp1放弃托管A（2）
  if(!sp1) //sp1未托管任何
    cout<<"4)spl is null"<<endl; //会输出
  A * q=new A(3);
  sp1.reset(q); //sp1托管q
  cout<<"5)"<<sp->n<<endl; //输出 3
  shared_ptr<A>sp4(sp1); //sp4托管A（3）
  shared_ptr<A>sp5;
  //sp5.reset(q); 不妥，会导致程序出错
  sp1.reset(); //sp1放弃托管A（3）
  cout<<"befor end main"<<endl;
  sp4.reset(); //sp1放弃托管A（3） ，A（3）无人托管了，自动delete掉，用析构函数
  cout<<"end main"<<endl;
  return 0; //程序结束，会delete掉A（2）
}
/********************************************************/
#include<iostream>
#include<memory>
using namespace std;
struct A{
  ~A(){
    cout<<"~A"<<endl;
  }
}
int main()
{
  A*p=new A();
  shared_ptr<A> ptr(p);
  shared_ptr<A> ptr2;
  ptr2.reset(p); //并不增加ptr中对p的托管计数 不会判断两个p是否相同
  cout<<"end"<<endl;
  return 0;
}
/*输出：
end
~A
~A
之后程序崩溃
因p被delete两次
