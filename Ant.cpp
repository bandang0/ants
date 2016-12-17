#include "Ant.h"

using namespace std;

// Standard constructor
Ant::Ant() : number_(1), curPath_(Path()), curCell_(Cell()),
nextCell_(Cell()) {}
Ant::~Ant() {}

//complete constructor
Ant::Ant(int num, Cell firstCell)
{
  number_ = num;
  curCell_ = firstCell;
  nextCell_ = firstCell;
  curPath_ = Path(firstCell);

  cout << "New Ant: number " << number_ << " at (" << curCell_.getX()
        << "," << curCell_.getY() << ") with empty path." << endl;

}


void Ant::evolve() //go to next cell and update path etc.
{
  curCell_ = nextCell_;
  nextCell_ = curCell_;
  curPath_.add(curCell_);
}

void Ant::chooseNext(World world) //choose next cell
//according to pheromone content
{
  vector<Cell> possibleCells; //contains all goable cells
  for (int k = -1; k != 2; k++)
  {
    for (int l = -1; l != 2; l++ )
    {
      if (l != k && world.getCell(k,l).getGo() == 0)
      {
        possibleCells.push_back(world.getCell(k,l));
      }
    }
  }

  //choose a random index in possibleCells and assign next cell to the one you
  // get.

  int rd = rand();
  rd  = rd % possibleCells.size();
  nextCell_ = possibleCells[rd];
}

void Ant::deposit(double depot)
{
  curCell_.addPhero(depot);
}
