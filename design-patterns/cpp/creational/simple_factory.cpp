/*!
* \brief. Simple factory. Receive a parameter to select
*         the object you want to constructe.
*
* \pattern. Factory method:
*           Define an interface for creating an object,
*         but let subclasses decide which class to
*         instantiate.Factory Method lets a class defer
*         instantiation to subclasses
* 
*      AbstractProduct  < = >  Factory(for all of the products)
*        |         |
*    ProductA  ProductB
*/

#include <iostream>
#include <memory> 

// AbstractProduct
class Animal {
public:
  virtual void GetSpecies() {
    printf("Animal.\n");
  }
};

// Product
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

// Factory
typedef Animal *(*CREATOR)();
class AnimalFactory { 
public:
  Animal *CreateAnimal(CREATOR c) {
    return (*c)();
  }
};

int main() {
  AnimalFactory *factory = new AnimalFactory();

  Animal *animal_a = factory->CreateAnimal(Lion::Create);
  Animal *animal_b = factory->CreateAnimal(Tiger::Create);
  Animal *animal_c = factory->CreateAnimal(Leopard::Create);

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