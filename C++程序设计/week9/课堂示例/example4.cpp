/*multimap例题*/
/*一个学生成绩录入和查询系统，接受以下两种输入：
   Add name id score
   Query score

   name是个字符串，中间没有空格，代表学生姓名。id是个整数，代表学生学号。
   score是个整数，表示分数。学号不会重复，分数和姓名都可能重复。

   两种输入交替出现。第一种输入表示要添加一个学生的信息，碰到这种输入，
   就记下学生的姓名、id和分数。第二种输入表示要查询，碰到这种输入，
   就输出已有记录中分数比score低的最高分获得者的姓名、学号和分数。
   如果有多个学生都满足条件，就输出学号最大的那个学生的信息。如果找不到满足条件的学生，则输出”Nobody"

   输入样例：
    Add Jack 12 78
    Query 78
    Query 81
    Add Percy 9 81
    Add Marry 8 81
    Query 82
    Add Tom 11 79
    Query 80
    Query 81

    输出结果样例：
    Nobody
    Jack 12 78
    Percy 9 81
    Tom 11 79
    Tom 11 79*/
  #include<iostream>
  #include<map> //使用multimap需要包含此头文件
  #include<string>
  using namespace std;
  class CStudent
  {
  public:
    struct CInfo //类的内部还可以定义类
    {
      int id;
      string name;
    };
    int score;
    CInfo info; //学生的其他信息
  };
  typedef multimap<int,CStudent::CInfo> MAP_STD;
  //first成员变量是一个int型，second成员变量是CStudent::CInfo类型
  int main()
  {
    MAP_STD mp;
    CStudent st;
    string cmd; //用来存放读取的命令
    while(cin >> cmd)
    {
      if(cmd == "Add")
      {
        cin >> st.info.name >> st.info.id >> st.score;
        mp.insert(MAP_STD::value_type(st.score,st.info));
        //把学生的信息插入到mp中，但是st是cstudent类，所以就不能直接插入mp中，value_type是个类型，临时对象
        //mp.insert(make_pair(st.score,st.info));也可以
      }
      else if(cmd == "Query")
      {
        int score;
        cin >> score;
        MAP_STD::iterator p = mp.lower_bound(score);
        if(p!=mp.begin()) //如果p==mp.begin没找到
        {
          --p;
          score=p->first; //比较查询分数低的最高分
          MAP_STD::iterator maxp=p;
          int maxId=p->second.id;
          for(;p!=mp.begin()&&p->first==score;--p)
          {
            //遍历所有成绩和score相等的学生
            if(p->second.id>maxId)
            {
              maxp=p;
              maxId=p->second.id;
            }
          }
          if(p->first==score)
          {
              //如果上面的循环是因为p==mp.begin()
              //而终止，则p指向的元素还要处理
            if(p->second.id>maxId)
            {
              maxp=p;
              maxId=p->second.id;
            }
          }
          cout<<maxp->second.name<<" "<<maxp->second.id<<" "<<maxp->first<<endl;
        }
        else
        //lower_bound的结果就是 begin ,说明没人分数比查询分数低
          cout<<"Nobody"<<endl;
      }
    }
    return 0;
  }
