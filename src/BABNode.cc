#include "../headers/BABNode.h"

BABNode::BABNode(Solution value) {
  set = value;
  father_ = nullptr;
  //links = new vector<BABNode*>;
  level = 0;
}
BABNode::BABNode(Solution sol, BABNode* father) {
  set = sol;
  father_ = father;
  //links = new vector<BABNode*>;
  level = father_->getLevel() + 1;
}

void BABNode::generateSons(Maxdiversity all) {
  auto elements = all.getPointsCopy();
  auto actual = set.getElementsCopy();
  for (int i =0; i < elements.size(); i++) {
    if (!(std::find(actual.begin(), actual.end(), elements[i]) != actual.end())) {
      auto sonSet = set;
      sonSet.add(elements[i]);
      links.push_back(new BABNode(sonSet,this));
    }
  }
}