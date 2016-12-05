#include "Path.h"

using namespace std;

// standard constructor
Path::Path() : length_(0) {}
Path::~Path() {}


void Path::add(Cell newCell)
{
  list_.push_back(newCell);
  length_ = length_ + 1;
}
