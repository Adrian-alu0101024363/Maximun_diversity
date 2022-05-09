#include "headers/maxdiversity.h"


int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Please specify the path to file" << endl;
  } else {
    string path = argv[1];
    cout << path;
    Maxdiversity max(path);
    max.print();
  }
}