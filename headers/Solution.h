#ifndef SOLUTION
#define SOLUTION
#include <vector>
#include <cmath>
#include <iostream>

using std::vector, std::cout, std::endl;

class Solution {
  private:
  vector<vector<double>> points_;
  int k_;
  public:
  Solution(){}
  Solution(vector<vector<double>> points, int k) {points_ = points; k_ = k;}
  vector<double> centroid();
  vector<vector<double>>& getElements() {return points_;}
  void add(vector<double> element) {points_.push_back(element);}
  vector<double> getFarElementRemoving(vector<double> sc);
  void setK(int k) {k_ = k;}
  void print();
};

#endif