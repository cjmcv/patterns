#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
    Factory method. Use multiple factories for 
  multiple products

pattern:
  Factory method:
    Define an interface for creating an object,
  but let subclasses decide which class to
  instantiate.Factory Method lets a class defer
  instantiation to subclasses.
 
    AbstractProduct     < = >        AbstractFactory
      |         |                     |          |
  ProductA  ProductB    FactoryA(for ProductA)  FactoryB(for ProductB)
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

# AbstractFactory
class Factory():
    def create_animal(self):
        pass
        
# Factory
class LionFactory(Factory):
  def __init__(self):
    print('Initialize LionFactory.')
  def create_animal(self):
      return Lion()
 
class TigerFactory(Factory):
  def __init__(self):
    print('Initialize TigerFactory.')
  def create_animal(self):
      return Tiger()
      
if __name__ == '__main__':
  lion_factory = LionFactory()
  tiger_factory = TigerFactory()
  
  obj1 = lion_factory.create_animal()
  obj2 = tiger_factory.create_animal()
	
  print('obj1: {0}'.format(obj1))
  print('obj2: {0}'.format(obj2))