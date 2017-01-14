#! /usr/bin/env python
#coding=utf-8
# 	python实现的哈希表

#	处理冲突的方法是开放地址法，冲突表达式为Hi=（H（key）+1）mod m，m为表长
#	实现哈希表（线性地址再散列）

def ChangeKey(key,m,di):
    newkey = (key + di) % m
    return newkey

a = raw_input("Please entry the numbers:\n").split()
m = len(a)

dict = {}

for i in a:
    key = int(i) % m
    if "%s" % key in dict:
        NewKey = ChangeKey(key,m,1)

        while "%s" % NewKey in dict:         #因为下面的dict01的key值是以字符串来保存，因此这里作判断时也要用字符串格式
            NewKey = ChangeKey(NewKey,m,1)
        dict["%s" % NewKey] = int(i)
    else:
        dict["%s"%key] = int(i)
print dict