#include "graph.h"
#include <queue>

// Prims implementation requires the graph to be present, not only the endges

class PrimsLazy {
public:
  vector<pair<int, int> >MST;
  int MSTWeight = 0;
  bool visited[1000];
  PrimsLazy() {
    MSTWeight = 0;
    for(int i = 0; i < 1000; i++) visited[i] = false;
  }

  // TODO to pass g in constructor and fix visited static allocation
  void FindMST(Graph g) {
    priority_queue<int> q;
    visited[1] = true;
    q.
  }
};

int main() {
  Graph g(7, 7);
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

  PrimsLazy p;
  p.FindMST(g);
  p.printMST();
}
