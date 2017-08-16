/*第一课*/
/*复合关系的使用*/
/*如果要写一个小区养狗管理程序，需要写一个“业主”类，还需要写一个”狗”类
   而狗是有“主人”的，主人当然是业主（假定狗只有一个主人，但一个业主可以有最多10条狗*/
class CDog;
class CMaster
{
  CDog dogs[10];
};
class CDog
{
  CMaster m;
};
//错误，循环定义
/*另一种写法：
  为“狗”类设计一个”业主”类的成员对象；
  为“业主”类设计一个“狗”类的对象指针数组。
  */
  class CDog;
  class CMastr{
    CDog * dogs[10];
  };
  class CDog{
    CMaster m;
  };
//更改狗主人信息麻烦
/*凑合的写法：
   为”狗“类设计一个”业主“类的对象指针；
   为”业主“类设计一个”狗”类的对象数组。*/
class CMaster; //CMaster 必须提前声明，不能先写CMaster类后写Cdog类
class CDog{
  CMaster *pm;
};
class CMaster{
  CDog dogs[10];
};
/*正确的写法
   为“狗”类设计一个”业主*类的对象指针；
   为“业主”类设计一个”狗“类的对象指针数组。*/
class CMaster; //CMaster必须提前声明，不能先写CMaster类后写Cdog类
class CDog{
CMaster *pm;
};
class CMaster{
  CDog * dogs[10];
};
