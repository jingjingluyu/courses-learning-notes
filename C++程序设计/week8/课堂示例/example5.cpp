/*第四课*/
/*函数对象*/
class CMyAverage{
public:
double operator()(int a1,int a2,int a3){
   return(double)(a1+a2+a3)/3;
  }
};
CMyAverage average; //函数对象
cout<<average(3,2,3); //相当于average.operator()(3,2,3)  一般只有函数才可以后面加括号，average是对象 称为函数对象
/******************************************************************************************************/
/*函数对象的应用*/
/*Dev C++中的Accumulate源代码1：*/
template<typename _Inputlterator,typename _Tp>
 _Tp accumulate(_Inputlterator _first,_Inputlterator _last,_Tp _init) //_init初始值
 {
   for(;_first!=_last;++_first)
    _init=_init+*_first; //进行累加
  return _init;
 }
 //typename 等价于class

 /*Dev C++中的Accumulate源代码2：*/
 template<typename _Inputlterator,typename _Tp,typename _BinaryOperation>
 _Tp accumulate(_Inputlterator _first,_Inputlterator _last,_Tp _init,_BinaryOperation _binary _op)
 {
   for(;_first!=_last;++_first)
    _init=_binary_op(_init,*_first); //init与first运算 结果 付给初始值init
  return _init;
 }
 //调用accumulate时，和_binary_op对应的实参可以是个函数或函数对象或函数指针
 /******************************************************************************************************/
 /*函数对象的应用示例*/
 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<numeric>
 #include<function>
 using naemspace std;
 int sumSquares(int total,int value)
 {return total+value*value;}
 template<class T>
 void PrintInterval(T first,T last)  //函数模板
 { //输出区间[first,last)中的元素
   for(;first!=last;++first)
    cout<<*first<<" ";
   cout<<endl;
 }
 template<class T>
 class SumPowers //类模板
 {
 private:
   int power;
 public:
   SumPowers(int p):power(p){}
   const T operator()(const T & total,const T & value)
   {// 计算 value的power次方，加到total上
     T v=value;
     for(int i=0;i<power-1;++1)
      v=v*value;
     return total+v;
   }
 };
 int main()
 {
   const int SIZE=10;
   int a1[]={1,2,3,4,5,6,7,8,9,10};
   vector<int> v(a1,a1+SIZE);
   cout<<"1)";PrintInterval(v.begin(),v.end());
   int result=accumulate(v.begin(),v.end(),0,SumSquares); //求平方和
   cout<<"2)平方和:"<<result<<endl;
   result=accumulate(v.begin(),v.end(),0,SumPowers<int>(3)); //求立方和
   cout<<"3)立方和:"<<result<<endl;
   result=accumulate(v.begin(),v.end(),0,SumPowers<int>(4)); //四次方和
   cout<<"4)4次方和:"<<result;
   return 0;
 }
// 由int result=accumulate(v.begin(),v.end(),0,SumSquares); //求平方和
//实例化出：
int accumulate(vector<int>::iterator first,vector<int>::iterator last,int init,int(*op)(int,int))//int(*op)(int,int)指针op与函数名字对应，有两个参数
{
  for(;first!=last;++first)
    init=op(init,*first);
  return init;
}
//accumulate(v.begin(),v.end(),0,SumPowers<int>(3));
//实例化出：
int accumulate(vector<int>::iterator first,vector<int>::iterator last,int init,SumPowers<int> op)
{
  for(;first!=last;++first)
    init=op(init,*first);
  return init;
}
