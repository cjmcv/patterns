/*!
* \brief   Prototype.Specify the kinds of objects to
*        create using a prototypical instance,and 
*        create new objects by copying this prototype.
*
*      client     = >     Prototype
*                             | 
*                     ConcretePrototypeA    
*/

#include <iostream>

class Prototype {
public:
  virtual void PrintName() = 0;
  virtual Prototype* clone() = 0;
};

class ConcretePrototypeA :public Prototype {
public:
  ConcretePrototypeA() {};
  Prototype* clone() {
    return new ConcretePrototypeA(*this);
  }
  void PrintName() {
    std::cout << "This is ConcretePrototypeA." << std::endl;
  }

private:
  ConcretePrototypeA(const ConcretePrototypeA&) {
    std::cout << "Excute copy construction of ConcretePrototypeA." << std::endl;
  }
};

class ConcretePrototypeB :public Prototype {
public:
  ConcretePrototypeB() {};
  Prototype* clone() {
    return new ConcretePrototypeB(*this);
  }
  void PrintName() {
    std::cout << "This is ConcretePrototypeB." << std::endl;
  }

private:
  ConcretePrototypeB(const ConcretePrototypeB&) {
    std::cout << "Excute copy construction of ConcretePrototypeB." << std::endl;
  }
};

int main() {

  Prototype* ca = new ConcretePrototypeA();
  Prototype* cb = new ConcretePrototypeB();

  // You have no idea what the Concrete Prototype you created.
  // But if using copy construction directly, you need to know 
  // the Concrete Prototype you want to create.
  Prototype* cda = ca->clone();
  Prototype* cdb = cb->clone();

  cda->PrintName();
  cdb->PrintName();

  delete ca;
  delete cb;

  // It means the clone funciton above is designed for deep copy.
  cda->PrintName(); 
  cdb->PrintName();

  delete cda;
  delete cdb;

  return 0;
}