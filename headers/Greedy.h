#ifndef GREEDY
#define GREEDY
#include "Algoritmo.h"
#include "maxdiversity.h"

class Greedy : public Algoritmo {
  public:
  Solution solve(Maxdiversity max, int m, int rlc);
  Solution solvewith(Solution parcial, Maxdiversity max, int m);
};
#endif