#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Adapter. 
    Convert the interface of a class into
  another interface clients expect.Adapter lets classes 
  work together that couldn't otherwise because of 
  incompatible interfaces.
  
References:
  https://github.com/faif/python-patterns/blob/master/structural/adapter.py
"""

# Adaptee.
class Dog(object):
  def __init__(self):
    self.name = "Dog"
  def bark(self):
    return "woof!"

class Cat(object):
  def __init__(self):
    self.name = "Cat"
  def meow(self):
    return "meow!"

# Adapter.
class Adapter(object):
  def __init__(self, obj, **adapted_methods):
    """We set the adapted methods in the object's dict"""
    self.obj_bak = obj
    self.__dict__.update(adapted_methods)

  def original_dict(self):
    return self.obj_bak.__dict__

if __name__ == "__main__":

  objects = []
  dog = Dog()
  print(dog.__dict__)
  objects.append(Adapter(dog, make_noise=dog.bark))
  print(objects[0].__dict__)
  print(objects[0].original_dict())
  cat = Cat()
  objects.append(Adapter(cat, make_noise=cat.meow))

  # The function make_noise is converted from 
  # the second input parameter of the constructor of Adapter.
  for obj in objects:
    print("A {0} goes {1}".format(obj.obj_bak.name, obj.make_noise()))

