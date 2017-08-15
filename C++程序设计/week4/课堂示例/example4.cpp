
/*可变长整形数组*/
int main(){ //要编写可变长整形数组类，使之能如下使用：
  CArray a; //空数组
  for(int i=0;i<5;++i)
    a.push_back(i);  //输入  0 1 2 3 4
    //要用动态分配的内存来存放数组元素，需要一个指针成员变量
  CArray a2,a3; //空数组
  a2=a;
  //要重载“=”
  for(int i=0;i<a.length();++i)
    cout<<a2[i]<<" ";  //输出 0 1 2 3 4
    //a2是对象，a2[i]应该是数组名，要重载 "[]"
  a2=a3; //a2是空的
  for(int i=0;i<a.length();++i)
    cout<<a2[i]<<" ";  //无输出
  cout<<endl;
  a[3]=100;  // 0 1 2 100 4
  CArray a4(a);  //复制构造函数初始化
  //要自己写复制构造函数
  for(int i=0;i<a4.length();++i)
    cout<<a4[i]<<" "; //输出 0 1 2 100 4
  return 0;
}
class CArray{
  int size；//数组元素的个数
  int *ptr;//指向动态分配的数组
public:
  CArray(int s=0); //数组初始化时就已经包含多少个元素了 s代表数组元素的个数
  CArray(CArray & a);
  ~CArray();
  void push_back(int v);//用于在数组尾部添加一个元素v
  CArray & operator=(const CArray & a);//用于数组对象间的赋值
  int length(){return size;}//返回数组元素个数
  int & CArray::operator[](int i)//返回值的类型是什么？是int & 而不是int
  {
    //用以支持根据下标访问数组元素，
    //如n=a[i]和a[i]=4;这样的语句 !!!!!非引用的函数返回值不可作为左值使用 a[i]=4
    return ptr[i];
  }
};
CArray::CArray(int s):size(s) //构造函数
{
   if(s==0)
    ptr=NULL;
   else
    ptr=new int[s];
}
CArray::CArray(CArray & a){ //复制构造函数 深拷贝 如果不写复制构造函数，程序本身会执行浅拷贝出问题
  if(!a.ptr){ //如果a.ptr为空
    ptr=NULL;
    size=0;
    return;
  }
  ptr=new int [a.size];
  memcpy(ptr,a.ptr,sizeof(int)*a.size); //把a.ptr的内容拷贝到ptr，sizeof(int)*a.size长的字节
  size=a.size;
}
CArray::~CArray()
{
  if(ptr)delete[] ptr;
}
CArray & CArray::operator=(const CArray & a) //返回值是CArray &，为了符合”=“惯例，
                                            //返回值是赋值号左边的引用
{
  //赋值号的作用是使”=“左边对象里存放的数组，大小和内容都和右边的对象一样
  if(ptr==a.ptr) //防止a=a这样的赋值导致出错
    return * this;
  if(a.ptr==NULL){
    if(ptr) delete [] ptr;
    ptr=NULL;
    size=0;
    return * this
  }
  if(size<a.size){ //size赋值号左边的 a.size赋值号右边的大小
                  // 如果原有空间够大，就不用分配新的空间.所以只有原有空间不够用再分配新空间
    if(ptr)
      delete [] ptr;
    ptr=new int[a.size];
  }
  memcpy(ptr,a.ptr,sizeof(int)*a.size);//如果原有空间足够用，直接赋值
  size=a.size;
  return * this;
} //CArray & CArray ::operator=(const CArray & a)
void CArray::push_back(int v)
{
  //在数组尾部添加一个元素
  if(ptr){
    int *tmpPtr=new int[size+1];//重新分配空间
    memecpy(tmpPtr,ptr,sizeof(int)*size);//拷贝原数组内容
    delete []ptr;
    ptr=tmpPtr;
  }
  else //数组本来是空的
    ptr =new int[1];
  ptr[size++]=v;//加入新的数组元素
}
