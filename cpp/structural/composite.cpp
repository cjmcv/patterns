/*!
* \brief. Composite. Compose objects into tree structures 
*       to represent part-whole hierarchies.Composite lets
*       clients treat individual objects and compositions 
*       of objects uniformly.
*
*           Component                  Leader
*            |    |                    |    |
*         Leaf    Composite        Member  Leader
*                                          |    |
*                                      Member  Member    
*/

#include <iostream>
#include <string>
#include <list>

// Component.
class Component {
public:
  Component(char* name) :name_(name) {}
  virtual void Add(Component* cpn) {}
  virtual void Remove(Component* cpn) {}
  virtual void Display(std::string str) {}

protected:
  char* name_;
  std::list<Component* > list_;
};

// Composite.
class Leader :public Component {
public:
  Leader(char* name) :Component(name) {}
  virtual void Add(Component* cpn) {
    if (cpn != NULL) {
      list_.push_back(cpn);
    }
  }
  virtual void Remove(Component* cpn) {
    if (cpn != NULL) {
      list_.remove(cpn);
    }
  }
  virtual void Display(std::string str) {
    std::cout << str << name_ << std::endl;
    str = str + str;
    std::list<Component*>::iterator iter = list_.begin();
    for (; iter != list_.end(); iter++) {
      (*iter)->Display(str);
    }
  }
};

// Leaf.
class Member :public Component {
public:
  Member(char* name) :Component(name) {}
  void Display(std::string str) {
    std::cout << str << name_ << std::endl;
  }
};

void main() {
  Leader *root0 = new Leader("Majordomo");
  Member *leaf_0a = new Member("Majordomo's assistant");
  Member *leaf_0b = new Member("Majordomo's secretary");

  root0->Add(leaf_0a);
  root0->Add(leaf_0b);

  Leader *node1 = new Leader("Department Manager"); 
  root0->Add(node1);

  Member *leaf_1a = new Member("Engineer A");
  Member *leaf_1b = new Member("Engineer B");
  node1->Add(leaf_1a);
  node1->Add(leaf_1b);

  root0->Display("--");

  std::cout << "//////////////////////////////" << std::endl << std::endl;

  root0->Remove(leaf_0a);
  root0->Display("==");

  std::cout << "//////////////////////////////" << std::endl << std::endl;

  root0->Remove(node1);
  root0->Display("--");

  std::cout << "//////////////////////////////" << std::endl;
  return;
}
