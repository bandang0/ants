#include "ants/Ant.h"
#include "ants/World.h"
#include "ants/global.h"


using namespace std;

int main(){

  string filename; //name of the file (existent or not to read the map)
  welcome();
  filename = chooseFile();

  cout << "Building world from " << filename <<"\n";
  World world(filename);
  cout << "Done\n";

  if (!world.isCorrect()){
    sorry();
    if (askExit() == 1){return 1;}
  }

  cout << "\tStarting calculations...\n";
  while(!world.hasInARow(10)){

    Ant ant(world, 3);
    while(!ant.isAtEnd(world)){
      ant.move(world);
      world.windBlow();
    }
    world.addPath(ant);
  }

  cout << "\tDone calculations.\n";

  cout << "\tHere are the results: \n";

  world.printPaths(10);

  cout <<"Exiting\n";
  return 0;
}
