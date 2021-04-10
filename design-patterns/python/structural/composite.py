#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Composite.
    Compose objects into tree structures 
  to represent part-whole hierarchies.Composite lets
  clients treat individual objects and compositions 
  of objects uniformly.

        Component                  Leader
         |    |                    |    |
      Leaf    Composite        Member  Leader
                                       |    |
                                    Member  Member   
"""

class Component(object):
  def __init__(self):
    self.name = ""
    
  def display(self, str):
    raise NotImplementedError("You should implement this.")
        
# Composite
class Leader(Component): 
  def __init__(self, name):
    self.name = name
    self.list = []
    
  def add(self, obj):
    self.list.append(obj)
    
  def remove(self, obj):
    self.list.remove(obj)

  def display(self, str):
    print(str + self.name)
    str = str + str;
    for obj in self.list:
      obj.display(str)
      
# Leaf
class Member(Component): 
  def __init__(self, name):
    self.name = name
    
  def display(self, str):
    print(str + self.name)
  
if __name__ == "__main__":
  
  root0 = Leader("Majordomo")
  leaf_0a = Member("Majordomo's assistant")
  leaf_0b = Member("Majordomo's secretary")
  
  root0.add(leaf_0a)
  root0.add(leaf_0b)
  
  node1 = Leader("Department Manager")
  root0.add(node1)
  
  leaf_1a = Member("Engineer A")
  leaf_1b = Member("Engineer B")
  node1.add(leaf_1a)
  node1.add(leaf_1b)

  root0.display("--")

  print("//////////////////////////////");

  root0.remove(leaf_0a);
  root0.display("==");

  print("//////////////////////////////");

  root0.remove(node1);
  root0.display("--");

  print("//////////////////////////////");