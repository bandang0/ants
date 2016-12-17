#include "Cell.h"

using namespace std;

// standard constructor
Cell::Cell() : x_(1), y_(1), go_(0), phero_(0.0) {

  cout << "New Cell at (1,1) with 0 phero content (goable)." << endl;
}

Cell::~Cell() {}
//complete constructor
Cell::Cell(int x, int y, int go = 0, double phero = 0.0)
{
  x_ = x;
  y_ = y;
  go_ = go;
  phero_ = phero;

  if (go_ == 1)
  {
  cout << "New Cell at (" << x_ << "," << y_ << ") with " << phero_
        << " phero content (not goable)." << endl;
  }
  else
  {
    cout << "New Cell at (" << x_ << "," << y_ << ") with " << phero_
          << " phero content (goable)." << endl;
  }
}

void Cell::print(){

  if (go_ == 1)
  {
  cout << "Cell at (" << x_ << "," << y_ << ") with " << phero_
        << " phero content (goable)." << endl;
  }
  else
  {
    cout << "Cell at (" << x_ << "," << y_ << ") with " << phero_
          << " phero content (not goable)." << endl;
  }
}

int Cell::getX()
{
  return x_;
}

int Cell::getY()
{
  return y_;
}

int Cell::getGo()
{
  return go_;
}

double Cell::getPhero()
{
  return phero_;
}

void Cell::addPhero(double morePhero)
{
  phero_ = phero_ + morePhero;
}

void Cell::subPhero(double minusPhero)
{
  phero_ = phero_ - minusPhero;
  if (phero_ <= 0.0)
  {
    phero_=0.0;
  }
}
