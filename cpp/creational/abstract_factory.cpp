/*!
* \brief.   Abstract Factory method. Use multiple factories for
*         multiple products
*
* \pattern. Factory method:
*           Define an interface for creating an object,
*         but let subclasses decide which class to
*         instantiate.Factory Method lets a class defer
*         instantiation to subclasses.
*
*      AbstractProduct1     < = >     AbstractProduct2
*        |         |                     |          |
*    ProductA1  ProductB1           ProductA2  ProductB2
*
*                       AbstractFactory 
*                        |           | 
*                  FactoryA         FactoryB
*        (for ProductA1 and A2)  (for ProductB1 and B2)
*
****************************************************************
*
*        MaleAnimal     < = >     FemaleAnimal
*        |        |               |          |
*    MaleLion  MaleTiger     FemaleLion  FemaleTiger
*
*                          AnimalFactory
*                          |           |
*                 LionFactory         TigerFactory
*   (for MaleLion and FemaleLion)  (for MaleTiger and FemaleTiger) 
*/

#include <iostream>
#include <memory> 

// AbstractProduct1
class MaleAnimal {

public:
  virtual void GetSpecies() {
    printf("MaleAnimal.\n");
  }
  static MaleAnimal *Create() {
    MaleAnimal *t = new MaleAnimal();
    return t;
  }
};

// ProductA1
class MaleLion : public MaleAnimal {
public:
  MaleLion() :age(0) {}
  void GetSpecies() {
    printf("MaleLion. age: %d\n", age++);
  }
  static MaleAnimal *Create() {
    MaleAnimal *t = new MaleLion();
    return t;
  }
private:
  int age;
};
// ProductB1
class MaleTiger : public MaleAnimal {
public:
  void GetSpecies() {
    printf("MaleTiger.\n");
  }
  static MaleAnimal *Create() {
    MaleAnimal *t = new MaleTiger();
    return t;
  }
};
//////////////////////////////////////////////////////////////
// AbstractProduct2
class FemaleAnimal {

public:
  virtual void GetSpecies() {
    printf("FemaleAnimal.\n");
  }
  static FemaleAnimal *Create() {
    FemaleAnimal *t = new FemaleAnimal();
    return t;
  }
};

// ProductA2
class FemaleLion : public FemaleAnimal {
public:
  FemaleLion() :age(0) {}
  void GetSpecies() {
    printf("FemaleLion. age: %d\n", age++);
  }
  static FemaleAnimal *Create() {
    FemaleAnimal *t = new FemaleLion();
    return t;
  }
private:
  int age;
};
// ProductB2
class FemaleTiger : public FemaleAnimal {
public:
  void GetSpecies() {
    printf("FemaleTiger.\n");
  }
  static FemaleAnimal *Create() {
    FemaleAnimal *t = new FemaleTiger();
    return t;
  }
};

//////////////////////////////////////////////////////////////
// AbstractFactory
class AnimalFactory {
public:
  virtual MaleAnimal *CreateMaleAnimal() {
    return MaleAnimal::Create();
  }
  virtual FemaleAnimal *CreateFemaleAnimal() {
    return FemaleAnimal::Create();
  }
};

// Factory
class LionFactory : public AnimalFactory {
public:
  MaleAnimal *CreateMaleAnimal() {
    return MaleLion::Create();
  }
  FemaleAnimal *CreateFemaleAnimal() {
    return FemaleLion::Create();
  }
};

class TigerFactory : public AnimalFactory {
public:
  MaleAnimal *CreateMaleAnimal() {
    return MaleTiger::Create();
  }
  FemaleAnimal *CreateFemaleAnimal() {
    return FemaleTiger::Create();
  }
};

int main() {
  AnimalFactory *factory = NULL;
  MaleAnimal *male_animal = NULL;
  FemaleAnimal *female_animal = NULL;

  factory = new LionFactory();
  male_animal = factory->CreateMaleAnimal();
  female_animal = factory->CreateFemaleAnimal();

  male_animal->GetSpecies();
  female_animal->GetSpecies();

  delete male_animal;
  delete female_animal;
  delete factory;

  factory = new TigerFactory();
  male_animal = factory->CreateMaleAnimal();
  female_animal = factory->CreateFemaleAnimal();

  male_animal->GetSpecies();
  female_animal->GetSpecies();

  delete male_animal;
  delete female_animal;
  delete factory;

  return 0;
}