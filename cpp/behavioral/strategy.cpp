/*!
* \brief   Strategy. Define a family of algorithms, encapsulate each 
*       one, and make them interchangeable.
*
*          Context      ->              Strategy
*                                       |     |
*     ConcreteContext     ConcreteStrategy1  ConcreteStrategy2
*/

#include <iostream>

class Strategy {
public:
  virtual std::string Execute() = 0;
};

// ConcreteStrategy1.
class Walk : public Strategy {
public:
  std::string Execute() {
    return "<Walk>";
  }
};

// ConcreteStrategy2.
class Swim :public Strategy {
public:
  std::string Execute() {
    return "<Swim>";
  }
};

// Context.
class Context {
public: 
  virtual void SetStrategy(Strategy *w) = 0;
  virtual void Go() = 0;
};

// ConcreteContext.
class Go2Beijing : public Context {
public:
  Go2Beijing() : way_(0) {};
  void SetStrategy(Strategy *w) {
    way_ = w;
  }
  void Go() {
    if(way_ != 0)
      std::cout << "I'm going to " << way_->Execute().c_str() << " to Beijing." << std::endl;
    else
      std::cout << "I don't know how to get to Beijing yet." << std::endl;
  }

private:
  Strategy *way_;
};

int main() {
  Strategy *swim = new Swim();
  Strategy *walk = new Walk();

  Context *context = new Go2Beijing();

  context->Go();
  std::cout << "/////////////////" << std::endl;

  context->SetStrategy(swim);
  context->Go();
  std::cout << "/////////////////" << std::endl;

  context->SetStrategy(walk);
  context->Go();
  std::cout << "/////////////////" << std::endl;

  return 0;
}
