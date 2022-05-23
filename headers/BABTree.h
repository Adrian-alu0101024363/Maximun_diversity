#include "BABNode.h"
class BABTree {
 private:
  BABNode* origin;
  public:
  BABTree(Solution set) { origin = new BABNode(set);}
  BABNode* getOrigin() {return origin;}
  //falta clear
};