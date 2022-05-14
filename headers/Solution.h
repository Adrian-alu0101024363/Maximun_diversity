#ifndef SOLUTION
#define SOLUTION
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using std::vector, std::cout, std::endl;

class Solution {
  private:
  vector<vector<double>> points_;
  int k_;
  double timeCost;
  public:
  Solution(){}
  Solution(vector<vector<double>> points, int k) {points_ = points; k_ = k;}
  vector<double> centroid();
  vector<vector<double>>& getElements() {return points_;}
  vector<vector<double>> getElementsCopy() {return points_;}
  void add(vector<double> element) {points_.push_back(element);}
  vector<double> getFarElementRemoving(vector<double> sc);
  vector<double> getFarElement(vector<double> sc);
  void setK(int k) {k_ = k;}
  vector<double> at(int index) {return points_[index];}
  void print();
  double distanceTotal();
  double getTimeCost() {return timeCost;}
  void setTimeCost(double time) {timeCost = time;}
  double distancia(vector<double> d1, vector<double> d2);
  void erase(int index) {points_.erase(points_.begin()+index);}
  void remove(vector<double> element);
  void insert(vector<double> element, int i) {points_.insert(points_.begin()+i, element);}
};

#endif