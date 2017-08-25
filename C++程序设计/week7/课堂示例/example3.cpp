/*第一课*/
/*mycopy程序，文件拷贝*/
//用法示例：
//mycopy src.dat dest.dat
//即将 src.dat 拷贝到 dest.dat
//如果 dest.dat 原来就有，则原来的文件会被覆盖
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[]){
  if(argc!=3){
    cout<<"File name missing!"<<endl;
    return 0;
  }
  ifstream inFile(argv[1],ios::binary|ios::in) //打开文件用于读 argv[1]第二个参数文件名
  if(!inFile){
    cout<<"Source file open error."<<endl;
    return 0;
  }
  ofstream outFile(argv[2],ios::binary|ios::out); //打开文件用于写
  if(!outFile){
    cout<<"New file open error."<<endl;
    inFile.close();  //打开的文件一定要关闭
    return 0;
  }
  char c;
  while(inFile.get(c))  //每次读取一个字符
    outFile.put(c); //每次写入一个字符
  outFile.close();
  inFile.close();
  return 0;
}
