#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Facade. 
    Provide a unified interface to a set of
  interfaces in a subsystem. Facade defines a higher-level
  interface that makes the subsystem easier to use. 
"""

#####
class LetterProcess(object):
  def write_context(self, context):
    print("Context: " + context)

  def fill_envelope(self, address):
    print("Address: " + address)

  def putinto_envelope(self):
    print("put the letter into Envelope.")
  
  def send_letter(self):
    print("Send Letter.")
 
##### 
class PostOffice(object):
  def __init__(self):
    self.process = LetterProcess()
    
  def send_letter(self, context, address):
    self.process.write_context(context)
    self.process.fill_envelope(address)
    self.process.putinto_envelope()
    self.process.send_letter()

if __name__ == '__main__':

  post_office = PostOffice();

  # Use an interface to complete the entire process of sending letter.
  post_office.send_letter("Hello", "Beijing");
    