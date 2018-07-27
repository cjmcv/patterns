#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Strategy. 
    Define a family of algorithms, encapsulate each 
  one, and make them interchangeable.
  
         Context      ->              Strategy
                                      |     |
   ConcreteContext     ConcreteStrategy1  ConcreteStrategy2
"""

import types

# Context
class Context:
  def __init__(self, func=None):
    if func is not None:
      self.execute = types.MethodType(func, self)

  def execute(self):
    print("No strategy")

# ConcreteStrategy1
def strategy1(self):
  print("Strategy1")

# ConcreteStrategy2
def strategy2(self):
  print("Strategy2")

if __name__ == '__main__':
  s0 = Context()
  s1 = Context(strategy1)
  s2 = Context(strategy2)

  s0.execute()
  s1.execute()
  s2.execute()