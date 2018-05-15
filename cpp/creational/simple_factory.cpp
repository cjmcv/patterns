/*!
* \brief. Receive a parameter to select
*         the object you want to constructe.
*
* \pattern. factory method:
*           Define an interface for creating an object,
*         but let subclasses decide which class to
*         instantiate.Factory Method lets a class defer
*         instantiation to subclasses
*/

#include <iostream>
#include <memory> 

// AbstractProduct: Animal
class Animal {

public:
  virtual void GetSpecies() {
    printf("Animal.\n");
  }
};

// Product: Lion
class Lion : public Animal {
public:
  Lion() :age(0) {}
  void GetSpecies() {
    printf("Lion. age: %d\n", age++);
  }
  static Animal *Create() {
    Animal *t = new Lion();
    return t;
  }
private:
  int age;
};

class Tiger : public Animal {
public:
  void GetSpecies() {
    printf("Tiger.\n");
  }
  static Animal *Create() {
    Animal *t = new Tiger();
    return t;
  }
};

class Leopard : public Animal {
public:
  void GetSpecies() {
    printf("Leopard.\n");
  }
  static Animal *Create() {
    Animal *t = new Leopard();
    return t;
  }
};

typedef Animal *(*CREATOR)();
class AnimalFactory { 
public:
  Animal *CreateHuman(CREATOR c) {
    return (*c)();
  }
};

int main() {
  AnimalFactory *factory = new AnimalFactory();

  Animal *animal_a = factory->CreateHuman(Lion::Create);
  Animal *animal_b = factory->CreateHuman(Tiger::Create);
  Animal *animal_c = factory->CreateHuman(Leopard::Create);

  animal_a->GetSpecies();
  animal_a->GetSpecies();

  animal_b->GetSpecies();
  animal_c->GetSpecies();
    
  delete animal_a;
  delete animal_b;
  delete animal_c;

  delete factory;

  return 0;
}