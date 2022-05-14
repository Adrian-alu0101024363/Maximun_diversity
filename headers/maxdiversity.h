#ifndef MAXDIVERSITY
#define MAXDIVERSITY
#include "Algoritmo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::vector, std::string, std::ifstream, std::stringstream;
using std::cout, std::endl, std::istringstream;

class Maxdiversity {
 private:
  vector<vector<double>> points_;
  int numberElements_;
  int dimension_;
  Algoritmo* method_;
 public:
  Maxdiversity(string file, Algoritmo* method);
  ~Maxdiversity(){}
  void read(string file);
  vector<double> values(string line);
  void print();
  vector<vector<double>> getPointsCopy() {return points_;}
  int getDimension() {return dimension_;}
  int getSize() {return numberElements_;}
  Solution solve(Maxdiversity max, int m, int rlc){return method_->solve(*this, m, rlc);}
};



#endif