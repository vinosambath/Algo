#include "../graph.h"
/*

If no negative cycle, Shortest Path Tree (SPT) exist.
If SPT exist, no negative edge exist
Repeat V times

*/
class BellmanFord {
public:
  int dist[1000];
  BellmanFord() {
    for(int i = 0; i < 500; i++) {
      dist[i] = 23423232;
    }
  }

  void shortestDistance(Graph g, int source) {
    bool hasNegativeCycle = false;
    int u, v, w;
    vector<pair<int,pair<int,int> > >::iterator it;
    dist[source] = 0;
    for(int i = 0; i < g.V; i++) {
      for(it = g.edges.begin(); it != g.edges.end(); it++) {
        u = it->second.first;
        v = it->second.second;
        w = it->first;
        if(dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
        }
      }
    }

    // check for negative cycle
    for(it = g.edges.begin(); it != g.edges.end(); it++) {
      u = it->second.first;
      v = it->second.second;
      w = it->first;
      if(dist[v] > dist[u] + w) {
        hasNegativeCycle = true;
        cout<<"Graph contains negative weight cycle"<<endl;
      }
    }

    if(!hasNegativeCycle) {
      for(int i = 0; i < g.V; i++) {
        cout<<i<<" - "<<dist[i]<<endl;
      }
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

  BellmanFord b;
  b.shortestDistance(g, 1);
}
