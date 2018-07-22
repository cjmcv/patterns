#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Command.
    Encapsulate a request as an object,thereby
  letting you parameterize clients with different requests,
  queue or log requests,and support undoable operations.
  
  Invoker    =>   ( Command    =>   Receiver )
                      |
                ConcreteCommand
"""

# Receiver
class Engineer: 
  def __init__(self, name):
    self.name = name
  def coding(self):
    print("%s is coding." % (self.name))
  def meeting(self):
    print("%s is in a meeting." % (self.name))
    
# Command.
class Command:  
  def __init__(self, receiver):
    self.receiver = receiver
    
class CodingCommand(Command):
  def execute(self):
    self.receiver.coding()
      
class MeetingCommand(Command):
  def execute(self):
    self.receiver.meeting()
    
# Invoker
class Manager:
  def __init__(self):
    self.command_stack = []
  def add_command(self, command):
    self.command_stack.append(command)
  def action(self):
    for cmd in self.command_stack:
      cmd.execute()
  
if __name__ == '__main__':

  engineer = Engineer("Tom")
  manager = Manager()
  manager.add_command(CodingCommand(engineer))
  manager.add_command(MeetingCommand(engineer))
  
  manager.action()

