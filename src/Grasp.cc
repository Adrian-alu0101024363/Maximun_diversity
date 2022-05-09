#include "../headers/Grasp.h"

Solution Grasp::solve(Maxdiversity max, int m) {
  Solution initial(max.getPointsCopy(), max.getDimension());
  Solution finalSolution;
  finalSolution.setK(max.getDimension());
  auto sc = initial.centroid();
  int i = 0; 
  while (i <= m) {
    auto se = initial.getFarElementRemoving(sc);
    finalSolution.add(se);
    sc = finalSolution.centroid();
    i++;
  }
  return finalSolution;
}