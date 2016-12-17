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

  // try cells declaration
  Cell Here;
  Cell There(2,3,1, 0.0);
  cout << "1." << endl;

  //try ant declaration
  Ant Z(1, Here);
  Ant Azteca(2, There);
  cout << "2." << endl;

  //try path declaration
  Path Path1;
  Path Path2(There);
  cout << "3." << endl;

  Path1.print();
  Path2.print();
  cout << "4." << endl;

  Path2.add(There);

  Here.print();
  There.print();

  cout << "5." << endl;
  Path1.print();
  Path2.print();
  return 0;
}
