# ants
`ants` is a optimization program which calculates the shortest path in a 2D discrete grid containing obstacles using an Ant Colony Optimization (ACO) algorithm.

The ACO's are a family of algorithms which are inspired by the collective behavior of ants in colonies (also referred to as Swarm Intelligence) and  compute  metaheuristic optimizations.

These methods have been particularly investigated by computer scientists such as Marco Dorigo and others after 1991. Please enjoy [this page](www.aco-metaheuristic.org) and of course [this one](en.wikipedia.org/wiki/Ant_colony_optimization_algorithms) for details.

In the algorithm used in `ants`, a 2D grid with obstacles and starting and end points in the grid are specified. The shortest free path in the grid is computed by letting ants randomly walk on the grid, starting from the starting point.

While they walk, the ants deposit pheromones on the way, and their steps are randomly chosen with a slight bias towards points with more pheromones. In the mean time, the pheromones are uniformly decreased on the whole grid at each step. Once an ant makes it to the end, its path is stored and an other ant starts off on the grid the previous ant left (with pheromones and all). With time, the ants start to all take the same path through the grid, and that path is (with a probability arbitrarily close to 1) the optimal path.

## Copying

This work is released under the GNU GPL3 License so feel free (as in freedom).

## Installing

All you need is the GNU C++ compiler (`g++`). Just run (with root priviledges) `make all`, then `make install` and `make clean` and  and you're done.

## Usage

This program calculates the shortest path on a 2D grid which can contain obstacles. It runs with the following command:

`ants "filename.map"`

Here, `filename.map` is a text file which contains all the info needed by the program for the calculation. Basically, it works like this (see `garden.map` for an example):

  1. The first line contains integers which succesively are : grid horizontal size, grid vertical size, horizontal coordinate of start point, vertical coordinate of start point, same for end point

  2. Then comes the description of the grid : 1 if the position contains an obstacle, 0 if none. Be sure to format the grid correctly (grid is rectangular, each line has the same number of 0's or 1's and starts on the very left)

The algorithm works by making ants randomly walk on the grid while depositing pheromones wherever they pass, so the program **will only accept your grid if**:

  1. The entire grid is **surrounded by a wall of obstacles** (or else the ants could walk off the grid into hyperspace!)

  2. The start and end points are **different** and not obstacles

  3. The start and end points are connected by a open path in the grid

Then after the command, the program should run and print out all the paths with optimal length.
