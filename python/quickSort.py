# coding:utf-8
class LNode():
	def __init__(self,item,next_=None):
		self.elem = item
		self.next = next_
class LinkedListUnderflow(ValueError):
	"""自定义异常"""
	def __init__(self, string):
		super(LinkedListUnderflow, self).__init__()
		self.string = string
		print self.string
		
class LLNode():
	"""继承自LNode"""
	def __init__(self):
		self.head = None
	# 判空
	def isEmpty(self):
		return self.head is None
	# 头插
	def prepend(self,item):
		self.head = LNode(item,self.head)
	# 删除头结点
	def pop(self,elem):
		if self.head is None:
			raise LinkedListUnderflow('头指针是空的')
		e = self.head.next
		self.head = self.head.next
		return e
	# 尾插
	def append(self,elem):
		if self.head is None:
			self.head = LNode(elem)
			return
		p = self.head
		while p.next is not None:
			p = p.next
		p.next = LNode(elem)
	# 尾删
	def popLast(self):
		if self.head is None:
			raise LinkedListUnderflow('头指针是空的')
		p = self.head
		if p.next is None:
			e = self.head.elem
			self.head = None
			return e
		while p.next.next is not None:
			p = p.next
		e = p.next.item
		p.next = None
		return e
	# 搜索
	def findElem(self,elem):
		index = 0
		p = self.head
		while p is not None:
			index += 1
			if p.elem == elem:
				return index
			p = p.next

	def printAll(self):
		p = self.head
		while p is not None:
			print ('%d ' % p.elem),
			if p.next is not None:
				print ',  ',
			p = p.next
if __name__ == '__main__':
    L = LLNode()
    for x in range(10):
        L.append(x)
    for x in range(10,20):
        L.prepend(x)
    L.printAll()
