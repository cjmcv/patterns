#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Bridge. 
    Decouple an abstraction from its 
  implementation so that the two can vary 
  independently.

      Computer    <==>    OS
       |    |            |  |
     IBM    HP      Windows  Linux   
"""

# Implementor A
class Windows(object):
  def run(self):
    print("Running Windows!")

# Implementor B
class Linux(object):
  def run(self):
    print("Running Linux!")

# Abstraction
class Computer(object):
  def __init__(self):
    self.system = None
    
  def install_system(self, system):
    self.system = system  
  
# RefinedAbstraction A
class IBM(Computer):    
  def run(self):
    print("Open the IBM computer.");
    if self.system != None:
      self.system.run()
    else:
      print("The computer has not yet installed an operating system.")

# RefinedAbstraction B   
class HP(Computer):
  def run(self):
    print("Open the HP computer.");
    if self.system != None:
      self.system.run()
    else:
      print("The computer has not yet installed an operating system.")
      
if __name__ == "__main__":
  
  os_win = Windows()
  os_linux = Linux()
  
  device1 = IBM()
  device2 = HP()
  
  device1.install_system(os_win)
  device2.install_system(os_linux)
  
  device1.run()
  device2.run()