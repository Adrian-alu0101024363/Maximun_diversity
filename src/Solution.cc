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
    //sol[l] = ceil(sol[l] * 100) / 100.0;
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

void Solution::remove(vector<double> element) {
  if (std::find(points_.begin(), points_.end(), element) != points_.end()) {
    auto pos = std::find(points_.begin(), points_.end(), element);
    points_.erase(pos);
  }
}

void Solution::print() {
    for (int i = 0; i < points_.size(); i++) {
    for (int j = 0; j < points_[i].size(); j++) {
      cout << points_[i][j] << " , ";
    }
    cout << endl;
  }
}
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
double Solution::distanceTotal() {
  double sum = 0.0;
  for (int i = 0; i < points_.size() - 1; i++) {
    for(int j = i + 1; j < points_.size();j++) {
    sum += distancia(points_[i], points_[j]);
    }
  }
  return sum;
}
