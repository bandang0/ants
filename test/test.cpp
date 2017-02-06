#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Ant.h"
#include "World.h"

using namespace std;

int main(){
  double r= 1.0e-2;
  double c = 1.0;
  int acc = 1;
  int stop = 1;
  int isnp[81] = {  1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 0, 0, 0, 0, 0, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1};
                    //1, 0, 0, 0, 0, 0, 0, 0, 1,

  World world(9, 9, isnp, 2, 2, 7, 7, r);

  if (!world.isCorrect()){
     world.sorry();
     return 1;
   }

   cout << "Starting calculations.\n";

   while(/*!world.hasInARow(10)*/ stop <= 100){
     cout << "New ant\n";
     Ant ant(world, c);

     while(!ant.isAtEnd(world) && acc < 300){
       ant.move(world);
       world.windBlow();
       //world.print();
       acc = acc +1;
    }
    acc=1;
    //ant.print();
    //world.print();
    world.addPath(ant);
    stop = stop +1;
   }

  cout << "Done calculations.\n";

  cout << "Here are the results: \n";

  world.printPaths(100);
  world.print();
  cout <<"Exiting\n";
  return 0;

}
