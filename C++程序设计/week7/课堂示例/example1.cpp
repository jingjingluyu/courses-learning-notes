/*第一课*/
/*文件的读写指针*/
ofstream fout("a1.out",ios::app); //建立一个ofstream对象fout 打开文件a1.out
long location=fout.tellp(); //取得写指针的位置location 调用tellp
location=10L; //location赋值 由于是long所以L
fout.seekp(location);  //将写指针移动到第10个字节处 就是移动到location的位置
fout.seekp(location,ios::beg); //从头数location
fout.seekp(location,ios::cur); //从当前位置cur数location
fout.seekp(location,ios::end); //从尾部数location
//location可以为负值

ifstream fout("a1.out",ios::app);
long location=fin.tellg(); //取得读指针的位置
location=10L;
fin.seekg(location); //将读指针移动到第10个字节处
fin.seekg(location,ios::beg); //从头数location
fin.seekg(location,ios::end); //从尾部数location
//location可以为负值

/***********************************************************/
/*二进制文件读写*/
int x=10;
fout.seekp(20,ios::beg); //写指针位置的定义 从begin之后的20个字节位置写起
fout.write((const char*)(&x),sizeof(int));
 //调用成员函数write 将某个字符串通过参数 (const char*)(&x) 传进来，大小sizeof(int)

 fin.seekg(0,ios::beg);
 fin.read((char*)(&x),sizeof(int));

 //二进制文件读写，直接写二进制数据，记事本看来未必正确
 /***********************************************************/
