/*!
* \brief. Adapter. Convert the interface of a class into
*      another interface clients expect.Adapter lets classes 
*      work together that couldn't otherwise because of 
*      incompatible interfaces.
*/
#include <iostream>

// The class for target interface that the customer needs.
class Target {
public:
  // Standard interface.
  virtual void Request() {
    std::cout << "Target::Request()" << std::endl;
  }
};

// The Class that need to be adapted.
class Adaptee {
public:
  void SpecificRequest() {
    std::cout << "Adaptee::SpecificRequest()" << std::endl;
  }
};

// Class Adapter. Adaptive through private inheritance.
class ClassAdapter : public Target, private Adaptee {
public:
  virtual void Request() {
    this->SpecificRequest();
  }
};

// Object Adapter. Adaptive through an object of Adaptee.
class ObjectAdapter :public Target {
public:
  ObjectAdapter(Adaptee* adaptee) {
    this->adaptee_ = adaptee_;
  }
  virtual void Request() {
    this->adaptee_->SpecificRequest();
  }
private:
  Adaptee* adaptee_;
};

int main() {
  { // Without using adapter.
    // You can't use the target interface to call the function. 
    Adaptee *src = new Adaptee();
    src->SpecificRequest();
    delete src;
  }

  std::cout << "///" << std::endl;

  { // Use Class Adapter.
    Target* target = new ClassAdapter();
    target->Request();
    delete target;
  }

  std::cout << "///" << std::endl;

  { // Use Object Adapter.
    Adaptee* src = new Adaptee();
    Target* target = new ObjectAdapter(src);
    target->Request();
    
    delete src;
    delete target;
  }

  std::cout << "///" << std::endl;

  return 0;
}