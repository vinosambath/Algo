#include <iostream>
#include <vector>
#include <utility>
#include <list>

typedef std::pair<int, int> graphpair;

using namespace std;
class Graph {
public:
  int V, E;
  vector<graphpair> *adj;
  vector<pair<int,pair<int,int> > > edges;
  Graph(int V, int E);
  void addEdge(int u, int v, int w);
  void printGraph();
  void printAdjListRepresentation();
  void sortEdges();
};
