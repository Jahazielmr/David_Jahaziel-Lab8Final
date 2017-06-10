#ifndef REAL_H
#define REAL_H
#include <string>

using namespace std;

class Real{

  public:
    Real();
  
    
  virtual string operator+(Real*)=0;
  virtual string operator+(int)=0;
  virtual string operator+(double)=0;

  virtual string operator-(Real*)=0;
  virtual string operator-(int)=0;
  virtual string operator-(double)=0;

  virtual string toString();

  virtual string operator*(Real*)=0;
  virtual string operator*(int)=0;
  virtual string operator*(double)=0;

  virtual string operator/(Real*)=0;
  virtual string operator/(int)=0;
  virtual string operator/(double)=0;
};

#endif
