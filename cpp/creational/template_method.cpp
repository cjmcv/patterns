/*!
* \brief. Template Method. Define the skeleton of an algorithm 
*      in an operation,deferring some steps to subclasses.Template
*      Method lets subclasses redefine certain steps of an algorithm 
*      without changing the algorithm's.
*/

#include <iostream>
#include <memory> 

class Animal { 
public:
  void GetInfo() {
    this->GetSpecies();
    this->GetName();
  }

protected:
  // protected virtual functions.
  virtual void GetSpecies() {
    printf("Animal.");
  }
  virtual void GetName() {
    printf("A.\n");
  }
};

//  Use protected functions to override.
class Lion : public Animal {
protected:
  void GetSpecies() {
    printf("Lion.");
  }
  void GetName() {
    printf("B.\n");
  }
};

class Tiger : public Animal {
protected:
  void GetSpecies() {
    printf("Tiger.");
  }
  void GetName() {
    printf("C.\n");
  }
};

int main() {
  Animal *animal_a = new Lion();
  Animal *animal_b = new Tiger();

  animal_a->GetInfo();
  animal_b->GetInfo();

  delete animal_a;
  delete animal_b;
  return 0;
}