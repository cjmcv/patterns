/*!
* \brief. Bridge. Decouple an abstraction from its 
*      implementation so that the two can vary 
*      independently.
*
*        Computer    <==>    OS
*         |    |            |  |
*       IBM    HP      Windows  Linux   
*/

#include <iostream>  

// Implementor
class OS {
public:
  virtual void Run() = 0;
};

// Concrete Implementor A
class Windows : public OS {
public:
  void Run() {
    printf("Running Windows!\n");
  }
};

// Concrete Implementor B
class Linux : public OS {
public:
  void Run() {
    printf("Running Linux!\n");
  }
};

// Abstraction
class Computer {
public:
  virtual void Install(OS* os) = 0;
  virtual void Run() = 0;
};

// RefinedAbstraction A
class IBM : public Computer {
public:
  IBM() :os_(NULL) {}
  void Install(OS* os) {
    os_ = os;
  }
  void Run() {
    printf("Open the IBM computer.\n");
    if (os_ != NULL)
      os_->Run();
    else
      printf("The computer has not yet installed an operating system.\n");
  }
private:
  OS *os_;
};

// RefinedAbstraction B
class HP : public Computer {
public:
  HP() :os_(NULL) {}
  void Install(OS* os) {
    os_ = os;
  }
  void Run() {
    printf("Open the HP computer.\n");
    if (os_ != NULL)
      os_->Run();
    else
      printf("The computer has not yet installed an operating system.\n");
  }
private:
  OS *os_;
};

int main() {
  OS* os_win = new Windows();
  OS* os_linux = new Linux();

  Computer* device = new IBM();
  Computer* device2 = new HP();

  device->Install(os_win);
  //device2->Install(os_linux);

  device->Run();
  device2->Run();

  delete os_win;
  delete os_linux;
  delete device;
  delete device2;

  return 0;
}