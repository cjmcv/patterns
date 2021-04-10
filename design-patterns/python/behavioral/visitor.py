#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Visitor. 
    Represent an operation to be performed 
  on the elements of an object structure. Visitor lets 
  you define a new operation without changing the classes
  of the elements on which it operates.

  <ObjectStructure>      <Element>              <Visitor>
    School  (create)->   Engineer       <==>      HR
                            |                     | |
                  SoftwareEngineer     IncomeVisitor VacationVisitor
"""

# ConcreteVisitor1.
class IncomeVisitor:
  def visit(self, engineer):
    engineer.show_income()
    
# ConcreteVisitor2.    
class VacationVisitor:
  def visit(self, engineer):
    engineer.show_vacation()

# ConcreteElement
class SoftwareEngineer: 
  def __init__(self, name, income, vacation):
    self.name = name
    self.income = income
    self.vacation = vacation
    
  def accept(self, visitor):
    visitor.visit(self)
    
  def show_income(self):
    print("%s's income: %d" % (self.name, self.income))
    
  def show_vacation(self):
    print("%s's vacation: %d" % (self.name, self.vacation))
 
# ObjectStructure. (Element producer).
# It is typically contains multiple containers of different types 
# and interfaces, such as List, Set, Map, etc. 
class School:
  def create_software_engineer(self, name, income, vacation):
    return SoftwareEngineer(name, income, vacation)
    
    
if __name__ == '__main__':

  # Create two visitors  
  v1 = IncomeVisitor()
  v2 = VacationVisitor()

  # Create Engineers by School.
  THU = School()
  Tom = THU.create_software_engineer("Tom", 25000, 14);
  Jimmy = THU.create_software_engineer("Jimmy", 36000, 6);

  Tom.accept(v1);
  Tom.accept(v2);

  Jimmy.accept(v1);
  Jimmy.accept(v2);
  
  