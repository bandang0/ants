#ifndef DEF_CELL
#define DEF_CELL

#include <iostream>
#include <string>

class Cell
{
  int x_;
  int y_;
  int go_; // 1 for wall and 0 for empty
  int begin_; // 1 if it the begining of the path
  int end_; //1 if its the end of the path
  double phero_;  // pheromone content

public:
  Cell();
};

#endif
