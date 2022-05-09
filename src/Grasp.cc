#include "../headers/Grasp.h"

Solution Grasp::solve(Maxdiversity max, int m) {
  Solution initial(max.getPointsCopy());
  Solution finalSolution;
  auto sc = initial.centroid(max.getDimension());
  int i = 0; 
  while (i <= m) {
    auto se = initial.getFarElement(sc, max.getDimension());
    finalSolution.add(se);
    sc = finalSolution.centroid(max.getDimension());
    i++;
  }
  return finalSolution;
}