#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief: 
  Builder. 
    Separate the construction of a complex 
  object from its representation so that the 
  same construction process can create 
  different representations.
"""

# Builder.
class AnimalBuilder:  
  def __repr__(self):
    return 'Species: {0.species} | Color: {0.color}'.format(self)
    
class LionBuilder(AnimalBuilder):
  def build_species(self):
    self.species = "Lion"
  def build_color(self):
    self.color = "Yellow"
    
class TigerBuilder(AnimalBuilder):
  def build_species(self):
    self.species = "Tiger"
  def build_color(self):
    self.color = "Orange"
    
# Director.
def construct_animal(cls):
  animal = cls()
  animal.build_species()
  animal.build_color()
  return animal

  
if __name__ == '__main__':

  obj1 = construct_animal(LionBuilder)
  obj2 = construct_animal(TigerBuilder)
  
  print(obj1)
  print(obj2)