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

  void dfs(int s, vector<bool> &visited) {
    visited[s] = true;
    for(int i = 0; i < V; i++) {
      if(rGraph[s][i] && !visited[i]) {
        dfs(i, visited);
      }
    }
  }


  void findMinCut(Graph g, int s) {
    vector<bool> visited(V, false);
    dfs(s, visited);

    cout<<"Min cut edges are "<<endl;
    for(int i = 0; i < V; i++) {
       for(int j = 0; j < V; j++) {
         if(g.mrGraph[i][j] && !visited[j] && visited[i]) {
           cout<<i<<" -  "<<j<<endl;
         }
       }
    }
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
    }
    cout<<"Max Flow is "<<max_flow<<endl;
  }

  void printrGraph() {
    for(int i = 0;i < V; i++) {
      for(int j = 0; j < V; j++) {
        cout<<rGraph[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};

int main() {
  Graph g(6, 10);
  // g.addEdge(1, 2, 1);
  // g.addEdge(1, 5, 1);
  // g.addEdge(5, 6, 1);
  // g.addEdge(6, 7, 1);
  // g.addEdge(7, 3, 1);
  // g.addEdge(3, 2, 1);
  // g.addEdge(2, 4, 1);
  g.addEdge(0, 1, 16);
  g.addEdge(1, 3, 12);
  g.addEdge(3, 5, 20);
  g.addEdge(0, 2, 13);
  g.addEdge(2, 1, 4);
  g.addEdge(1, 2, 10);
  g.addEdge(2, 4, 14);
  g.addEdge(3, 2, 9);
  g.addEdge(4, 5, 4);
  g.addEdge(4, 3, 7);
  g.printGraph();
  cout<<endl;
  g.printAdjListRepresentation();
  g.printMatrixRepresentation();

  MaxFlow m(g);
  m.printrGraph();
  cout<<endl;
  m.findMaxFlow(0, 5);
  m.printrGraph();

  m.findMinCut(g, 0);
}
