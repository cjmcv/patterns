#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief: 
  Prototype.
    Specify the kinds of objects to
  create using a prototypical instance,and 
  create new objects by copying this prototype.
    Using copy and deepcopy in python is enough.
"""

from copy import copy, deepcopy

class NormalClass:
  def __init__(self):
    self.state = 'A'
  def __str__(self):
    return self.state
  def clone(self):
    return (self)
  def deep_clone(self):
    return deepcopy(self)

if __name__ == '__main__':
  obj1 = NormalClass()
  obj2 = obj1.clone()
  obj3 = obj1.deep_clone()
	
  print('obj1: {0}'.format(obj1))   # A
  print('obj2: {0}'.format(obj2))   # A
  print('obj3: {0}'.format(obj3))   # A
  
  obj2.state = "B"
  print('obj1: {0}'.format(obj1))   # B
  print('obj2: {0}'.format(obj2))   # B
  print('obj3: {0}'.format(obj3))   # A
  
  obj3.state = "C"
  print('obj1: {0}'.format(obj1))   # B
  print('obj2: {0}'.format(obj2))   # B
  print('obj3: {0}'.format(obj3))   # C