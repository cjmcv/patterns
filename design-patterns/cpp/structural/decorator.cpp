/*!
* \brief. Decorator. Attach additional responsibilities to an
*      object dynamically keeping the same interface.Decorators
*      provide a flexible alternative to subclassing for extending
*      functionality.
*
*                ----- Pet --------
*                |      |         |
*              Dog     Cat    PetDecorator
*                               |      |
*                          Coloring  Dressing
*/
#include <iostream>
#include <string>

// Abstract Component  
class Pet {
public:
  Pet() {}
  virtual ~Pet() {}
  void ShowDecorate() {
    std::cout << attribute_.c_str() << std::endl;
  }
public:
  std::string attribute_;
};

// Concrete Component A
class Dog : public Pet {
public:
  Dog() {
    attribute_ = "Dog-";
  }
};

// Concrete Component B
class Cat : public Pet {
public:
  Cat() {
    attribute_ = "Cat-";
  }
};

// Abstract Decorator
class PetDecorator : public Pet {
public:
  PetDecorator() {}
protected:
  Pet *pet_;
};

// Concrete Decorator A
class Coloring : public PetDecorator {
public:
  Coloring(Pet *pet) {
    pet_ = pet;
    attribute_ = pet_->attribute_ + "Coloring-";
  }
};

// Concrete Decorator B
class Dressing : public PetDecorator {
public:
  Dressing(Pet *pet) {
    pet_ = pet; 
    attribute_ = pet_->attribute_ + "Dressing-";
  }
};

int main() {
  Pet *pet = new Dog();
  Pet *pet_color = new Coloring(pet);
  Pet *pet_color_dress = new Dressing(pet_color);
  Pet *pet_color_dress_color = new Coloring(pet_color_dress);

  pet->ShowDecorate();
  std::cout << "////////////////" << std::endl;

  pet_color->ShowDecorate();
  std::cout << "////////////////" << std::endl;

  pet_color_dress->ShowDecorate();
  std::cout << "////////////////" << std::endl;

  pet_color_dress_color->ShowDecorate();
  std::cout << "////////////////" << std::endl;

  delete pet;
  delete pet_color;
  delete pet_color_dress;
  delete pet_color_dress_color;

  return 0;
}