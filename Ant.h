#ifndef DEF_ANT
#define DEF_ANT

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include "World.h"

class World ; //this is just because World.h and Ant.h include themselves

class Ant
{
  int _x;
  int _y;
  std::vector<int> _pathX;
  std::vector<int> _pathY;
  int _pathLength;
  const double _depot;//how mush phero is deposited at each move

public:
  //destructor constructor
  ~Ant();
  Ant(int x, int y, double depot);//complete constructor
  Ant(World & , double);//constructor at world's start position and depot

  //print, equal
  void print() const;//print info on ant

  //getset
  int getX() const ;
  int getY() const ;
  std::vector<int> getPathX() const;
  std::vector<int> getPathY() const;

  //methods
  int chooseLab(World &) const;//randomly choose label of next cell
  void move(World &);//go to next step, update path and world phero
  bool isAtEnd(World &) const; //tells if ant is at end position of world

};

#endif
