/*第二课*/
/*函数模板*/
template<class T>
void Swap(T &x,T & y)
{
    T tmp=x;
    x=y;
    y=tmp;
}
int main(){
  int n=1,m=2;
  Swap(n,m);  //编译器自动生成 void Swap(int &,int &)函数
  double f=1.2,g=2.3;
  Swap(f,g); //编译器自动生成 void Swap(double &,double &)函数
  return 0;
}
/***************************************************************/
/*求数组最大元素的 MaxElement 函数模板*/
template<class T>
T MaxElement(T a[],int size) //size是数组元素个数
{
  T tmpMax=a[0];
  for(int i=1;i<size;++i)
  {
    if(tmpMax<a[i])
    tmpMax=a[i];
  }
  return tmpMax;
}
/***************************************************************/
/*函数模板可以重载*/
/*例，下面两个模板可以同时存在：*/
template<class T1,class T2>
void print(T1 arg1,T2 arg2)
{
  cout<<arg1<<" "<<arg2<<endl;
}
template<class T>
void print(T arg1,T arg2)
{
  cout<<arg1<<" "<<arg2<<endl;
}
/***************************************************************/
/*函数模板调用顺序*/
template<class T>
T Max(T a,T b){
  cout<<"Template Max 1"<<endl;
  return 0;
}
template<class T,class T2>
T Max(T a,T2 b){
  cout<<"Template Max 2"<<endl;
  return 0;
}
double Max(double a,double b){
  cout<<"MyMax"<<endl;
  return 0;
}
int main(){
  int i=4,j=5;
  Max(1.2,3.4); //调用 Max(double,double)
  Max(i,j); //调用第一个T Max(T a ,T b)模板生成的函数
  Max(1.2,3); //调用第二个 T Max(T a,T2 b)模板生成的函数
  return 0;
}
//结果：MyMax Template Max 1 Template Max 2
/***************************************************************/
/*赋值兼容原则引起函数模板中类型参数的二义性*/
template<class T>
T myFunction(T arg1,T arg2)
{
  cout<<arg1<<" "<<arg2<<"\n";
  return arg1;
}
....
myFunction(5,7); //ok:replace T with int
myFunction(5.8); //ok:replace T with double
myFunction(5,8.4); //error:replace T with int or double? 二义性

/*可以在函数模板中使用多个类型参数，可以避免二义性*/
template<class T1,class T2>
T myFunction(T1 arg1,T2 arg2)
{
  cout<<arg1<<" "<<arg2<<"\n";
  return arg1;
}
