#include <iostream>
#include <string>
#include <vector>
#include "Ant.h"
#include "World.h"

using namespace std;

int main(){
  cout << "Welcome to the Ant Colony Algorithm pathfinder\n";
  cout << "Building world from file " << filename << "\n";

  World world(filename);
  cout << "Done\n";

  if (!world.isCorrect()){
    world.sorry();
    return 1;
  }

  cout << "Starting calculations.\n";
  while(!world.hasInARow(10)){

    Ant ant(world, 3);
    while(!ant.atEnd(world)){
      ant.move(world);
      world.windBlow();
    }
    world.addPath(ant);
  }

  cout << "Done calculations.\n";

  cout << "Here are the results: \n";

  world.printPaths(10);

  cout <<"Exiting\n";
  return 0;
}
