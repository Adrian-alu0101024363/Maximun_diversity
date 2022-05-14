#include "Algoritmo.h"
#include "maxdiversity.h"
#include <random>

class Grasp : public Algoritmo {
  public:
  Solution solve(Maxdiversity max, int m, int rlc);
  //vector<double> getFarElement(){}
  Solution localSearch(Maxdiversity max, Solution origin);
  Solution ConstructGrasp(Maxdiversity max, int m, int rlc);
};