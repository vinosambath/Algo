#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Graph {
public:
  int V, E;
  vector<pair<int,pair<int,int> > > edges;
  Graph(int V, int E);
  void addEdge(int u, int v, int w);
  void printGraph();
  void sortEdges();
};
