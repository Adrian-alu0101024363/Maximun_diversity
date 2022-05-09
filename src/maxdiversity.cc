#include "../headers/maxdiversity.h"

Maxdiversity::Maxdiversity(string file) {
  read(file);
}

bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' ');}

void Maxdiversity::read(string file) {
  ifstream f;
  f.open(file);
  f >> numberElements_;
  f >> dimension_;
  string line = "";
  points_.resize(numberElements_);
  int i = 0;
  getline(f,line);
  while(getline(f, line)) {
    string str = line;
    cout << endl << line;
    std::replace(std::begin(str),std::end(str),'\t',' ');
    std::replace(std::begin(str),std::end(str),',','.');
    std::string::iterator new_end = std::unique(str.begin(), str.end(), BothAreSpaces);
    str.erase(new_end, str.end());
    vector<double> val = values(str);
    for (int j = 0; j < dimension_; j++) {
      points_[i].push_back(val[j]);
    }
    i++;
 }
}

/**
 * @brief from a line of text to a vector of double
 * used to store the distances to the nodes
 * @param line the line read from the file
 * @return std::vector<double> the distance values
 */
std::vector<double> Maxdiversity::values(std::string line) {
  char space_char = ' ';
  vector<double> val;
  istringstream iss(line);
  double value;
  while (iss >> value) {
    val.push_back(value);
  }
  return val;
}



void Maxdiversity::print() {
  cout << "Number of elements: " << numberElements_ << endl;
  cout << "Dimension of each: " << dimension_ << endl;

  for (int i = 0; i < points_.size(); i++) {
    for (int j = 0; j < points_[i].size(); j++) {
      cout << points_[i][j] << " , ";
    }
    cout << endl;
  }
}