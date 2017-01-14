def conflict(state, nextX):
    nextY = len(state)
    for i in range(nextY):
        if abs(nextX-state[i]) in (0, nextY-i):
            return True
    return False

def queens(side_length, state=()):
    for pos in range(side_length):
        if not conflict(state, pos):
             if len(state) == side_length-1:
                yield (pos,)
             else:
                for result in queens(side_length, state+(pos,)):
                    yield (pos,)+result

def prettyprint(solution):
    def line(pos, length = len(solution)):
        return '.'*(pos) + 'X' + '.'*(length-pos-1)
    for pos in solution:
        print line(pos)


for solution in list(queens(4)):
    print solution
    prettyprint(solution)