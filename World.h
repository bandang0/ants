#ifndef DEF_WORLD
#define DEF_WORLD


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Ant.h"

class Ant;

class World
{
  int _sizeX;
  int _sizeY;
  std::vector<int> _phero;
  std::vector<int> _isnp;
  int _startX;
  int _startY;
  int _endX;
  int _endY;
  int _loss; //loss by wind blow

public:
  //destructor, constructor
  ~World();//destructor
  World(int sizeX, int sizeY, int isnp[], int startX,
        int startY, int endX, int endY, int loss);//constructor
                                                  //with complete info
  World(std::string mapName) ; //constructor that reads read info in a map file

  //print, equals
  void print(); //print pheromone state
  void print(Ant & ); //print ants on grid

  //getset
  int getSizeX();
  int getSizeY();
  int getPhero(int);
  int getIsnp(int);
  int getStartX();
  int getStartY();
  int getEndX();
  int getEndY();
  void setPhero(int, int);

  //methods
  int getPos(int, int);
  void windBlow();
};

#endif
