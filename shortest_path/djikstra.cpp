#include "../graph.h"
#include <queue>

class Djikstra {
public:
  priority_queue<pair<int, int> > pq;
  int dist[1000];
  Djikstra() {
    for(int i = 0; i < 500; i++) {
      dist[i] = 23423232;
    }
  }

  void shortestDistance(Graph g, int src) {
    dist[src] = 0;
    vector<graphpair>::iterator it;

    pq.push(make_pair(0, src));
    while(!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      for(it = g.adj[u].begin(); it != g.adj[u].end(); it++) {
        int v = it -> first;
        int w = it -> second;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push(make_pair(dist[v], v));
        }
      }
    }
  }

  void printShortestDistance(Graph g) {
    for(int i = 0; i < g.V; i++) {
      cout<<i<< " - "<<dist[i]<<endl;
    }
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
  d.shortestDistance(g, 1);
  d.printShortestDistance(g);
}
