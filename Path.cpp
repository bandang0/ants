#include "Path.h"

using namespace std;

// standard constructor
Path::Path() : length_(0) {}

//constructor by first cell
Path::Path(Cell firstCell) : length_(1) {
  vector<Cell> list_(1, firstCell);
}

Path::~Path() {}

void Path::print() {
  cout << "Path with length " << length_ <<":" << endl;
  
  for (int i=0; i < length_; i = i+1 ){
    cout << "  Cell " << i << " : " << "(" << list_[i].getX() << ","
    << list_[i].getY()<<")" << endl;
  }
}

void Path::add(Cell newCell)
{
  list_.push_back(newCell);
  length_ = length_ + 1;
}
