#include "Algoritmo.h"
#include "maxdiversity.h"

class Grasp : public Algoritmo {
  public:
  Solution solve(Maxdiversity max, int m);
  //vector<double> getFarElement(){}
  Solution localSearch(Maxdiversity max, Solution origin);
  Solution ConstructGrasp(Maxdiversity max, int m);
};