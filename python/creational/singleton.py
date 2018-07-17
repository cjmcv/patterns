#!/usr/bin/python
# -*- coding : utf-8 -*-

"""
brief: 
	Singleton.
"""

flag = 0
if flag == 0:
    # Using __dict__.
    # Different objects have the same state. 
	class Singleton(object):
		__shared_state = {}

		def __init__(self):
			self.__dict__ = self.__shared_state
			self.state = 'Init'

		def __str__(self):
			return self.state
	
elif flag == 1:
    # Using __new__.
    # The same object with the same state.
	class Singleton(object):
		def __init__(self):
			self.state = 'Init'
		
		def __str__(self):
			return self.state
			
		def __new__(cls):
			if not hasattr(cls, 'instance'):
				cls.instance = super(Singleton, cls).__new__(cls)
			return cls.instance
	
elif flag == 2:
    # Using decorator.
    # The same object with the same state.
	def decorator(cls):
		instances = {}
		def getinstance(*args,**kwargs):
			if cls not in instances:
				instances[cls] = cls(*args,**kwargs)
			return instances[cls]
		return getinstance
	
	# decorator(Singleton(object))
	@decorator
	class Singleton(object):
		def __init__(self):
			self.state = 'Init'
		def __str__(self):
			return self.state
		
if __name__ == '__main__':
	obj1 = Singleton()
	obj2 = Singleton()
	
	obj1.state = 'a'
	obj2.state = 'b'

	print('obj1: {0}'.format(obj1))
	print('obj2: {0}'.format(obj2))

	obj2.state = 'c'

	print('obj1: {0}'.format(obj1))
	print('obj2: {0}'.format(obj2))

	print('- obj1 id: {0}'.format(id(obj1)))
	print('- obj2 id: {0}'.format(id(obj2)))