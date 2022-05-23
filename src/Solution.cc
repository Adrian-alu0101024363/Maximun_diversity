#include "../headers/Solution.h"

/**
 * @brief calculate the centroid of the solution
 * 
 * @return vector<double> 
 */
vector<double> Solution::centroid() {
  vector<double> sol(k_);
  for (int i = 0; i < points_.size(); i++) {
    for (int j = 0; j < points_[i].size(); j++) {
      sol[j] += points_[i][j];
    }
  }
  for (int l = 0; l < sol.size(); l++) {
    sol[l] = sol[l] / points_.size();
    //sol[l] = ceil(sol[l] * 100) / 100.0;
  }
  return sol;
}

/**
 * @brief Get the farest vector and remove it from the solution
 * 
 * @param sc reference vector to get the farest
 * @return vector<double> 
 */
vector<double> Solution::getFarElementRemoving(vector<double> sc) {
  double max(-std::numeric_limits<double>::infinity());
  vector<double> sol(k_);
  vector<double> element;
  size_t pos;
  for (int i = 0; i < points_.size(); i++) {
    double sum = 0.0;
    for (int j = 0; j < points_[i].size(); j++) {
      sol[j] = pow(sc[j] - points_[i][j],2);
      sum += sol[j];
    }
    double root = sqrt(sum);
    if (root > max) {
      max = root;
      element = points_[i];
      pos = i;
    }
  }
  points_.erase(points_.begin()+pos);
  return element;
}

/**
 * @brief Get the farest vector(copy) from the solution
 * 
 * @param sc reference vector to get the farest
 * @return vector<double> 
 */
vector<double> Solution::getFarElement(vector<double> sc) {
  double max(-std::numeric_limits<double>::infinity());
  vector<double> sol(k_);
  vector<double> element;
  size_t pos;
  for (int i = 0; i < points_.size(); i++) {
    double sum = 0.0;
    for (int j = 0; j < points_[i].size(); j++) {
      sol[j] = pow(sc[j] - points_[i][j],2);
      sum += sol[j];
    }
    double root = sqrt(sum);
    if (root > max) {
      max = root;
      element = points_[i];
      pos = i;
    }
  }
  return element;
}

/**
 * @brief remove a given vector from the solution
 * 
 * @param element vector to be removed
 */
void Solution::remove(vector<double> element) {
  if (std::find(points_.begin(), points_.end(), element) != points_.end()) {
    auto pos = std::find(points_.begin(), points_.end(), element);
    points_.erase(pos);
  }
}

/**
 * @brief print the solution elements aka vectors to console
 * 
 */
void Solution::print() {
    for (int i = 0; i < points_.size(); i++) {
    for (int j = 0; j < points_[i].size(); j++) {
      cout << points_[i][j] << " , ";
    }
    cout << endl;
  }
}

/**
 * @brief return the distance between two vectors given
 * 
 * @param d1 vector to measure distance
 * @param d2 vector to measure distance
 * @return double 
 */
double Solution::distancia(vector<double> d1, vector<double> d2) {
  double sum = 0.0;
  for (int j = 0; j < d1.size(); j++) {
    sum += pow(d1[j] - d2[j],2);
  }
  double root = sqrt(sum);
  return root;
}

/*
double Solution::distanceTotal() {
  double sum = 0.0;
  for (int i = 0; i < points_.size() - 1; i++) {
    sum += distancia(points_[i], points_[i+1]);
  }
  return sum;
}*/

/**
 * @brief return the z value of this solution
 * 
 * @return double 
 */
double Solution::distanceTotal() {
  double sum = 0.0;
  for (int i = 0; i < points_.size() - 1; i++) {
    for(int j = i + 1; j < points_.size();j++) {
    sum += distancia(points_[i], points_[j]);
    }
  }
  return sum;
}

/**
 * @brief min distance to element given in solution
 * 
 * @param element vector to measure distance
 * @return double 
 */
double Solution::minDistance(vector<double> element) {
  if (size() == 0) {
    return INT32_MIN;
  }
  double distanceM = INT32_MAX;
  for (int i = 0; i < getElementsCopy().size(); i++) {
    if ((distancia(at(i), element)) < distanceM) {
      distanceM = distancia(at(i), element);
    }
  }
  return distanceM;
}

/**
 * @brief max distance to element given in solution
 * 
 * @param element vector to measure distance
 * @return double distance
 */
double Solution::maxDistance(vector<double> element) {
  if (size() == 0) {
    return INT32_MAX;
  }
  double distanceM = INT32_MIN;
  for (int i = 0; i < getElementsCopy().size(); i++) {
    if ((distancia(at(i), element)) > distanceM) {
      distanceM = distancia(at(i), element);
    }
  }
  return distanceM;
}

 /*
 double Solution::upperBound(int m, Maxdiversity all) {
   auto greedy = new Greedy();
   Solution s = greedy->solve(all,m,0);
   return s.distanceTotal();
 }
 */
