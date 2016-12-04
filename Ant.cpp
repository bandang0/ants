#include "Ant.h"

using namespace std;

// Standard constructor
Ant::Ant() : number_(1), curPath_(Path()), curCell_(Cell()),
nextCell_(Cell()) {}
