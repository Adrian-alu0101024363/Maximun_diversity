#include "../headers/Branch.h"

/*Solution Branch::solve(Maxdiversity max, int m, int rlc) {
  auto originalElements = max.getPointsCopy();
  original = max;
  Solution s(originalElements,max.getDimension());
  dataO = s;
  vector<Solution> actives;
  Greedy* greedy = new Greedy();
  Solution lowerSol = greedy->solve(max,m,rlc);
  Solution best = lowerSol;
  tree = new BABTree(s);
  solutionSize = m;
  branchOut(tree->getOrigin());
  return best;
}*/

/**
 * @brief solve the max problem using branch and bound
 * 
 * @param max the problem
 * @param m the max size of solution
 * @param rlc the elements to get as farest
 * @return Solution 
 */
Solution Branch::solve(Maxdiversity max, int m, int rlc) {
  auto originalElements = max.getPointsCopy();
  Solution s(originalElements,max.getDimension());
  vector<Solution> actives;
  Greedy* greedy = new Greedy();
  Solution lowerSol = greedy->solve(max,m,rlc);
  auto lower = lowerSol.distanceTotal();
  for (int i = 0; i < originalElements.size(); i++) {
    Solution aux;
    aux.add(originalElements[i]);
    auto item = s.getFarElement(originalElements[i]);
    aux.set(1);
    aux.add(item);
    actives.push_back(aux);
  }
  Solution sol = lowerSol;
  int i = 0;
  /**
  for (int j = 0; j < actives.size(); j++) {
    vector<Solution> sols = getValidactives(actives[j],max,lower,m);
    cout << "Sols size " << sols.size() << endl;
    for (int i = 0; i < sols.size(); i++) sols[i].print();
  }**/

  while (actives.size() > 0 && i < actives.size()) {
    auto far = actives[i].getFarElement(actives[i].at(i));
    auto distance = actives[i].distancia(actives[i].at(i), far);
    auto upper = distance * (m - actives[i].size());
    //auto greedy = new Greedy();
    //auto upper = greedy->solvewith(actives[i],max,m).distanceTotal();
    if (getValidactives(actives[i],max,lower,m).size() <= 0) {
      lower = upper;
      actives.erase(actives.begin()+i);
      //cout << "lower is: " << lower << endl;
      sol = actives[i];
    } else {
      if (upper < lower) {
        //cout << "erase";
        actives.erase(actives.begin()+i);
        i--;
      } else {
        vector<Solution> sons = getValidactives(actives[i], max, lower, m);
        for (int j = 0; j < sons.size(); j++) {
          actives.push_back(sons[j]);
        }
      }
    }
    i++;
  }
  return sol;
}

/**
 * @brief get a vector of solutions that expand the given
 * 
 * @param element the solution which will expand
 * @param max the problem
 * @param lower the lower bound
 * @param m the size of solution
 * @return vector<Solution> the new actives solutions
 */
vector<Solution> Branch::getValidactives(Solution element, Maxdiversity max, double lower, int m) {
  auto originalElements = max.getPointsCopy();
  vector<Solution> actives;
  auto elements = element.getElementsCopy();
  Solution s(originalElements,max.getDimension());
  for (int j = 0; j < originalElements.size(); j++) {
    if (std::find(elements.begin(), elements.end(), originalElements[j]) != elements.end()) {
      //std::cout << "Element found";
    } else {
      Solution aux = element;
      aux.add(originalElements[j]);
      //auto greedy = new Greedy();
      //auto upper = greedy->solvewith(aux,max,m).distanceTotal();
      auto far = aux.getFarElement(aux.at(aux.size()-1));
      auto distance = aux.distancia(aux.at(aux.size()-1), far);
      auto upper = distance * (m - aux.size());
      //cout << "lower es: " << lower << "upper es: " << upper << endl;
      if (upper > lower) {
        aux.add(originalElements[j]);
        actives.push_back(aux);
      }
    }
  }
  return actives;
}

/*
void Branch::branchOut(BABNode* set) {
  if (set->getSet().size() != solutionSize) {
    set->generateSons(original);
    //exploreDepthFirst(set);
  } else {
    if (bestFound.distanceTotal() < set->getSet().distanceTotal()) {
      bestFound = set->getSet();
    }
  }
}
bool Branch::worthy(BABNode* node) {
  if (std::find(alreadyExpanded.begin(), alreadyExpanded.end(), node) != alreadyExpanded.end()) {
    return false;
  }
  int adding = -1;
  for (int i = 0; i < node->getSet().size();i++) {
    auto n = node->getSet().getElementsCopy();
    auto fn = node->getFather()->getSet().getElementsCopy();
    if ((std::find(n.begin(), n.end(), node->getSet().at(i)) != n.end())
    && !(std::find(fn.begin(), fn.end(), node->getSet().at(i)) != fn.end())) {
      adding = i;
      break;
    }
  }
  for (int i = 0; i < node->getFather()->getSet().size();i++) {
    auto n = node->getSet().getElementsCopy();
    if (!(std::find(n.begin(), n.end(), node->getSet().at(i)) != n.end())) {
      if (dataO.minDistance(node->getSet().at(i)) > dataO.maxDistance(node->getSet().at(adding))) {
        return false;
      }
    }
  }
  return (node->getSet().upperBound(solutionSize, original) >= bestFound.distanceTotal() - 0.08 * bestFound.distanceTotal());
}

void Branch::exploreDepthFirst(BABNode* currentNode) {
  for (BABNode* son : currentNode->getLinks()) {
    if (worthy(son)) {
      alreadyExpanded.push_back(*son);
      branchOut(son);
    } else {
      alreadyExpanded.push_back(*son);
    }
  }
}
*/