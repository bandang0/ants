#ifndef DEF_ANT
#define DEF_ANT

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "World.h"

class World ;

class Ant
{
  int _x;
  int _y;
  std::vector<int> _pathX;
  std::vector<int> _pathY;
  int _pathLength;
  int _depot;//how mush phero is deposited at each step

public:
  //destructor constructor
  ~Ant();//destructor
  Ant(int x, int y, int depot);//complete constructor

  //print, equal
  void print();//print info on ant

  //getset
  int getX();
  int getY();

  //methods
  int chooseLab(World &);
  void move(World &);

};

#endif
