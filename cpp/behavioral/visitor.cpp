/*!
* \brief   Visitor. Represent an operation to be performed 
*       on the elements of an object structure. Visitor lets 
*       you define a new operation without changing the classes
*       of the elements on which it operates.
*
*  <ObjectStructure>      <Element>                <Visitor>
*     School  (create)->   Engineer       <==>        HR
*                             |                       | |
*                    SoftwareEngineer     IncomeVisitor VacationVisitor
*/

#include <iostream>
#include <string>

class Engineer;

// Visitor.
class HR {
public:
  virtual void Visit(Engineer *element) {};
};

// Element
class Engineer  {
public:
  virtual void ShowIncome() = 0;
  virtual void ShowVacation() = 0;
  // Allow a visitor to access it.
  virtual void Accept(HR *visitor) {};
};

// ConcreteElement
class SoftwareEngineer : public Engineer {
public:
  SoftwareEngineer(std::string name, int income, int vacation) {
    this->name_ = name;
    this->income_ = income;
    this->vacation_ = vacation;
  }

  void Accept(HR *visitor) {
    visitor->Visit(this);
  }

  // Show something or do something.
  void ShowIncome() {
    std::cout << name_ << "'s income: " << income_ << std::endl;
  }
  void ShowVacation() {
    std::cout << name_ << "'s vacation: " << vacation_ << std::endl;
  }

public:
  std::string name_;
  int income_;
  int vacation_;
};

// ConcreteVisitor.
class IncomeVisitor : public HR {
public:
  void Visit(Engineer *element) {
    element->ShowIncome();
  }
};

// ConcreteVisitor.
class VacationVisitor : public HR {
public:
  void Visit(Engineer *element) {
    element->ShowVacation();
  }
};

// ObjectStructure. (Element producer).
// It is typically contains multiple containers of different types 
// and interfaces, such as List, Set, Map, etc.
class School {
public:
  static Engineer *CreateSoftwareEngineer(std::string name,
    int income, int vacation) {
    Engineer *t = new SoftwareEngineer(name, income, vacation);
    return t;
  }
};

void main() {
  // Create two visitors  
  HR *v1 = new IncomeVisitor();
  HR *v2 = new VacationVisitor();

  // Create Engineers by School.
  Engineer *Tom = School::CreateSoftwareEngineer("Tom", 25000, 14);
  Engineer *Jimmy = School::CreateSoftwareEngineer("Jimmy", 36000, 6);

  Tom->Accept(v1);
  Tom->Accept(v2);

  Jimmy->Accept(v1);
  Jimmy->Accept(v2);

  delete v1;
  delete v2;
  delete Tom;
  delete Jimmy;
}