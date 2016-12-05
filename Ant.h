#ifndef DEF_ANT
#define DEF_ANT

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Path.h"
#include "Cell.h"
#include "World.h"

class Ant
{
  int number_;
  Path curPath_;
  Cell curCell_;
  Cell nextCell_;

public:
  Ant();// standard constructor
  ~Ant();
  Ant(int num, Cell firstCell);//complete constructor


  void evolve();
  void chooseNext(World world);
  void deposit(double depot);
};

#endif
