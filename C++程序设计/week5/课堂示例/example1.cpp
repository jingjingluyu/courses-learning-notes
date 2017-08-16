/*第一课*/
/*需要继承机制的例子*/
/*所有的学生都有的共同属性：
    姓名
    学号
    性别
    成绩
所有的学生都有的共同方法(成员函数)：
    是否该留级
    是否该奖励
而不同的学生，又有各自不同的属性和方法：
    研究生
      导师
      系
    大学生
      系
    中学生
      竞赛特长加分*/
class CStudent{
private:
  string sName;
  int nAge;
public:
  bool IsThreeGood(){};
  void SetName(const string & name)
  {sName=name;}
  //... ...
};
class CUndergraduateStudent:public CStudent{
private:
  int nDepartment;
public:
  bool IsThreeGood(){......};//覆盖
  bool CanBao Yan(){... ...};
}; //派生类的写法是：类名：public 基类名
class CGraduateStudent:public CStudent{
private:
  int nDepartment;
  char szMentorName[20];
public:
  int CountSalary(){...};
};
/****************************************************************************/
/*学籍管理*/
#include<iostream>
#include<string>
using namespace std;
class CStudent{
private:
  string name;
  string id; //学号
  char gender; //性别，‘F’代表女，‘M’代表男
  int age;
public:
  void PrintInfo(); //打印出学生的具体信息
  void SetInfo(const string & name_,const string & id_,int age_,char gender_); //设置学生的各种信息
  string GetName(){return name;}
};
class CUndergraduateStudent:public CStudent
{ //本科生类，继承了CStudent类
private:
  string department; //学生所属的系的名称
public:
  void QualifiedForBaoyan(){ //给予保研资格
    cout<<"qualified for baoyan"<<endl;
  }
  void Printlnfo(){  //覆盖，派生类对基类的修改
    CStudent::PrintInfo();  //调用基类的PrintInfo
    cout<<"Department:"<<department<<endl;
  }
  void SetInfo(const string & name_,const string & id_,int age_,
    char gender_,const string & department_)
  {
    CStudent::SetInfo(name_,id_,age_,gender_); //调用基类的SetInfo
    department=department_;
  }
};
int main()
{
  CUndergraduateStudent s2;
  s2.SetInfo("Harry Potter","118829212",19,'M',"Computer Science");
  cout<<s2.GetName()<<" ";
  s2. QualifiedForBaoyan();
  s2. PrintInfo();
  return 0;
}
