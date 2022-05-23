#include "Algoritmo.h"
#include "maxdiversity.h"
#include "Greedy.h"
//#include "BABTree.h"

class Branch : public Algoritmo {
  /*private:
    //BABTree* tree;
    int solutionSize;
    Solution bestFound;
    //vector<BABNode> alreadyExpanded;
    Maxdiversity original;
    Solution dataO;*/
  public:
  Solution solve(Maxdiversity max, int m, int rlc);
  //void branchOut(BABNode* set);
  //bool worthy(BABNode* node);
  //void exploreDepthFirst(BABNode* currentNode);
  vector<Solution> getValidactives(Solution element, Maxdiversity max, double lower, int m);
};
