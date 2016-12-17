#ifndef DEF_CELL
#define DEF_CELL

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

class Cell
{
  int x_;
  int y_;
  int go_; // 1 for wall and 0 for empty
  double phero_;  // pheromone content

public:
  Cell(); //standard constructor
  ~Cell();
  Cell(int x, int y, int go, double phero); //complete constructor
  int getX();
  int getY();
  int getGo();
  double getPhero();
  void addPhero(double morePhero);
  void subPhero(double minusPhero);
  void print();
};

#endif
