#ifndef DEF_PATH
#define DEF_PATH

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Cell.h"

class Path
{
  int length_;
  std::vector<Cell> list_;

public:
  Path(); //standard constructor
  Path(Cell firstCell); //constructor by firstCell
  ~Path();

  void print();
  void add(Cell newCell);
};

#endif
