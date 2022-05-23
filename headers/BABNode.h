#include <vector>
#include "Solution.h"
using namespace std;

class BABNode {
  private: 
  Solution set;
  BABNode* father_;
  vector<BABNode*> links;
  int level;
  public:
  BABNode(Solution value);
  BABNode(Solution sol, BABNode* father);
  int getLevel() {return level;}
  vector<BABNode*> getLinks() {return links;}
  BABNode* getFather() {return father_;}
  Solution& getSet() {return set;}
  Solution getSetCopy() {return set;}
  void bound() {Solution p; set = p; links.clear();}
  void generateSons(Maxdiversity all);
};