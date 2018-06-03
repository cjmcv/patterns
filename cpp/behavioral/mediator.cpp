/*!
* \brief   Mediator.Define an object that encapsulates how 
*       a set of objects interact.Mediator promotes loose 
*       coupling by keeping objects from referring to each 
*       other explicitly,and it lets you vary their interaction
*       independently.
*
*     ( Renter and Landlord communicate through HouseMediator. 
*       So Renter and Landlord don't need to meet each other. )
*
*        Person     <=>     Mediator     <=>    Person
*          |                   |                  |
*        Renter           HouseMediator        Landlord
*/

#include <iostream>
#include <string>

class Mediator;

class Person {
public:
  virtual void SetMediator(Mediator *mediator) {}
  virtual void SendMessage(std::string &message) {}
  virtual void GetMessage(std::string &message) {}
protected:
  Mediator *mediator_;
};

class Mediator {
public:
  virtual void Send(std::string &message, Person *person) {}
  virtual void SetRenter(Person *renter) {}
  virtual void SetLandlord(Person *landlord) {}
};

// Concrete Person A
class Renter :public Person {
public:
  void SetMediator(Mediator *mediator) {
    mediator_ = mediator; 
    mediator_->SetRenter(this);
  }
  void SendMessage(std::string &message) { 
    mediator_->Send(message, this);
  }
  void GetMessage(std::string &message) { 
    std::cout << "Renter gets the message from Landlord£º" << message;
  }
};

// Concrete Person B
class Landlord :public Person {
public:
  void SetMediator(Mediator *mediator) {
    mediator_ = mediator; 
    mediator_->SetLandlord(this);
  }
  void SendMessage(std::string &message) {
    mediator_->Send(message, this);
  }
  void GetMessage(std::string &message) {
    std::cout << "Landlord gets the message from Renter£º" << message;
  }
};

// Concrete Mediator.
class HouseMediator :public Mediator {
public:
  HouseMediator() :renter_(NULL), landlord_(NULL) {}
  void SetRenter(Person *renter) { 
    renter_ = renter; 
  }
  void SetLandlord(Person *landlord) {
    landlord_ = landlord; 
  }
  void Send(std::string &message, Person *person) {
    if (person == renter_)
      landlord_->GetMessage(message);
    else
      renter_->GetMessage(message);
  }
private:
  Person *renter_;
  Person *landlord_;
};

int main() {
  Mediator *mediator = new HouseMediator();
  Person *renter = new Renter();
  Person *landlord = new Landlord();

  renter->SetMediator(mediator);
  landlord->SetMediator(mediator);

  renter->SendMessage(std::string("I want to rent a house in ShenZhen.\n"));
  landlord->SendMessage(std::string("I have a house in ShenZhen.\n"));
  
  delete renter;
  delete landlord;
  delete mediator;

  return 0;
}