import random
import math

ant_x = 0 # Ant position
ant_y = 0

start_x = 5 # Starting position
start_y = 8

end_x = 5 # Ending position
end_y = 1

path = [] # Final path
path_length = math.inf # Final path length
path_accumulator = 0 # To know when to stop the algorithm
# We will stop the algorithm when the same path is found 10 times in a row

current = [] # Path of the current ant
current_length = 0 # Length of the current ant's path

passed = [] # Passed cells for no infinite loop

bool_map = [[1,1,1,1,1,1,1,1,1,1,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,0,0,0,0,0,0,0,0,0,1],[1,1,1,1,1,1,1,1,1,1,1]] 
# Map of booleans repsresenting obstacles

ph_map = [[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1]] 
# Map of pheromones represented by ints to calculate the probability for the next cell, default value is 1 for all cells

def check_list (l,a,b) :
    a = False
    for i in range (len (l)):
        if l[i] == (a,b):
            a = True
    return a

def  move (x,y) :
    
    #global current
    #global passed
    global ant_x
    global ant_y
    global current_length

    a_x = x-1 # Positions of the neighboor cells
    b_x = x-1
    c_x = x-1
    d_x = x
    e_x = x
    f_x = x+1
    g_x = x+1
    h_x = x+1

    a_y = y-1
    b_y = y
    c_y = y+1
    d_y = y+1
    e_y = y-1
    f_y = y+1
    g_y = y
    h_y = y-1
    
    
    a_ph = ph_map[x-1][y-1] # Pheromones on each neighboor cell
    b_ph = ph_map[x-1][y]
    c_ph = ph_map[x-1][y+1]
    d_ph = ph_map[x][y+1]
    e_ph = ph_map[x][y-1]
    f_ph = ph_map[x+1][y+1]
    g_ph = ph_map[x+1][y]
    h_ph = ph_map[x+1][y-1]
    
    # The idea is to fill a list with "pheromone times" of each neighboor cell's position and the pick a random element of the list for the ant's next position

    l = []

    if not bool_map[a_x][a_y] and not check_list(passed,a_x,a_y):
        for i in range (a_ph):
            l.append((a_x,a_y))

    if not bool_map[b_x][b_y] and not check_list(passed,b_x,b_y):
        for i in range (b_ph):
            l.append((b_x,b_y))

    if not bool_map[c_x][c_y] and not check_list(passed,c_x,c_y):
        for i in range (c_ph):
            l.append((c_x,c_y))

    if not bool_map[d_x][d_y] and not check_list(passed,d_x,d_y):
        for i in range (d_ph):
            l.append((d_x,d_y))

    if not bool_map[e_x][e_y] and not check_list(passed,e_x,e_y):
        for i in range (e_ph):
            l.append((e_x,e_y))

    if not bool_map[f_x][f_y] and not check_list(passed,f_x,f_y):
        for i in range (f_ph):
            l.append((f_x,f_y))

    if not bool_map[g_x][g_y] and not check_list(passed,g_x,g_y):
        for i in range (g_ph):
            l.append((g_x,g_y))

    if not bool_map[h_x][h_y] and not check_list(passed,h_x,h_y):
        for i in range (h_ph):
            l.append((h_x,h_y))
    if l != [] :
        rd = random.randint(0,len(l)-1)

        (swap_x,swap_y) = l[rd] # Necessary swap tupple for Python to see the new position as two variables that can be independantely accessed

        ph_map[ant_x][ant_y] += 1 # Increment the pheromone on cell before leaving it

        ant_x = swap_x # Update ant's position
        ant_y = swap_y
    
        current.append((ant_x,ant_y)) # Update current path after moving
        current_length += 1
        passed.append((ant_x,ant_y))
    
def move_call (x,y): # Function that loops untill ant is done each path
    while ant_x != end_x or ant_y != end_y:
        move (ant_x,ant_y)
    passed = []
    


while  path_accumulator < 1 : # Function that loops untill the final path is found
    move_call (ant_x,ant_y)
    
for i in range (len(path)):
    print(path[i])
