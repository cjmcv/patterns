#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  State. 
    Allow an object to alter its behavior 
  when its internal state changes.The object will 
  appear to change its class.
  
      Context       <===>       TCPState
        |                        |    |
    TCPContext           TCPListen  TCPAccepted  
                         TCPConnected  TCPClose 
"""
# Context.
class TCPContext: 
  def __init__(self):
    self.state = None
    
  def initialize(self):
    self.state = TCPListen()
    
  def set_state(self, state):
    self.state = state
    
  def request(self):
    self.state.handle(self)
    
# State.
class TCPState(object):
  def __new__(cls):
    if not hasattr(cls, 'instance'):
      cls.instance = super(TCPState, cls).__new__(cls)
    return cls.instance
    
class TCPClose(TCPState):
  def handle(self, context):
    print("TCP STAT Close.")
    context.set_state(TCPListen());

class TCPListen(TCPState):
  def handle(self, context):
    print("TCP STAT Listening.")
    context.set_state(TCPAccepted());

class TCPAccepted(TCPState):
  def handle(self, context):
    print("TCP STAT Accepted.")
    context.set_state(TCPConnected());
    
class TCPConnected(TCPState):
  def handle(self, context):
    print("TCP STAT Connected.")
    context.set_state(TCPClose());
    
    
if __name__ == '__main__':

  print("Test Singleton: ")
  a = TCPClose()
  b = TCPClose()
  c = TCPListen()
  d = TCPListen()
  
  print('id: {0}'.format(id(a)))
  print('id: {0}'.format(id(b)))
  print('id: {0}'.format(id(c)))
  print('id: {0}'.format(id(d)))
  print("**")
   
  print("Test State: ")
  
  context = TCPContext()
  context.initialize()
  
  context.request()
  context.request()
  context.request()
  context.request()
  
  print("**")
  
  context.request()
  context.request()
  context.request()
  context.request()
  