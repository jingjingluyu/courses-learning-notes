/********************************************************/
/*1.类模板从类模板派生*/
template<class T1,class T2>
class A {
  T1 V1;T2 v2;
};
template<class T1,class T2> //由A派生出来 类型参数一样
class B:public A<T2,T1>{
  T1 v3;T2 v4;
};

template<class T>        //由B派生
class C:public B<T,T>{
  T v5;
};
int main(){
  B<int,double>obj1;
  C<int>obj2;
  return 0;
}


/*2.类模板从模板类派生*/
template<class T1,class T2>
class A{T1 v1;T2 v2;}; //类模板A
template<class T>
class B:publicA<int,double>{T v;}; //A实例化为模板类 派生出B类模板
int main(){B<char>obj1;return 0;}  //自动生成两个模板类：A<int,double>和B<char>

/*3.类模板从普通类派生*/
class A{int v1;}; //普通类A

template<class T>
class B:public A{T v;}; //派生出类B

int main(){
  B<char>obj1;
  return 0;
}

/*4.普通类从模板类派生*/
template<class T>
class A{T v1;int n;}; //模板类

class B:public A<int> {double v;}; //T替换成为int实例化
int main(){
  B obj1; 
  return 0;
}
