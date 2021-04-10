/*!
* \brief   Memento. Without violating encapsulation,capture
*       and externalize an object's internal state so that the
*       object can be restored to this state later.
*
*/
#include <iostream>

// Memento. Responsible for storing the internal state of the Originator
//       and providing the internal state of the Originator as needed.
class Memento {
public:
  Memento(const std::string& state) {
    this->state_ = state;
  }
  void SetState(const std::string& state) {
    this->state_ = state;
  }
  std::string &GetState() {
    return this->state_;
  }
private:
  std::string state_;
};

// Originator. It is responsible for recording the internal state of the
//        current moment, defining which states belong to the backup scope,
//        and creating and restoring the memo data.
class Originator {
public:
  Originator(const std::string& state) {
    this->state_ = state;
  }
  Memento* CreateMemento() {
    return new Memento(this->state_);
  }
  void RestoreToMemento(Memento* memento) {
    this->state_ = memento->GetState();
  }
  void SetState(const std::string& state) {
    this->state_ = state;
  }
  std::string &GetState() {
    return this->state_;
  }

private:
  std::string state_;
};

// Caretaker. Manage, save and provide the Memento.
class Caretaker {
public:
  void SetMemento(Memento* memento) {
    this->memento_ = memento;
  }
  Memento* GetMemento() {
    return this->memento_;
  }

private:
  Memento* memento_;
};

int main() {
  // Initialize.
  Originator* org = new Originator("A");
  std::cout << org->GetState().c_str() << std::endl;

  // Save.
  Caretaker* taker = new Caretaker();
  taker->SetMemento(org->CreateMemento());

  // Change.
  org->SetState("B");
  std::cout << org->GetState().c_str() << std::endl;

  // Restore.
  org->RestoreToMemento(taker->GetMemento());
  std::cout << org->GetState().c_str() << std::endl;

  return 0;
}