#include "../graph.h"

class Djikstra {
public:
  Djikstra() {
    vector<int> dist(1000, 123534343);
  }
};

int main() {
  Graph g(8, 7);
  // given as u, v, w
  g.addEdge(1, 2, 1);
  g.addEdge(1, 5, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(6, 7, 2);
  g.addEdge(7, 3, 1);
  g.addEdge(3, 2, 3);
  g.addEdge(2, 4, 1);
  cout<<"The give graph is ----------"<<endl;
  g.printGraph();
  g.printAdjListRepresentation();

  Djikstra d;
  //d.FindShortestDistance();
  //d.printShortestDistance();
}
