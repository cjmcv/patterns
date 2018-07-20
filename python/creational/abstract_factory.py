#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
pattern:
  Factory method:
    Define an interface for creating an object,
  but let subclasses decide which class to
  instantiate.Factory Method lets a class defer
  instantiation to subclasses.

    AbstractProduct1     < = >     AbstractProduct2
      |         |                     |          |
  ProductA1  ProductB1           ProductA2  ProductB2

                     AbstractFactory 
                      |           | 
                FactoryA         FactoryB
      (for ProductA1 and A2)  (for ProductB1 and B2)

***************************************************************

        MaleAnimal     < = >     FemaleAnimal
        |        |               |          |
    MaleLion  MaleTiger     FemaleLion  FemaleTiger
;
                        AnimalFactory
                        |           |
               LionFactory         TigerFactory
  (for MaleLion and FemaleLion)  (for MaleTiger and FemaleTiger) 
"""

##########################################
# AbstractProduct1
class MaleAnimal:
  def __init__(self):
    self.boundary = 'MaleAnimal'
    self.state = self.boundary
  def __str__(self):
    return self.state
	
# ProductA1
class MaleLion(MaleAnimal):
  def __init__(self):
    super(MaleLion, self).__init__();
    self.state = self.boundary + ' - MaleLion'
  def __str__(self):
    return self.state
    
# ProductB1
class MaleTiger(MaleAnimal):
  def __init__(self):
    super(MaleTiger, self).__init__();
    self.state = self.boundary + ' - MaleTiger'	
  def __str__(self):
    return self.state

##########################################
# AbstractProduct2
class FemaleAnimal:
  def __init__(self):
    self.boundary = 'FemaleAnimal'
    self.state = self.boundary
  def __str__(self):
    return self.state
	
# ProductA2
class FemaleLion(FemaleAnimal):
  def __init__(self):
    super(FemaleLion, self).__init__();
    self.state = self.boundary + ' - FemaleLion'
  def __str__(self):
    return self.state
    
# ProductB2
class FemaleTiger(FemaleAnimal):
  def __init__(self):
    super(FemaleTiger, self).__init__();
    self.state = self.boundary + ' - FemaleTiger'	
  def __str__(self):
    return self.state
 
########################################## 
# AbstractFactory
class AnimalFactory():
  def create_male_animal(self):
    pass
  def create_female_animal(self):
    pass
        
# FactoryA
class LionFactory(AnimalFactory):
  def __init__(self):
    print('Initialize LionFactory.')
  def create_male_animal(self):
      return MaleLion()
  def create_female_animal(self):
      return FemaleLion()    

# FactoryB      
class TigerFactory(AnimalFactory):
  def __init__(self):
    print('Initialize TigerFactory.')
  def create_male_animal(self):
      return MaleTiger()
  def create_female_animal(self):
      return FemaleTiger()  
      
      
if __name__ == '__main__':
  lion_factory = LionFactory()
  tiger_factory = TigerFactory()
  
  obj_a1 = lion_factory.create_male_animal()
  obj_a2 = lion_factory.create_female_animal()
  obj_b1 = tiger_factory.create_male_animal()
  obj_b2 = tiger_factory.create_female_animal()
	
  print('obj_a1: {0}'.format(obj_a1))
  print('obj_a2: {0}'.format(obj_a2))
  print('obj_b1: {0}'.format(obj_b1))
  print('obj_b2: {0}'.format(obj_b2))