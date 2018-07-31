#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Decorator. 
    Attach additional responsibilities to an
  object dynamically keeping the same interface.Decorators
  provide a flexible alternative to subclassing for extending
  functionality.

           ---- Pet -------
          |      |         |
         Dog    Cat    PetDecorator
                         |      |
                    Coloring  Dressing
"""

#####
class Pet(object):
  def __init__(self):
    self.attribute = "";
  def show_decorate(self):
    print(self.attribute)
 
##### 
class Dog(Pet):
  def __init__(self):
    self.attribute = "Dog-";

#####
class PetDecorator(Pet):
  def __init__(self, pet):
    self.pet = pet
    
class Coloring(PetDecorator):
  def __init__(self, pet):
    PetDecorator.__init__(self, pet) 
    self.attribute = pet.attribute + "Coloring-"
    
class Dressing(PetDecorator):
  def __init__(self, pet):
    PetDecorator.__init__(self, pet) 
    self.attribute = pet.attribute + "Dressing-"


if __name__ == '__main__':

  pet = Dog()
  pet_color = Coloring(pet)
  pet_color_dress = Dressing(pet_color)
  pet_color_dress_color = Coloring(pet_color_dress)
  
  pet.show_decorate()
  print("////////////////")

  pet_color.show_decorate()
  print("////////////////")
  
  pet_color_dress_color.show_decorate()
  print("////////////////")
    