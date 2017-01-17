#include "Ant.h"

using namespace std;

//destructor
Ant::~Ant() {
  cout << "Destroyed ant\n";
}

Ant::Ant(int x, int y, double depot) : _x(x), _y(y), _pathLength(1),
                                    _depot(depot) {
  _pathX.push_back(x);//initialize path at start cell
  _pathY.push_back(y);
  cout << "Constucted ant at ("<<x<<","<<y<<") with depot " << _depot << "\n";
}

Ant::Ant(World & world , double depot) ://constructor at world start position
  _pathLength(1),
  _depot(depot) {
    _x = world.getStartX();
    _y = world.getStartY();
    _pathX.push_back(_x);//initialize path at start cell
    _pathY.push_back(_y);
    cout << "Constucted ant at ("<<_x<<","<<_y<<") with depot "
          << _depot << "\n";

  }


void Ant::print() const {
  cout << "Ant is at ("<<_x<<","<<_y<<"). It's current path has length "<<
  _pathLength  << " and is : \n\t";

  for (int i = 0; i< _pathLength; i++) {//list cells in path
    cout <<"(" << _pathX[i]<<","<<_pathY[i]<<") ";
  }
  cout <<"\n";
}

int Ant::getX() const {return _x;}
int Ant::getY() const {return _y;}
vector<int> Ant::getPathX() const {return _pathX;}
vector<int> Ant::getPathY() const {return _pathY;}

int Ant::chooseLab (World & world) const {

  //we will choose a random label from 0 to 7 which label the sourounding
  //cells
  int lab;
  int rd;
  double sum = 0.0;
  double xrd;
  vector<int> pos = { world.getPos(_x,_y-1), //vector of positions
                      world.getPos(_x-1, _y-1), //of sourrounding cells
                      world.getPos(_x-1, _y),
                      world.getPos(_x-1, _y+1),
                      world.getPos(_x, _y+1),
                      world.getPos(_x+1, _y+1),
                      world.getPos(_x+1, _y),
                      world.getPos(_x+1, _y-1)};

  vector<double> accPhero = {0.0};


  for (int m = 0; m<= 7; m++){
    double toAdd = (1.0 - (double) world.getIsnp(pos[m])) *
              world.getPhero(pos[m]);
    sum = sum + toAdd;
    accPhero.push_back(accPhero[m] + toAdd);
  }

  if (sum == 0.0){return rand() % 7;} //if thereis no phero around

  rd = rand() % 32000;
  xrd = ((double) rd) / 32000.0; //random number in [0, 1[

  if ( accPhero[0] <= xrd && xrd < accPhero[1]/sum ){
    lab = 0;
  }
  else if (accPhero[1]/sum <= xrd && xrd < accPhero[2]/sum){
    lab = 1;
  }
  else if (accPhero[2]/sum <= xrd && xrd < accPhero[3]/sum){
    lab = 2;
  }
  else if (accPhero[3]/sum <= xrd && xrd < accPhero[4]/sum){
    lab = 3;
  }
  else if (accPhero[4]/sum <= xrd && xrd < accPhero[5]/sum){
    lab = 4;
  }
  else if (accPhero[5]/sum <= xrd && xrd < accPhero[6]/sum){
    lab = 5;
  }
  else if (accPhero[6]/sum <= xrd && xrd < accPhero[7]/sum){
    lab = 6;
  }
  else if (accPhero[7]/sum <= xrd && xrd < accPhero[8]/sum){
    lab = 7;
  }

  return lab;
}


void Ant::move(World & world) {

  int pos; //next position
  int newX, newY; //next position in x, y coords



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

  pos = world.getPos(newX, newY);

  //deposit phero at next cell
  world.setPhero(pos, world.getPhero(pos) + _depot);
  // go to next cell
  _x = newX;
  _y = newY;

  //update path and length
  _pathX.push_back(newX);
  _pathY.push_back(newY);
  _pathLength = _pathLength + 1;
}


bool Ant::isAtEnd(World & world) const {
  return (_x == world.getEndX() && _y == world.getEndY());
}
