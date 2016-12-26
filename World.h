#ifndef DEF_WORLD
#define DEF_WORLD


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

class World
{
  const int _sizeX;
  const int _sizeY;
  std::vector<std::vector<int>> _phero;
  std::vector<std::vector<bool>> _isnp;
  const int _startX;
  const int _startY;
  const int _endX;
  const int _endY;

public:
  ~World();//destructor
  World(int sizeX, int sizeY, bool *isnp, int startX, int startY,
    int endX, int endY);//constructor with complete info
  World(std::string mapName); // construcotr that reads read info in a map file
  void print();
};

#endif
