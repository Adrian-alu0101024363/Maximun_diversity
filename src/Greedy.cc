#include "../headers/Greedy.h"

/**
 * @brief solve the max problem using a greedy approach
 * 
 * @param max the problem
 * @param m the max size of solution
 * @param rlc the elements to get as farest (not used)
 * @return Solution 
 */
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

/**
 * @brief from the given parcial solution until reaching m using greedy approach
 * generate a solution
 * @param parcial a parcial solution
 * @param max the problem
 * @param m the max size of solution
 * @return Solution 
 */
Solution Greedy::solvewith(Solution parcial, Maxdiversity max, int m) {
  Solution initial(max.getPointsCopy(), max.getDimension());
  Solution finalSolution;
  for (int i = 0; i < parcial.size(); i++) {
    initial.remove(parcial.at(i));
  }
  finalSolution.setK(max.getDimension());
  auto sc = parcial.centroid();
  int i = parcial.size(); 
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