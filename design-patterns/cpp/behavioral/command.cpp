/*!
* \brief   Command.Encapsulate a request as an object,thereby
*        letting you parameterize clients with different requests,
*        queue or log requests,and support undoable operations.
*
*        Invoker    =>   ( Command    =>   Receiver )
*                             |
*                        ConcreteCommand
*/

#include <iostream>
#include <vector>

// Receiver.
class Engineer {
public:
  void Coding() {
    std::cout << "Coding." << std::endl;
  }
  void Meeting() {
    std::cout << "Meeting." << std::endl;
  }
};

// Command.
class Command {
public:
  Command() {}
  virtual void ExecuteCommand() = 0;
protected:
  Engineer *receiver_;
};

class CodingCommand :public Command {
public:
  CodingCommand(Engineer *receiver) { receiver_ = receiver; }
  void ExecuteCommand() {
    receiver_->Coding();
  }
};

class MeetingCommand :public Command {
public:
  MeetingCommand(Engineer *receiver) { receiver_ = receiver; }
  void ExecuteCommand() {
    receiver_->Meeting();
  }
};

// Invoker.
class Manager {
public:
  Manager() {
    command_list_.clear();
  }
  void SetCommand(Command *command) {
    command_list_.push_back(command);
  }
  void Action() {
    for (unsigned int i = 0; i < command_list_.size(); i++) {
      command_list_[i]->ExecuteCommand();
    }
  }
private:
  std::vector<Command *> command_list_;
};

int main(int argc, char *argv[]) {

  Manager *manager = new Manager();
  Engineer *engineer = new Engineer();

  Command *command_one = new MeetingCommand(engineer);
  Command *command_two = new CodingCommand(engineer);

  manager->SetCommand(command_one);
  manager->SetCommand(command_two);

  // Engineer is going to excute those commands here.
  manager->Action(); 

  delete manager;
  delete engineer;
  delete command_one;
  delete command_two;

  return 0;
}