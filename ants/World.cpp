#include "ants/World.h"

using namespace std;

World::~World () {
  cout << "Destroyed world\n";
}

World::World(int sizeX, int sizeY, int isnp[], int startX,
  int startY,  int endX, int endY, double rho) { //complete constructor

    _sizeX = sizeX;
    _sizeY = sizeY;
    for (int i = 0; i < sizeX*sizeY; i++) {
        _phero.push_back(1.0); //initialize pheromone at 1.0
        _isnp.push_back(isnp[i]);//copy isnp in the class member
    }
    _startX = startX;
    _startY = startY;
    _endX = endX;
    _endY = endY;
    _rho  = rho;
    _listPathX = { };
    _listPathY = { };

    cout << "Constructed world with size (" << sizeX << "," << sizeY << ") "
          << "and rho coefficient " << _rho << "\n";
}


World::World(string mapName)//constructor with file
{




  _listPathX = {};
  _listPathY = {};
}

void World::print() const {

  cout << "Current pheromone state : \n";//print grid of pheromone content
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

void World::print(Ant & ant) const {//print ant on grid
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

void World::printPaths() const {
  cout  << "World currently has " << _listPathX.size()
        << " paths stored. They are : \n";

  for (int m = 0; m < _listPathX.size(); m++){
    cout << "\t" << m+1 << ": ";
    for (int n = 0; n < _listPathX[m].size(); n++){
      cout << "(" << _listPathX[m][n] << "," << _listPathY[m][n] << ") ";
    }
    cout << "\n";
  }
}

void World::printPaths(int p) const {

  int min = p;
  int listNum = _listPathX.size();
  if (_listPathX.size() < p ){min = _listPathX.size();}

  cout  << "The world's last " << p << " non-empty stored paths are : \n";

  for (int m = min; m >= 1; m--){
    cout << "\t" << m << ": ";
    for (int n = 0; n < _listPathX[listNum-m].size(); n++){
      cout << "(" << _listPathX[listNum - m][n] << ","
           << _listPathY[listNum -m ][n] << ") ";
    }
    cout << "\n";
  }

}

int World::getSizeX() const {return _sizeX;}
int World::getSizeY() const {return _sizeY;}
double World::getPhero(int pos) const {return _phero[pos];}
int World::getIsnp(int pos) const {return _isnp[pos];}
int World::getStartX() const {return _startX;}
int World::getStartY() const {return _startY;}
int World::getEndX() const {return _endX;}
int World::getEndY() const {return _endY;}

void World::setPhero(int pos, double phero){
  _phero[pos] = phero;
}

int World::getPos(int x, int y) const {
  //this function gives the position between 0 and sx*sy-1 of an element
  // which has position (x,y) with 1<=x,y<=sx in the grid

  return _sizeX*(y-1) + (x-1);

}

void World::windBlow() {
  for (int j = 0; j < _sizeX*_sizeY; j++){
    _phero[j] = (1 - _rho) * _phero[j];
  }
}

bool World::isCorrect() const {

  //1. the start and end cells are not walls
  if (_isnp[getPos(_startX,_startY)] == 1 || _isnp[getPos(_endX,_endY)] == 1){
    return false;
  }

  //2. the start and end cells are not the same
  if(_startX == _endX && _startY == _endY){
    return false;
  }

  //3. the whole world is enclosed in a wall
  int prod = 1; //this is the product of all _isnp around the wall
                //it stays equal to 1 iff a wall encloses the world

  for (int l = 1; l <= _sizeX ; l++){
    prod = prod*_isnp[getPos(l,1)];
    prod = prod*_isnp[getPos(l,_sizeY)];
  }

  for (int l= 2; l<=_sizeY -1 ; l++){
    prod = prod*_isnp[getPos(1,l)];
    prod = prod*_isnp[getPos(_sizeX,l)];
  }


  if (prod == 0){return false;}
  //4. the start and end cells are connected
  /* To be implemented */

  return true;

}


void World::addPath(Ant & ant) {
  _listPathX.push_back(ant.getPathX());
  _listPathY.push_back(ant.getPathY());

}


bool World::hasInARow(int n) const {

  bool rtn = true;

  if ( _listPathX.size() < n ){ return false;}//if there aren't enough paths

  for (int k = 1; k <= n ; k++ ){ //test if all last n paths have same length
    rtn = rtn && (_listPathX[_listPathX.size()-1].size()
                  == _listPathX[_listPathX.size()-1 -k ].size() );
  }

  return rtn;
}
