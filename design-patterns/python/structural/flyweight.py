#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Flyweight. 
    Use sharing to support large numbers 
  of fine-grained objects efficiently.
  
  FlyweightFactory   <-->     Flyweight
                               |     |
                ConcreteFlyweight  UnsharedConcreteFlyweight
                
References:
  http://dongweiming.github.io/python-flyweight.html
"""

class FlyweightFactory(object):
  def __init__(self, cls):
    self._cls = cls
    self._instances = dict()
    
  # The number and type of parameters of the cls are 
  # abstracted by using *args and **kargs.
  def get_instance(self, *args, **kargs):
    # If the key is in the dictionary, return the value 
    # corresponding to the key.
    # Otherwise, insert the key into the dictionary.
    return self._instances.setdefault(
      (args, tuple(kargs.items())),
      self._cls(*args, **kargs))

class ConcreteFlyweightA(object):
  def __init__(self, a, b, c):
    self.a = a
    self.b = b
    self.c = c

class ConcreteFlyweightB(object):
  def __init__(self, x, y, z):
    self.x = x
    self.y = y
    self.z = z

if __name__ == '__main__':

  FlyweightA = FlyweightFactory(ConcreteFlyweightA)
  FlyweightB = FlyweightFactory(ConcreteFlyweightB)

  print(FlyweightA.get_instance(1, 2, 3) is 
    FlyweightA.get_instance(1, 2, 3))
  print(FlyweightB.get_instance('a', 'b', 'c') is 
    FlyweightB.get_instance('a', 'b', 'c'))
  print(FlyweightA.get_instance(1, 2, 3) is not 
    FlyweightB.get_instance(1, 2, 3))
  print(FlyweightA.get_instance(1, 2, 3) is not 
    FlyweightA.get_instance(1, 2, 5))     
