import random
import math

ant_x = 0 # Ant position
ant_y = 0

start_x = 0 # Starting position
start_y = 0

end_x = 0 # Ending position
end_y = 0

path = [] # Final path
path_length = math.inf # Final path length
path_accumulator = 0 # To know when to stop the algorithm
# We will stop the algorithm when the same path is found 10 times in a row

current = [] # Path of the current ant
current_length = 0 # Length of the current ant

ph_map = [[]] # Map of pheromone quantities represented by ints to calculate the probability for the next cell, default value is 1 for all cell
bool_map = [[]] # Map of booleans representing obstacles

def pheromone_count (x,y) : # Counts the total number of pheromones surrounding the current ant's cell's
    return(ph_map[x-1][y-1] + ph_map[x-1][y] + ph_map[x-1][y+1] + ph_map[x][y+1] + ph_map[x][y-1] + ph_map[x+1][y+1] + ph_map[x+1][y] + ph_map[x+1][y-1])

def move (x,y) :
    
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

    if not bool_map[a_x][a_y]:
        for i in range (a_ph):
            l.append((a_x,a_y))

    if not bool_map[a_x][a_y]:
        for i in range (b_ph):
            l.append((b_x,b_y))

    if not bool_map[a_x][a_y]:
        for i in range (c-ph):
            l.append((c_x,c_y))

    if not bool_map[a_x][a_y]:
        for i in range (d_ph):
            l.append((d_x,d_y))

    if not bool_map[a_x][a_y]:
        for i in range (e_ph):
            l.append((e_x,e_y))

    if not bool_map[a_x][a_y]:
        for i in range (f_ph):
            l.append((f_x,f_y))

    if not bool_map[a_x][a_y]:
        for i in range (g_ph):
            l.append((g_x,g_y))

    if not bool_map[a_x][a_y]:
        for i in range (h_ph):
            l.append((h_x,h_y))

    rd = random.randint(0,len(l)-1)

    (swap_x,swap_y) = l[rd] # Necessary swap tupple for Python to see the new position as two variables that can be independantely accessed

    ph_map[ant_x][ant_y] += 1 # Increment the pheromone on cell before leaving it

    ant_x = swap_x # Update ant's position
    ant_y = swap_y
    
    current.append((ant_x,ant_y)) # Update current path after moving
    current_length += 1
    
def move_call (x,y): # Function that loops untill ant is done each path
    while ant_x != end_x or ant_y != end_y:
        move (ant_x,ant_y)
    


while  path_accumulator < 10 : # Function that loops untill the final path is found
    move_call (ant_x,ant_y)
    
for i in range (len(path)):
    print(path[i])
