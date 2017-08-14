/*第一课*/
/*赋值运算符的重载*/
/*编写一个长度可变的字符串类String
   包含一个char *类型的成员变量
   ->指向动态分配的存储空间
   该存储空间用于存放‘\0’结尾的字符串*/
class String{
private:
  char *str; //指向动态分配的存储空间
public:
  String():str(NULL){} //构造函数，初始化str为NULL
  const char *c_str(){return str;} //返回指针，在外不想改变指针指向的具体的值，
                                   //所以返回值为const类型 char * p=s.c_str()错
  char *operator=(const char *s); //重载函数，若没有这句不需要delete，指针没有指向任何值
  ~String();
   };
//重载’=’->obj="hello"能够成立
char * String::operator=(const char * s){ //指针读取不能修改
  if(str) //判断一下指针是否为空
  delete []str; //不为空delete一下
  if(s){ //s不为NULL才会只想拷贝
    dtr=new char[strlen(s)+1];
    strcpy(str,s);
  }
  else
  str=NULL;
  reutrn str;
}
String::~String(){
  if(str) delete [] str;
};
int main(){
  String s;
  s="Good Luck";  //相当于s.operator=(" ")
  cout<<s.c_str()<<endl;
  //String s2="hello" //这条语句要是不注释掉就会出错,他是初始化语句需要构造函数 string(char *){}
  s="Shenzhou8!";
  cout<<s.c_str()<<endl;
  return 0;
}
/*******************************************************************************/
/*为了避免*/
String & String :: operator=(const String & s){ //引用,
  if(str==s.str)     // 传进来的对象的指针和当前的对象指针所指地址相同
  return *this;     //返回当前对象
  if(str) delete [] str;
  is(s.str){
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
  }
  else
    str=NULL;
  return *this;
}
