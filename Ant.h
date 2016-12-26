#ifndef DEF_ANT
#define DEF_ANT

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>


class Ant
{
  int _x;
  int _y;
  std::vector<int> _pathX;
  std::vector<int> _pathY;
  int _pathLength;

public:
  ~Ant();//destructor
  Ant(int x, int y);//complete constructor

  void print();//print info on ant
  void move();
};

#endif
