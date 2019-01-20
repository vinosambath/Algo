#include "graph.h"
#include <queue>

// Prims implementation requires the graph to be present, not only the endges

class PrimsLazy {
public:
  vector<pair<int, int> >MST;
  int MSTWeight = 0;
  bool inMST[1000];
  PrimsLazy() {
    MSTWeight = 0;
    for(int i = 0; i < 1000; i++) inMST[i] = false;
  }

  // TODO to pass g in constructor and fix visited static allocation
  void FindMST(Graph g, int src) {
    priority_queue<pair<int, int> > pq;
    vector<int> key(g.V, 10343434);
    pq.push(make_pair(0, src));
    key[src] = 0;

    while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      vector< pair<int, int> >::iterator it;
      for(it = g.adj[u].being(); it != g.adj[u].end(); it++) {

      }
    }

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
