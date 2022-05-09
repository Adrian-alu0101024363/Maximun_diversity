#include "../headers/Solution.h"

vector<double> Solution::centroid() {
  vector<double> sol(k_);
  for (int i = 0; i < points_.size(); i++) {
    for (int j = 0; j < points_[i].size(); j++) {
      sol[j] += points_[i][j];
    }
  }
  for (int l = 0; l < sol.size(); l++) {
    sol[l] = sol[l] / points_.size();
    sol[l] = ceil(sol[l] * 100) / 100.0;
  }
  return sol;
}

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

void Solution::print() {
    for (int i = 0; i < points_.size(); i++) {
    for (int j = 0; j < points_[i].size(); j++) {
      cout << points_[i][j] << " , ";
    }
    cout << endl;
  }
}