#include "graph.h"
#include <queue>

class MaxFlow {
public:
  // to reduce key strokes rGraph -> residual Graph
  vector<vector<int> > rGraph;
  int V;
  MaxFlow(Graph g) {
    rGraph = vector<vector<int> >(g.V, vector<int>(g.V));
    V = g.V;
    for (int i = 0; i < g.V; i++) {
      for(int j = 0; j < g.V; j++) {
        rGraph[i][j] = g.mrGraph[i][j];
      }
    }
  }

  bool bfs(vector<vector<int> > rGraph, int s, int t, int parent[]) {
    vector<int> visited = vector<int>(V);
    queue<int> q;
    q.push(s);

    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()) {
      int u = q.front();
      q.pop();

      for(int v = 0; v < V; v++) {
        if(!visited[v] && rGraph[u][v] > 0) {
          q.push(v);
          parent[v] = u;
          visited[v] = 1;
        }
      }
    }
    return visited[t] == 1;
  }

  void findMaxFlow(int s, int t) {
    for(int i = 0; i < V; i++) {
       for(int j = 0; j < V; j++) {
         cout<<rGraph[i][j]<<" ";
       }
       cout<<endl;
    }
    int parent[V], max_flow = 0;
    int i = 0;
    while(bfs(rGraph, s, t, parent)) {
      int path_flow = 20343438;
      for(int v = t; v != s; v = parent[v]) {
          int u = parent[v];
          path_flow = min(path_flow, rGraph[u][v]);
      }
      for(int v = t; v != s; v = parent[v]) {
        int u = parent[v];
        rGraph[u][v] -= path_flow;
        rGraph[v][u] += path_flow;
      }
      max_flow += path_flow;
      cout<<max_flow<<endl;
    }
    for(int i = 0; i < V; i++) {
       for(int j = 0; j < V; j++) {
         cout<<rGraph[i][j]<<" ";
       }
       cout<<endl;
    }
  }
};

int main() {
  Graph g(8, 9);
  g.addEdge(1, 2, 1);
  g.addEdge(1, 5, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(6, 7, 1);
  g.addEdge(7, 3, 1);
  g.addEdge(3, 2, 1);
  g.addEdge(2, 4, 1);
  g.printGraph();
  g.printAdjListRepresentation();
  //g.printMatrixRepresentation();

  MaxFlow m(g);
  m.findMaxFlow(1, 7);
}
