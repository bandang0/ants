#include "Ant.h"

using namespace std;

//destructor
Ant::~Ant() {
  cout << "Destroyed ant\n";
}

Ant::Ant(int x, int y, int depot) : _x(x), _y(y), _pathLength(1),
                                    _depot(depot) {
  _pathX.push_back(x);//initialize path at start cell
  _pathY.push_back(y);
  cout << "Constucted ant at ("<<x<<","<<y<<") with depot " << _depot << "\n";
}

void Ant::print() {
  cout << "Ant is at ("<<_x<<","<<_y<<"). It's current path has length "<<
  _pathLength  << " and is : \n";

  for (int i = 0; i< _pathLength; i++) {//list cells in path
    cout <<"\t(" << _pathX[i]<<","<<_pathY[i]<<")\n";
  }
}

int Ant::getX() {return _x;}
int Ant::getY() {return _y;}

int Ant::chooseLab (World & world) {

  //we will choose a random label from 0 to 7 which label the sourounding
  //cells
  int rd;
  int lab;
  vector<int> possibleCells={}; //vector of labels of possible cells to go

  // fill in the vector with as many labels n as there are pheromones in cell
  // n around the current cell
  if (world.getIsnp(world.getPos(_x,_y-1)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x,_y-1)); k++){
      possibleCells.push_back(0);
    }
  }

  if (world.getIsnp(world.getPos(_x-1,_y-1)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x-1,_y-1)); k++){
      possibleCells.push_back(1);
    }
  }

  if (world.getIsnp(world.getPos(_x-1,_y)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x-1,_y)); k++){
      possibleCells.push_back(2);
    }
  }

  if (world.getIsnp(world.getPos(_x-1,_y+1)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x-1,_y+1)); k++){
      possibleCells.push_back(3);
    }
  }

  if (world.getIsnp(world.getPos(_x,_y+1)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x,_y+1)); k++){
      possibleCells.push_back(4);
    }
  }

  if (world.getIsnp(world.getPos(_x+1,_y+1)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x+1,_y+1)); k++){
      possibleCells.push_back(5);
    }
  }

  if (world.getIsnp(world.getPos(_x+1,_y)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x+1,_y+1)); k++){
      possibleCells.push_back(6);
    }
  }

  if (world.getIsnp(world.getPos(_x+1,_y-1)) == 0){
    for (int k = 0 ; k <= world.getPhero(world.getPos(_x+1,_y-1)); k++){
      possibleCells.push_back(7);
    }
  }

  rd = rand() % possibleCells.size();//random number
                                     //in [0, num of possible cells]

  lab = possibleCells[rd]; //random label, those most represented are more
                           //likely to be chosen

  return lab;

}


void Ant::move(World & world) {

  int pos = world.getPos(_x, _y); //current position
  int newX, newY; //next position

  //deposit phero
  world.setPhero(pos, world.getPhero(pos) + _depot);

  //choose label
  int lab = chooseLab(world);

  //choose cell
  switch (lab) {
    case 0 :
      newX = _x;
      newY = _y -1;
      break;

    case 1 :
      newX = _x - 1;
      newY = _y - 1;
      break;

    case 2 :
      newX = _x -1;
      newY = _y;
      break;

    case 3 :
      newX = _x -1;
      newY = _y +1;
      break;

    case 4 :
      newX = _x;
      newY = _y +1;
      break;

    case 5 :
      newX = _x +1;
      newY = _y +1;
      break;

    case 6 :
      newX = _x +1;
      newY = _y;
      break;

    case 7 :
      newX = _x +1;
      newY = _y -1;
      break;
  }

  // go to next cell
  _x = newX;
  _y = newY;

  //update path and length
  _pathX.push_back(newX);
  _pathY.push_back(newY);
  _pathLength = _pathLength + 1;
}
