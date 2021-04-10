#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Template.
    Method. Define the skeleton of an algorithm 
  in an operation,deferring some steps to subclasses.Template
  Method lets subclasses redefine certain steps of an algorithm 
  without changing the algorithm's.
"""

# Skeleton.
class Animal:
  def get_info(self):
    self.get_species();
    self.get_name();
    
  def get_species(self):
    print("Animal")
    
  def get_name(self):
    print("A")

# Subclass1. Redefine certain steps.
class Lion(Animal): 
  def get_species(self):
    print("Lion")
    
  def get_name(self):
    print("L")

# Subclass2.
class Tiger(Animal): 
  def get_species(self):
    print("Tiger")
    
  def get_name(self):
    print("T")

    
if __name__ == '__main__':
  l = Lion()
  t = Tiger()
  
  l.get_info()
  t.get_info()
