#!/usr/bin/python
# -*- coding : utf-8 -*-

""" 
brief:
  Proxy. 
    Provide a surrogate or placeholder for
  another object to control access to it.

              Subject
              |     |    
    RealSubject <-  Proxy
"""

class RealSubject(object):
  def request(self):
    print("RealSubject Request")
    
class Proxy(object):
  def __init__(self):
    self._subject = None
    
  def set_subject(self, subject):
    self._subject = subject
    
  def request(self):
    if self._subject != None:
      self._subject.request()
    else:
      print("No Subject.")

if __name__ == '__main__':

  subject = RealSubject()
  proxy = Proxy()
  proxy.set_subject(subject)
  # Use a proxy to do something for the subject.
  proxy.request()