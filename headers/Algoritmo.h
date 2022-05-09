#ifndef ALGORITMO
#define ALGORITMO
#include "Solution.h"
#include <chrono>

class Maxdiversity;

class Algoritmo {
public:
  virtual Solution solve(Maxdiversity max, int m) = 0;
};

#endif