import random

class Ants:
    pass

class Map:
    pass

b = Ants()
b.pos = (4,5)

path = ([],800)
current = ([],0)
ph_map = [[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[
0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0]]
bool_map = [[1,1,1,1,1,1,1,1,1,1,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[
1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,1,1,1,1,1,1,1,1,1,1]]
start = (5,8)
end = (5,1)

def move (a):
    global current
    r = random.randint(0,7)
    ph_map[a.pos[0]][a.pos[1]] += 1
    if r == 0 and bool_map[a.pos[0]][a.pos[1]-1] != True :
    	a.pos = (a.pos[0],a.pos[1]-1)
    	(current [0].append(a.pos))
    	current [1] = (current [1] + 1)
    elif r == 1 and bool_map[a.pos[0]-1][a.pos[1]-1] != True :
    	a.pos = (a.pos[0]-1,a.pos[1])
    	a.pos = (a.pos[0],a.pos[1]-1)
    	(current [0].append(a.pos))
    	current [1] = (current [1] + 1)
    elif r == 2 and bool_map[a.pos[0]-1][a.pos[1]] != True :
    	a.pos = (a.pos[0]-1,a.pos[1])
    	(current [0].append(a.pos))
    	current [1] = (current [1] + 1)
    elif r == 3 and bool_map[a.pos[0]-1][a.pos[1]+1] != True :
    	a.pos = (a.pos[0]-1,a.pos[1])
    	a.pos = (a.pos[0],a.pos[1]+1)
    	(current [0].append(a.pos))
    	current [1] =(current [1] + 1)
    elif r == 4 and bool_map[a.pos[0]][a.pos[1]+1] != True :
    	a.pos = (a.pos[0],a.pos[1]+1)
    	(current [0].append(a.pos))
    	current [1] =(current [0],current [1] + 1)
    elif r == 5 and bool_map[a.pos[0]+1][a.pos[1]+1] != True :
    	a.pos = (a.pos[0]+1,a.pos[1])
    	a.pos = (a.pos[0],a.pos[1]+1)
    	(current [0].append(a.pos))
    	current [1] =current [1] + 1
    elif r == 6 and bool_map[a.pos[0]+1][a.pos[1]] != True :
    	a.pos = (a.pos[0]+1,a.pos[1])
    	((current [0].append(a.pos))
    	current [1] = (current [1] + 1)
    elif r == 7 and bool_map[a.pos[0]+1][a.pos[1]-1] != True :
    	a.pos = (a.pos[0]+1,a.pos[1])
    	a.pos = (a.pos[0],a.pos[1]-1)   
    	((current [0].append(a.pos))
    	current [1] = (current [1] + 1)   
    else:
    	move(a)

def main ():


    acc = 0
    while acc < 500 :
        a = Ants()
        a.pos = (start[0],start[1])

        current = ([],0)

        while a.pos != end :
            move(a)

        if current [1] > path [1]:
            current = ([],0)

        if current [1] == path[1]:
            path[0].append(current [0])
            current = ([],0)

        else:
            path = current
            current = ([],0)
        acc += 1

    return path



print(main())
