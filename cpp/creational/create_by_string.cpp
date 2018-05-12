#include <iostream>
#include <memory>
#include <map> 

class Animal {

public:
  virtual void GetSpecies() {
    printf("Animal.\n");
  }
};

class Lion : public Animal {
public:
  void GetSpecies() {
    printf("Lion.\n");
  }
  static std::shared_ptr<Animal> CreateLion() {
    return std::shared_ptr<Animal>(new Lion());
  }
};

class Tiger : public Animal {
public:
  void GetSpecies() {
    printf("Tiger.\n");
  }
  static std::shared_ptr<Animal> CreateTiger() {
    return std::shared_ptr<Animal>(new Tiger());
  }
};

class Leopard : public Animal {
public:
  void GetSpecies() {
    printf("Leopard.\n");
  }
  static std::shared_ptr<Animal> CreateLeopard() {
    return std::shared_ptr<Animal>(new Leopard());
  }
};

class AnimalFactory {
  typedef std::shared_ptr<Animal>(*AnimalCreator)();
public:
  ~AnimalFactory() {};

  // Create operator instance according to the name that has been registered.
  std::shared_ptr< Animal > CreateByType(std::string type) {
    typename std::map<std::string, AnimalCreator>::iterator it = creator_map_.find(type);
    if (it == creator_map_.end())
      return NULL;

    AnimalCreator creator = it->second;
    if (!creator)
      return NULL;

    return creator();
  }

  // Registerer, set the mapping relation between operator's class name and it's specific pointer function.
  int RegisterClass(std::string type, AnimalCreator getOpFunc) {
    if (creator_map_.count(type) != 0) {
      printf("type %s is already registered.\n", type.c_str());
      return -1;
    }
    creator_map_[type] = getOpFunc;
    return 0;
  }

  // Singleton mode. Only one AnimalFactory exist.
  static AnimalFactory& GetInstance() {
    static AnimalFactory factory;
    return factory;
  }

private:
  AnimalFactory() {};
  typename std::map<std::string, AnimalCreator> creator_map_;
};

static void RegisterAnimal() {
  AnimalFactory::GetInstance().RegisterClass("Lion", Lion::CreateLion);
  AnimalFactory::GetInstance().RegisterClass("Tiger", Tiger::CreateTiger);
  AnimalFactory::GetInstance().RegisterClass("Leopard", Leopard::CreateLeopard);
}

int main() {
  RegisterAnimal();

  std::shared_ptr<Animal> animal_a = AnimalFactory::GetInstance().CreateByType("Lion");
  std::shared_ptr<Animal> animal_b = AnimalFactory::GetInstance().CreateByType("Tiger");
  std::shared_ptr<Animal> animal_c = AnimalFactory::GetInstance().CreateByType("Leopard");

  animal_a->GetSpecies();
  animal_b->GetSpecies();
  animal_c->GetSpecies();

  return 0;
}