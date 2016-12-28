#include "World.h"

using namespace std;

World::~World () {
  cout << "Destroyed world\n";
}

World::World(int sizeX, int sizeY, int isnp[], int startX,
  int startY,  int endX, int endY, int loss) { //complete constructor

    _sizeX = sizeX;
    _sizeY = sizeY;
    for (int i = 0; i < sizeX*sizeY; i++) {
        _phero.push_back(0); //initialize pheromone at 1
        _isnp.push_back(isnp[i]);//copy isnp in the class member
    }
    _startX = startX;
    _startY = startY;
    _endX = endX;
    _endY = endY;
    _loss  = loss;
    cout << "Constructed world with size (" << sizeX << "," << sizeY << ")\n";
}


World::World(string mapName)//constructor with file
{

}

void World::print() {

  cout << "Current pheromone state : \n";
  for (int i = 0; i < _sizeY; i++){
    for (int j = 0; j < _sizeX; j++){
      if (_isnp[_sizeX*i + j] == 1){
        cout << "x\t";
      }
      else{
        cout << _phero[_sizeX*i + j] << "\t";
      }
    }
    cout << "\n";
  }
}

void World::print(Ant & ant){
  int aX = ant.getX();
  int aY = ant.getY();

  cout << "Current ant position : \n";
  for (int i = 0; i < _sizeY; i++){
    for (int j = 0; j < _sizeX; j++){
      if (_isnp[_sizeX*i + j] == 1){
        cout << "x\t";
      }
      else{
        if ( aX == j+1 && aY == i+1 ){
          cout << "a\t";
        }
        else{
          cout << ".\t";
        }
      }
    }
    cout << "\n";
  }
}


int World::getSizeX() {return _sizeX;}
int World::getSizeY(){return _sizeY;}
int World::getPhero(int pos) {return _phero[pos];}
int World::getIsnp(int pos) {return _isnp[pos];}
int World::getStartX() {return _startX;}
int World::getStartY() {return _startY;}
int World::getEndX() {return _endX;}
int World::getEndY() {return _endY;}

void World::setPhero(int pos, int phero){
  _phero[pos] = phero;
}

int World::getPos(int x, int y) {
  //this function gives the position between 0 and sx*sy-1 of an element
  // which has position (x,y) with 1<=x,y<=sx in the grid

  return _sizeX*(y-1) + (x-1);

}
void World::windBlow() {
  for (int j = 0; j < _sizeX*_sizeY; j++){
    if (_phero[j] - _loss < 0) {
      _phero[j] = 0;
    }
    else{
    _phero[j] = _phero[j] - _loss;
    }
  }
}
