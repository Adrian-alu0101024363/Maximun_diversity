#include "../headers/Greedy.h"

Solution Greedy::solve(Maxdiversity max, int m, int rlc) {
  Solution initial(max.getPointsCopy(), max.getDimension());
  Solution finalSolution;
  finalSolution.setK(max.getDimension());
  auto sc = initial.centroid();
  int i = 0; 
  auto t_start = std::chrono::high_resolution_clock::now();
  while (i < m) {
    auto se = initial.getFarElementRemoving(sc);
    finalSolution.add(se);
    sc = finalSolution.centroid();
    i++;
  }
  auto t_end = std::chrono::high_resolution_clock::now();
  auto timeCost = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  finalSolution.setTimeCost(timeCost);
  return finalSolution;
}