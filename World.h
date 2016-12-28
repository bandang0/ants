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
  std::vector<int> _phero;//phero content of cells
  std::vector<int> _isnp;//list of obstacles
  int _startX;
  int _startY;
  int _endX;
  int _endY;
  int _loss; //loss by wind blow
  std::vector<std::vector<int>> _listPathX;//list of paths, x coord
  std::vector<std::vector<int>> _listPathY;//list of paths, y coord

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
  void printPaths();
  void printPaths(int);
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
  int getPos(int, int);//get linear position in [0, sx*sy-1] with x,y coords
  void windBlow();//uniformely lose pheromone
  bool isCorrect();//verify that calculations and solutions are possible
  void addPath(Ant &);
  void sorry();
  bool hasInARow(int);

};

#endif
