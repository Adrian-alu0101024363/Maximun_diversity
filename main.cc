#include "headers/maxdiversity.h"
#include "headers/Grasp.h"


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Please specify the path to file" << endl;
  } else {
    string path = argv[1];
    cout << path << endl;
    Maxdiversity max(path, new Grasp());
    //max.print();
    Solution s = max.solve(max,2);
    cout << "Solution elements: " << endl;
    s.print();
    cout << "Distance sum: " << s.distanceTotal() << endl;
    cout << "Time Cost: " << s.getTimeCost() << endl;
    /*
    auto to = max.getPointsCopy();
    Solution sol(to);
    auto v = sol.centroid(2);
    for (auto element : v) cout << element << ",";
    */
  }
}