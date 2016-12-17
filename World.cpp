#include "World.h"

using namespace std;

// Standard constructor
World::World() : sizeX_(1), sizeY_(1) {}
World::~World() {}

//constructor with file
World::World(string mapName)
{

}

Cell World::getBegin()
{
  return begin_;
}

Cell World::getEnd()
{
  return end_;
}

Cell World::getCell(int i, int j)
{
  return cellTab_[i][j];
}

void World::updatePhero(double loss)
{
  for (int i = 0; i < sizeX_; i++)
  {
    for (int j = 0; j < sizeY_; j++ )
    {
      cellTab_[i][j].subPhero(loss);
    }
  }
}
