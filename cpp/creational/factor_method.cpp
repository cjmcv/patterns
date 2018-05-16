/*!
* \brief.   Factory method. Use multiple factories for 
*         multiple products
*
* \pattern. Factory method:
*           Define an interface for creating an object,
*         but let subclasses decide which class to
*         instantiate.Factory Method lets a class defer
*         instantiation to subclasses.
* 
*      AbstractProduct     < = >        AbstractFactory
*        |         |                     |          |
*    ProductA  ProductB    FactoryA(for ProductA)  FactoryB(for ProductB)
*/

#include <iostream>
#include <memory> 

// AbstractProduct
class Animal {

public:
  virtual void GetSpecies() {
    printf("Animal.\n");
  }
  static Animal *Create() {
    Animal *t = new Animal();
    return t;
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

// AbstractFactory
class AnimalFactory {
public:
  Animal *CreateAnimal() {
    return Lion::Create();
  }
};

// Factory
class LionFactory : public AnimalFactory {
public:
  Animal *CreateAnimal() {
    return Lion::Create();
  }
};

class TigerFactory : public AnimalFactory {
public:
  Animal *CreateAnimal() {
    return Tiger::Create();
  }
};

int main() {
  AnimalFactory *factory = NULL;
  Animal *animal = NULL;

  factory = new LionFactory();
  animal = factory->CreateAnimal();
  animal->GetSpecies();
  animal->GetSpecies();

  delete animal;
  delete factory;

  factory = new TigerFactory();
  animal = factory->CreateAnimal();
  animal->GetSpecies();

  delete animal;
  delete factory;

  return 0;
}