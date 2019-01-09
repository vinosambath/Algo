#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
  int *parent, cnt, *rank;
  UnionFind(int N);
  int find(int x);
  void merge(int x, int y);
  bool connected(int x, int y);
};
