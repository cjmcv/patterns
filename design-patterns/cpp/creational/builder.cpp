/*!
* \brief. Builder. Separate the construction of a complex 
*       object from its representation so that the same
*       construction process can create different 
*       representations.
*/

#include <iostream>
#include <memory> 

// Builder.
class AnimalBuilder {
public:
  virtual void BuildSpecies() {}
  virtual void BuildColor() {}
};
 
class LionBuilder : public AnimalBuilder {
public:
  void BuildSpecies() {
    std::cout << "Build species: Lion." << std::endl;
  }
  void BuildColor() {
    std::cout << "Build color: yellow." << std::endl;
  }
};
  
class TigerBuilder : public AnimalBuilder {
public:
  void BuildSpecies() {
    std::cout << "Build species: Tiger." << std::endl;
  }
  void BuildColor() {
    std::cout << "Build color: orange." << std::endl;
  }
};

// Director.
class Director {
public:
  void Initialize(AnimalBuilder *builder) {
    builder_ = builder; 
  }
  void Create() {
    builder_->BuildSpecies();
    builder_->BuildColor();
  }
private:
  AnimalBuilder *builder_;
};

int main() {
  Director *director = new Director();

  LionBuilder lion;
  director->Initialize(&lion);
  director->Create();

  TigerBuilder tiger;
  director->Initialize(&tiger);
  director->Create();

  delete director;

  //// Compare to Simple Factory here.
  //AnimalFactory *factory = new AnimalFactory();
  //Animal *animal_a = factory->CreateAnimal(Lion::Create);
  //Animal *animal_b = factory->CreateAnimal(Tiger::Create);
  //Animal *animal_c = factory->CreateAnimal(Leopard::Create);

  return 0;
}