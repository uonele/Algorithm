# coding:utf-8
# N * N 的八皇后
# 检查是否存在冲突
# 不冲突：任意两个皇后不在同一行、同一列、且者在相互的对角线上。
# status 是皇后的位置，status[2] = 3 表示（2,3），2是行，3是列，行和列都从0开始

# position 代表列标
def conflect(status,position):
	length = len(status)
	# 遍历status
	for i in range(length):
		# 0指的是在同一列的情况
		if abs(position - status[i]) in (0, length-1):
			return True
	return False
def queen(length, status=()):
	for x in range(length):
		if not conflect(status,x):
			if (length - len(status)) == 1:
				yield (x,)
			else:
				# 递归，status增加
				for y in queen(length,status+(x,)):
					yield (x,)+y
# 格式化输出
def goodlook(solution):
	length = len(solution)
	def line(pos):
		return '.'*(pos) + 'X' + '.'*(length-pos-1)

	for pos in solution:
		print line(pos)

for solution in list(queen(4)):
	goodlook(solution)


