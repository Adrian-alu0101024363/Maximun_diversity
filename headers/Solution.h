#ifndef SOLUTION
#define SOLUTION
#include <vector>
#include <cmath>
#include <iostream>

using std::vector, std::cout, std::endl;

class Solution {
  private:
  vector<vector<double>> points_;
  public:
  Solution(){}
  Solution(vector<vector<double>> points) {points_ = points;}
  vector<double> centroid(int k);
  vector<vector<double>>& getElements() {return points_;}
  void add(vector<double> element) {points_.push_back(element);}
  vector<double> getFarElement(vector<double> sc, int k);
  void print();
};

#endif