#ifndef ALGORITMO
#define ALGORITMO
#include "Solution.h"
#include <chrono>

class Maxdiversity;

class Algoritmo {
public:
  virtual Solution solve(Maxdiversity max, int m, int rlc) = 0;
};

#endif