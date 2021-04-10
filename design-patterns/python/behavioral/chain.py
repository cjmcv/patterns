#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief:
  Chain.
    Avoid coupling the sender of a request to its 
  receiver by giving more than one object a chance to 
  handle the request.Chain the receiving objects and pass 
  the request along the chain until an object handles it.

       Action    ->    Handler
                       |     |
                 Handler1 -> Handler2

  Request -> ServerLevel1 -> ServerLevel2 -> ServerLevel3.
"""

# Request
class Request:  
  def __init__(self, level):
    self.level = level
  def get_level(self):
    return self.level

# Handler.
class Server:  
  def set_next_level(self, server):
    self.next_server = server
    
class ServerLevel1(Server):
  def __init__(self):
    self.level = 1
  def get_request(self, request):
    if self.level < request.get_level():
      if self.next_server != None:
        self.next_server.get_request(request)
      else:
        print("The request was rejected.")
    else:
      print("The request is accepted by the Server of Level 1.")
      
class ServerLevel2(Server):
  def __init__(self):
    self.level = 2
  def get_request(self, request):
    if self.level < request.get_level():
      if self.next_server != None:
        self.next_server.get_request(request)
      else:
        print("The request was rejected.")
    else:
      print("The request is accepted by the Server of Level 2.")
  
class ServerLevel3(Server):
  def __init__(self):
    self.level = 3
  def get_request(self, request):
    if self.level < request.get_level():
      if self.next_server != None:
        self.next_server.get_request(request)
      else:
        print("The request was rejected.")
    else:
      print("The request is accepted by the Server of Level 3.")
      
if __name__ == '__main__':

  server1 = ServerLevel1()
  server2 = ServerLevel2()
  
  server1.set_next_level(server2)
  server2.set_next_level(None)
  
  request = Request(2)
  server1.get_request(request)
  