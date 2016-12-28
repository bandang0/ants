#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Ant.h"
#include "World.h"

using namespace std;

int main()
{

  int isnp[100] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


  World world1(10, 10, isnp, 2, 2, 3, 4, 1);

  world1.print();

  Ant ant1(2,2, 4);
  Ant ant2(5,6, 4);


  for (int k = 0; k < 50; k++){

    ant1.move(world1);
    world1.windBlow();
    usleep(1000000);
    world1.print();
    world1.print(ant1);

  }


}
