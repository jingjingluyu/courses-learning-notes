#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
double r,i;
public:
void Print() {
cout << r << "+" << i << "i" << endl;
}
Complex & operator=(const char * a){
  r=*a-48;i=*(a+2)-48;
  return *this;
}
};
int main() {
Complex a;
a = "3+4i"; a.Print();
a = "5+6i"; a.Print();
return 0;
}
