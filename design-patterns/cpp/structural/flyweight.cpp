/*!
* \brief. Flyweight. Use sharing to support large numbers 
*      of fine-grained objects efficiently.
*
*        FlyweightFactory   <-->         Flyweight
*                                         |     |
*                           ConcreteFlyweight  UnsharedConcreteFlyweight
*/

#include <iostream>  
#include <map>  

class Flyweight {
public:
  virtual void Operation() = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
  void Operation() {
    std::cout << "ConcreteFlyweight's Operation." << std::endl;
  }
};

class FlyweightFactory {
public:
  void Initialize() {
    obj_map_['A'] = new ConcreteFlyweight;
    obj_map_['B'] = new ConcreteFlyweight;
  } 
  void ClearFlyweight() {
    std::map<char, Flyweight*>::iterator it = obj_map_.begin();
    while (it != obj_map_.end()) { 
      std::cout << "Release object " << it->first << std::endl;
      delete it->second; 
      obj_map_.erase(it++);
    }
  }

  Flyweight* GetFlyweight(char tag) {
    std::map<char, Flyweight*>::iterator it = obj_map_.find(tag);
    if (it != obj_map_.end()) {
      return (Flyweight*)it->second;
    }
    else {
      std::cout << "Create new object for " << tag << std::endl;
      Flyweight* new_obj = new ConcreteFlyweight;
      obj_map_[tag] = new_obj;
      return new_obj;
    }
  }
private:
  // The key member for Flyweight Pattern.
  std::map<char, Flyweight*> obj_map_;
};

int main() {
  FlyweightFactory* factory = new FlyweightFactory;
  factory->Initialize();

  Flyweight* ch1 = factory->GetFlyweight('A');
  if (ch1 != NULL)
    ch1->Operation();

  Flyweight* ch2 = factory->GetFlyweight('B');
  if (ch2 != NULL)
    ch2->Operation();

  Flyweight* ch3 = factory->GetFlyweight('C');
  if (ch3 != NULL)
    ch3->Operation();

  Flyweight* ch4 = factory->GetFlyweight('A');
  if (ch4 != NULL)
    ch4->Operation();

  // The address of ch4 is the same as ch1.
  std::cout << "address: " << ch1 << ", " << ch2 << ", " \
    << ch3 << ", " << ch4 << std::endl;
  
  std::cout << std::endl;
  factory->ClearFlyweight();
  std::cout << std::endl;

  Flyweight* ch5 = factory->GetFlyweight('C');
  if (ch5 != NULL)
    ch5->Operation();

  std::cout << "address: " << ch5 << std::endl;

  return 0;
}