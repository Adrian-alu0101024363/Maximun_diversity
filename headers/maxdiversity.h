#ifndef MAXDIVERSITY
#define MAXDIVERSITY

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
 public:
  Maxdiversity(string file);
  ~Maxdiversity(){}
  void read(string file);
  vector<double> values(string line);
  void print();
};



#endif