#include <iostream>
#include <string>
#include <vector>
#include "Ant.h"
#include "World.h"

using namespace std;

int main()
{

  Ant ant1(0,0);
  Ant ant2(2,5);

  ant1.print();
  ant2.print();

  bool isnp[3][4] = { {false, false, false, false},
                      {false, true, true, false},
                      {false, true, true, false}};

  World garden(3, 4, isnp, 2, 1,  2, 2);

  garden.print();
}
