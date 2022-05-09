#include "../headers/Grasp.h"

Solution Grasp::solve(Maxdiversity max, int m) {
  auto t_start = std::chrono::high_resolution_clock::now();
  Solution noLocal = ConstructGrasp(max, m);
  Solution sol = localSearch(max,noLocal);
  cout << "Sol local: " << sol.distanceTotal() << endl;
  auto t_end = std::chrono::high_resolution_clock::now();
  auto timeCost = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  noLocal.setTimeCost(timeCost);
  //sol.setTimeCost(timeCost);
  //return sol;
  return noLocal;
}

Solution Grasp::ConstructGrasp(Maxdiversity max, int m) {
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

Solution Grasp::localSearch(Maxdiversity max, Solution origin) {
  double originalDistance = origin.distanceTotal();
  auto elements = origin.getElements();
  auto elementsCopy = origin; 
  auto originalElements = max.getPointsCopy();
  double maxi(-std::numeric_limits<double>::infinity()); 
  vector<double> change, element;
  int removing = 0;
  for (int i = 0; i < elements.size(); i++) {
    element = elementsCopy.getElementsCopy()[i];
    elementsCopy.erase(i);
    auto tempCentroid = elementsCopy.centroid();
    for (int j = 0; j < originalElements.size(); j++) {
      if (std::find(elements.begin(), elements.end(), originalElements[j]) != elements.end()) {
        //std::cout << "Element found";
      } else {
        auto distance = origin.distancia(originalElements[j], tempCentroid);
        if (distance > maxi) {
          maxi = distance;
          change = originalElements[j];
          removing = i;
        }
      }
    }
    elementsCopy.insert(element, i);
  }
  elementsCopy.erase(removing);
  elementsCopy.insert(change, removing);
  if (elementsCopy.distanceTotal() > originalDistance) {
    return elementsCopy;
  } else {
    return origin;
  }
}