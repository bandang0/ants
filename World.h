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
  std::vector<double> _phero;//phero content of cells
  std::vector<int> _isnp;//list of obstacles
  int _startX;
  int _startY;
  int _endX;
  int _endY;
  double _rho; //when wind blows, pheromone is multiplied by (1 - _rho)
  std::vector<std::vector<int>> _listPathX;//list of paths, x coord
  std::vector<std::vector<int>> _listPathY;//list of paths, y coord

public:
  //destructor, constructor
  ~World();//destructor
  World(int sizeX, int sizeY, int isnp[], int startX,
        int startY, int endX, int endY, double rho);//constructor
                                                  //with complete info
  World(std::string mapName) ; //constructor that reads read info in a map file

  //print, equals
  void print() const; //print pheromone state
  void print(Ant & ) const; //print ants on grid
  void printPaths() const;
  void printPaths(int) const;
  //getset
  int getSizeX() const;
  int getSizeY() const;
  double getPhero(int) const;
  int getIsnp(int) const;
  int getStartX() const;
  int getStartY() const;
  int getEndX() const;
  int getEndY() const;
  void setPhero(int, double);

  //methods
  int getPos(int, int) const;//get  position in [0, sx*sy-1] with x,y coords
  void windBlow();//uniformly lose pheromone
  bool isCorrect() const;//verify that calculations and solutions are possible
  void addPath(Ant &);
  bool hasInARow(int) const;

};

#endif
