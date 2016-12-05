#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "Path.h"
#include "Ant.h"
#include "World.h"

using namespace std;

int main()
{

  Cell Here, There(2,3,1, 0.0);
  Ant Z(1, Here);
  Ant Azteca(2, There);
  


  return 0;
}
