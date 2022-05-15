#include "headers/maxdiversity.h"
#include "headers/Grasp.h"
#include "headers/Greedy.h"
#include <iomanip>
#include <time.h>
#include <filesystem>

using std::setw;
using std::time;
namespace fs = std::filesystem;

vector<string> getFiles(string path = "./files/") {
  vector<string> files;
  for (const auto & entry : fs::directory_iterator(path)) {
      string file = entry.path().string();
      files.push_back(file);
      //cout << file << endl;
  }
  return files;
}

void grasp(string file) {
  int m = 2;
  int j = 1;
  //Maxdiversity max(file, new Grasp());
  while (m < 6) {
    j = 1;
    while (j < 4) {
      Maxdiversity max(file, new Grasp());
      Solution s = max.solve(max,m,j);
      string name = file.substr(8,file.length());
      cout << name << setw(4) << max.getSize() << setw(4);
      cout << max.getDimension() << setw(4) << m << setw(4);
      cout << j << setw(8) << s.distanceTotal() << setw(8) << s.getTimeCost() << endl;
      //cout << "S: ";
      //s.print();
      j++;
    }
    m++;
  }
}

void greedy(string file) {

  int m = 2;
  while (m < 6) {
    Maxdiversity max(file, new Grasp());
    Solution s = max.solve(max,m,1);
    string name = file.substr(8,file.length());
    cout << name << setw(4) << max.getSize() << setw(4);
    cout << max.getDimension() << setw(4) << m << setw(12);
    cout << s.distanceTotal() << setw(8) << s.getTimeCost() << endl;
    //cout << "S: ";
    //s.print();
    m++;
  }
}

int main(int argc, char** argv) {
  struct timespec ts;
  auto start = std::chrono::high_resolution_clock::now();
  auto finish = std::chrono::high_resolution_clock::now();
  auto s = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
  srand(s);
  if (argc < 2) {
    string file;
    vector<string> files = getFiles();
    //Greedy
    cout << "Problema" << setw(12) << "n" << setw(4) << "K" << setw(4) << "m";
    cout << setw(10) << "z" << setw(9) << "CPU" << endl;
    for (int i = 0; i < files.size(); i++) {
      file = files[i];
      greedy(file);
      cout << endl;
    }
    //Grasp
    cout << "Problema" << setw(12) << "n" << setw(4) << "K" << setw(4) << "m";
    cout << setw(4) << "LRC" << setw(4) << "z" << setw(12) << "CPU" << endl;
    for (int i = 0; i < files.size(); i++) {
      file = files[i];
      grasp(file);
      cout << endl;
    }

  } else {
    string path = argv[1];
    int m = 2;
    cout << path << endl;
    //max.print();
    int j = 1;
    cout << "Problema" << setw(12) << "n" << setw(4) << "K" << setw(4) << "m";
    cout << setw(4) << "LRC" << setw(4) << "z" << setw(12) << "CPU" << endl;
    Maxdiversity max(path, new Grasp());
    while (m < 6) {
      j = 1;
      while (j < 4) {
        Solution s = max.solve(max,m,j);
        cout << path << setw(4) << max.getSize() << setw(4);
        cout << max.getDimension() << setw(4) << m << setw(4);
        cout << j << setw(8) << s.distanceTotal() << setw(8) << s.getTimeCost() << endl;
        //cout << "S: ";
        //s.print();
        j++;
      }
      m++;
    }
    /*
    auto to = max.getPointsCopy();
    Solution sol(to);
    auto v = sol.centroid(2);
    for (auto element : v) cout << element << ",";
    */
  }
}