#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Ant.h"
#include "World.h"

using namespace std;

int main(){
  int acc = 30;
  int stop = 1;
  int isnp[25] = {  1, 1, 1, 1, 1,
                    1, 0, 0, 0, 1,
                    1, 0, 0, 0, 1,
                    1, 0, 0, 0, 1,
                    1, 1, 1, 1, 1};

  World world(5, 5, isnp, 2, 2, 4, 4, 0);

  if (!world.isCorrect()){
     world.sorry();
     return 1;
   }

   cout << "Starting calculations.\n";

   while(!world.hasInARow(10)){
     cout << "New ant\n";
     Ant ant(world, 0);

     while(!ant.isAtEnd(world)){
       ant.move(world);
       world.windBlow();
       world.print();
    }
    ant.print();
    world.print();
    world.addPath(ant);
    stop = stop +1;
   }

  cout << "Done calculations.\n";

  cout << "Here are the results: \n";

  world.printPaths(3);

  cout <<"Exiting\n";
  return 0;

}
