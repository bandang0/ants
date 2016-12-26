#include "World.h"

using namespace std;

World::~World () {
  cout << "Destroyed world";
}

World::World(int sizeX, int sizeY, bool *isnp, int startX,
  int startY,  int endX, int endY) { //complete constructor

    _sizeX = sizeX;
    _sizeY = sizeY;
    for (int i = 0, i< sizeX, i++) {
      for (int j = 0,  i<sizeY, j++){
        _phero[i][j] = 0;
        _isnp[i][j] = *isnp[i][j];
      }
    }
    _startX = startX;
    _startY = startY;
    _endX = endX;
    _endY = endY;

    cout << "Constructed world with size" << sizeX << "," << sizeY << ")\n";
}


World::World(string mapName)//constructor with file
{

}

void World::print() {

  cout << "Walls : \n"
  for (int i=0; i <_sizeX; i++){
    for (int j=0; i <_sizeY; j++){
      cout << _isnp[i][j] ;
    }

    cout <<"\n";
  }

  cout << "Pheromones : \n";

  for (int i=0; i <_sizeX; i++){
    for (int j=0;  i <_sizeY; j++){
      cout << _phero[i][j] ;
    }

    cout <<"\n";
  }


}
