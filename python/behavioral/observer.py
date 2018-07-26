#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Observer. Define a one-to-many dependency 
    between objects so that when one object changes
  state,all its dependents are notified and updated
  automatically.

         Subject      <->       Observer
            |                      |                        
    ConcreteSubject          ConcreteObserver  
"""

class Observer: 
  def __init__(self):
    self.subject = None
    self.state = 0
    
  def set_subject(self, subject):
    self.subject = subject
    
  def update(self):
    if self.subject != None:
      self.state = self.subject.get_state()
    else:
      print("self.subject is None.")
      
  def get_state(self):
    return self.state
    

class Subject:
  def __init__(self):
    self.observer_list = []
    self.state = 0
    
  def add_observer(self, observer):
    self.observer_list.append(observer)
    observer.set_subject(self)

  def remove_observer(self, observer):
    self.observer_list.remove(observer)
    observer.set_subject = None
    
  def notify(self):
    for ob in self.observer_list:
      ob.update()
    
  def set_state(self, state):
    self.state = state
    
  def get_state(self):
    return self.state
    

if __name__ == '__main__':

  subject = Subject()
  
  # Create Observer
  observer1 = Observer()
  observer2 = Observer()
  
  print("subject: %d, observer1: %d, observer2: %d." 
    % (subject.get_state(), observer1.get_state(), observer2.get_state()))
  
  # Add observers
  subject.add_observer(observer1)
  subject.add_observer(observer2)
  
  # Change the state
  subject.set_state(2)
  subject.notify()
  
  # The state of the observer changes as the subject changes.
  print("subject: %d, observer1: %d, observer2: %d." 
    % (subject.get_state(), observer1.get_state(), observer2.get_state()))
  
  # Remove the observer2
  subject.remove_observer(observer2)
  
  subject.set_state(3)
  subject.notify()
  
  print("subject: %d, observer1: %d, observer2: %d." 
    % (subject.get_state(), observer1.get_state(), observer2.get_state()))
    