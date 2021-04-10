#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Mediator.
    Define an object that encapsulates how 
  a set of objects interact.Mediator promotes loose 
  coupling by keeping objects from referring to each 
  other explicitly,and it lets you vary their interaction
  independently.

  ( Renter and Landlord communicate through HouseMediator. 
    So Renter and Landlord don't need to meet each other. )
    
     Person     <=>     Mediator     <=>    Person
       |                   |                  |
     Renter           HouseMediator        Landlord
"""

# Mediator
class HouseMediator: 
  def __init__(self):
    self.renter = None
    self.landlord = None
    
  def set_renter(self, renter):
    self.renter = renter
    
  def set_landlord(self, landlord):
    self.landlord = landlord
    
  def send_message(self, message, sender):
    if (sender == self.renter and
        self.landlord != None):
      self.landlord.get_message(message)
    elif (sender == self.landlord and 
          self.renter != None):
      self.renter.get_message(message)
    else:
      print("No reciever.")
    
# Person
class Person:
  def __init__(self):
    self.mediator = None
    
  def send_message(self, message):
    if self.mediator != None:
      self.mediator.send_message(message, self)
    else:
      print("No mediator.")

# Person A.
class Landlord(Person):  
  def set_mediator(self, mediator):
    self.mediator = mediator
    self.mediator.set_landlord(self)
    
  def get_message(self, message):
    print("Landlord gets the message from Renter：%s" % (message))
  
# Person B.
class Renter(Person):  
  def set_mediator(self, mediator):
    self.mediator = mediator
    self.mediator.set_renter(self)

  def get_message(self, message):
    print("Renter gets the message from Landlord: %s" % (message))
    
  
if __name__ == '__main__':

  renter = Renter()
  landlord = Landlord()
  mediator = HouseMediator()
  
  renter.set_mediator(mediator);
  landlord.set_mediator(mediator);
  
  renter.send_message("I want to rent a house in ShenZhen.");
  landlord.send_message("I have a house in ShenZhen.");
  
