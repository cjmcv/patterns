#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Memento.
    Without violating encapsulation,capture
  and externalize an object's internal state so that the
  object can be restored to this state later.
  
          Originator         <==>      Caretaker
              |                           |
   Create and restore Memento    Save and provide Memento
"""

# Memento. Responsible for storing the internal state of the Originator
#       and providing the internal state of the Originator as needed.
class Memento: 
  def __init__(self, state):
    self.state = state
    
  def set_state(self, state):
    self.state = state
    
  def get_state(self):
    return self.state
    
# Originator. It is responsible for recording the internal state of the
#        current moment, defining which states belong to the backup scope,
#        and creating and restoring the memo data.
class Originator:
  def __init__(self, state):
    self.state = state
    
  def create_memento(self):
    return Memento(self.state)

  def restore_from_memento(self, memento):
    self.state = memento.get_state();
    
  def set_state(self, state):
    self.state = state
    
  def get_state(self):
    return self.state  
    
# Caretaker. Manage, save and provide the Memento.
class Caretaker:  
  def set_memento(self, memento):
    self.memento = memento

  def get_memento(self):
    return self.memento
  
if __name__ == '__main__':

  # Initialize.
  org = Originator("A")
  print("%s" %(org.get_state()))
  
  # Save.
  taker = Caretaker();
  taker.set_memento(org.create_memento());
  
  # Change.
  org.set_state("B")
  print("%s" %(org.get_state()))
  
  # Restore.
  org.restore_from_memento(taker.get_memento());
  print("%s" %(org.get_state()))
  
