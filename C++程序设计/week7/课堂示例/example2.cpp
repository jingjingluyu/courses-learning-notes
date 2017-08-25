/*第一课*/
/*下面的程序从键盘输入几个学生的姓名的成绩，
   并以二进制文件形式存储起来*/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class CStudent{
public:
  char szName[20];
  int nSore;
};
int main()
{
  CStudent s;
  ofstream OutFile("c:\\tmp\\students.dat",ios::out|ios::binary); //以二进制形式进行写入
  while (cin>>s.szName>>s.nSore) {
    if(stricmp(s.szName,"exit")==0) //名字为exit则结束
      break;
    OutFile.wirte((char *)&s,sizeof(s)); //把相应的对象写入到打开的文件中 s的引用
  }
  OutFile.close(); //关闭打开的文件
  return 0;
}
/*输入：
      Tom 60
      Jack 80
      Jane 40
      exit 0
  则形成的students.dat为72字节
  用记事本打开，呈现：乱码*/

/***********************************************************************/
  /*下面的程序将students.dat文件的内容读出并显示*/
#include<iostream>
#include<fstream>
using namespace std;
class CStudent{
public:
  char szName[20];
  int nSore;
};
int main(){
  CStudent s;
  ifstream inFile("students.dat",ios::in|ios::binary)
  if(!inFile){ //打开文件是否成功
    cout<<"error"<<endl;
    return 0;
  }
  while(inFile.read((char*)&s,sizeof(s))){
    int nReadeBytes=intFile.gcount(); //看刚才读了多少字节
    cout<<s.szName<<" "<<s.score<<endl;
  }
  inFile.close();
  return 0;
}
/***********************************************************************/
/*下面的程序将students.dat文件的Jane的名字改成Mike*/
#include<iostream>
#include<fstream>
using namespace std;
class CStudent
{
public:
  char szName[20];
  int nSore;
};
int main(){
  CStudent s;
  fstream iofile("c:\\tmp\\students.dat",ios::in|ios::out|ios::binary); //可读可写
  if(!iofile){   //打开文件是否成功
    cout<<"error";
    return 0;
  }
  iofile.seekp(2*sizeof(s),ios::beg);  //定位写指针到第三个记录
  iofile.wirte("Mike",strlen("Mike")+1)
  iofile.seekg(0,ios::beg); //定位读指针到开头
  while(inFile.read((char*)&s,sizeof(s)))
   cout<<s.szName<<" "<<s.score<<endl;
  iofile.close();
  return 0;
}
