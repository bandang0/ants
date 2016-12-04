#ifndef DEF_ANT
#define DEF_ANT

#include <iostream>
#include <string>
#include <vector>
#include "Path.h"
#include "Cell.h"


class Ant
{
  int number_;
  Path curPath_;
  Cell curCell_;
  Cell nextCell_;

public:
  Ant();
};

#endif
