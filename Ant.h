#ifndef DEF_ANT
#define DEF_ANT

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "World.h"

class World ; //this is just because World.h and Ant.h include themselves

class Ant
{
  int _x;
  int _y;
  std::vector<int> _pathX;
  std::vector<int> _pathY;
  int _pathLength;
  int _depot;//how mush phero is deposited at each move

public:
  //destructor constructor
  ~Ant();
  Ant(int x, int y, int depot);//complete constructor
  Ant(World & , int);//constructor at world's start position and depot

  //print, equal
  void print();//print info on ant

  //getset
  int getX();
  int getY();
  std::vector<int> getPathX();
  std::vector<int> getPathY();

  //methods
  int chooseLab(World &);//randomly choose label of next cell
  void move(World &);//go to next step, update path and world phero
  bool isAtEnd(World &); //tells if ant is at end position of world

};

#endif
