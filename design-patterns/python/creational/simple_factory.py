#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief: 
	Simple factory. Receive a parameter to select
	the object you want to constructe.
	
pattern:
	Factory method.
	Define an interface for creating an object,
	but let subclasses decide which class to
	instantiate.Factory Method lets a class defer
	instantiation to subclasses
	
	AbstractProduct  < = >  Factory(for all of the products)
		|         |
	ProductA  ProductB
"""

# AbstractProduct
class Animal:
  def __init__(self):
    self.boundary = 'Animal'
    self.state = self.boundary
  def __str__(self):
    return self.state
	
# Product
class Lion(Animal):
  def __init__(self):
    super(Lion, self).__init__();
    self.state = self.boundary + ' - Lion'
  def __str__(self):
    return self.state
	
class Tiger(Animal):
  def __init__(self):
    super(Tiger, self).__init__();
    self.state = self.boundary + ' - Tiger'	
  def __str__(self):
    return self.state

# Factory
flag = 0
if flag == 0:

  class Factory:
    def __init__(self):
      print('Initialize factory A.')
    def create_animal(self, species):
      if species == "Lion":
        return Lion()
      if species == "Tiger":
        return Tiger()
        
else:

  class Factory:
    def __init__(self):
      print('Initialize factory B.')
      self.map = {
        'Lion': Lion(),
        'Tiger': Tiger()
      }
    def create_animal(self, species):
      return self.map[species]
      
if __name__ == '__main__':
  factory = Factory()
  
  obj1 = factory.create_animal("Lion")
  obj2 = factory.create_animal("Tiger")
	
  print('obj1: {0}'.format(obj1))
  print('obj2: {0}'.format(obj2))