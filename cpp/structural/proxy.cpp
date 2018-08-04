/*!
* \brief. Proxy. Provide a surrogate or placeholder for
*         another object to control access to it.
*
*                 Subject
*                 |     |    
*       RealSubject <-  Proxy
*/
#include <iostream>

class Subject {
public:
  virtual void Request() = 0;
};

class RealSubject : public Subject {
public:
  void Request() {
    std::cout << "RealSubject Request" << std::endl;
  }
};

class Proxy : public Subject {
public:
  Proxy(): sub_(NULL) {}
  void SetSubject(Subject* sub) {
    sub_ = sub;
  }

  void Request() {
    if (sub_ != NULL)
      sub_->Request();
    else
      std::cout << "No Subject." << std::endl;
  }

private:
  Subject* sub_;
};

int main() {
  Subject* sub = new RealSubject();
  Proxy* p = new Proxy();

  p->SetSubject(sub);
  // Use a proxy to do something for the subject.
  p->Request();

  delete sub;
  delete p;

  return 0;
}