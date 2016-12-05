#ifndef DEF_WORLD
#define DEF_WORLD


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Cell.h"

class World
{
  int sizeX_;
  int sizeY_;
  std::string fileName_;
  Cell begin_;
  Cell end_;
  std::vector< std::vector<Cell> > cellTab_;

public:
  World(); // standard constructor
  ~World();
  World(std::string mapName); // construcotr that reads read info in a map file

  Cell getBegin();
  Cell getEnd();
  Cell getCell(int i, int j);
  void updatePhero(double loss);
};

#endif
