#include "Ant.h"

using namespace std;

// Standard constructor
Ant::~Ant() {
  cout << "Destroyed ant\n";
}

Ant::Ant(int x, int y) : _x(x), _y(y), _pathLength(1) {
  _pathX.push_back(x);
  _pathY.push_back(y);
  cout << "Constucted ant at ("<<x<<","<<y<<")\n";
}

void Ant::print() {
  cout << "Ant is at ("<<_x<<","<<_y<<"). It's current path has length "<<
  _pathLength  << " and is : \n";

  for (int i = 0; i< _pathLength; i++) {
    cout <<"\t(" << _pathX[i]<<","<<_pathY[i]<<")\n";
  }
}

void Ant::move() {

}
