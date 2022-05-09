#ifndef ALGORITMO
#define ALGORITMO
#include "Solution.h"

class Maxdiversity;

class Algoritmo {
public:
  virtual Solution solve(Maxdiversity max, int m) = 0;
};

#endif