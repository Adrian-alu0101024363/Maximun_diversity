#include "../headers/Grasp.h"

Solution Grasp::solve(Maxdiversity max, int m, int rlc) {
  auto t_start = std::chrono::high_resolution_clock::now();
  Solution finalSolution = ConstructGrasp(max, m, rlc);
  int i = 0;
  while (i < 20) {
    Solution noLocal = ConstructGrasp(max, m, rlc);
    Solution sol = localSearch(max,noLocal);
    //cout << "Sol no local: " << noLocal.distanceTotal() << endl;
    if (sol.distanceTotal() > finalSolution.distanceTotal()) {
      finalSolution = sol;
    }
    i++;
  }
  auto t_end = std::chrono::high_resolution_clock::now();
  auto timeCost = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  //noLocal.print();
  finalSolution.setTimeCost(timeCost);
  return finalSolution;
}

Solution Grasp::ConstructGrasp(Maxdiversity max, int m, int rlc) {
  Solution initial(max.getPointsCopy(), max.getDimension());
  Solution finalSolution;
  finalSolution.setK(max.getDimension());
  auto sc = initial.centroid();
  int i = 0; 
  while (i < m) {
    vector<vector<double>> elements;
    Solution temp = initial;
    for (int i = 0; i < rlc; i++) {
      elements.push_back(temp.getFarElementRemoving(sc));
    }
    int random = rand() % elements.size(); 
    auto se = elements[random];
    //cout << random << endl;
    initial.remove(se);
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
  //double maxi(-std::numeric_limits<double>::infinity());
  double maxi = 0.0;  
  vector<double> change, element;
  int removing = 0;
  bool flag = false;
  for (int i = 0; i < elements.size(); i++) {
    for (int j = 0; j < originalElements.size(); j++) {
      if (std::find(elements.begin(), elements.end(), originalElements[j]) != elements.end()) {
        //std::cout << "Element found";
      } else {
        double distance4 = 0.0;
        double distance2 = 0.0;
        double distance3 = 0.0;
        double distance1 = 0.0;
        if (i > 0) {
          distance2 = origin.distancia(elements[i-1], elements[i]);
          distance4 = origin.distancia(elements[i-1], originalElements[j]);
        }
        if (i < elements.size() - 1) {
          distance3 = origin.distancia(originalElements[j], elements[i+1]);
          distance1 = origin.distancia(elements[i], elements[i+1]);
        }
        double distance = distance3 + distance4 - distance1 - distance2;
        if (distance > maxi) {
          maxi = distance;
          change = originalElements[j];
          removing = i;
          flag = true;
        }
      }
    }
  }
  if (flag) {
    elementsCopy.erase(removing);
    elementsCopy.insert(change, removing);
    return elementsCopy;
  }
  return origin;
}