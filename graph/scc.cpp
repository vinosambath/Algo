#include "graph.h"
#include <iostream>
#include <stack>
using namespace std;

/*
Finds the Strongly Connected Components
*/

void fillOrder(Graph g, stack<int> &st, vector<bool> &visited, int u) {
  vector<graphpair>::iterator it;
  visited[u] = true;
  for(it = g.adj[u].begin(); it != g.adj[u].end(); it++) {
    int v = it->first;
    if(!visited[v]) {
      fillOrder(g, st, visited, v);
    }
  }
  st.push(u);
}

void dfs(Graph g, vector<bool> &visited, int source) {
  vector<graphpair>::iterator it;
  visited[source] = true;
  cout<<source<<" ";
  for(it = g.rGraph[source].begin(); it != g.rGraph[source].end(); it++) {
    int v = it-> first;
    if(!visited[v]) {
      dfs(g, visited, v);
    }
  }
}



void scc(Graph g, int s) {
  stack<int> st;
  vector<bool> visited(g.V, false);
  for(int i = 0; i < g.V; i++) {
    if(!visited[i]) {
      fillOrder(g, st, visited, i);
    }
  }

  g.reverseGraph();
  fill(visited.begin(), visited.end(), false);

  while(!st.empty()) {
    int node = st.top();
    st.pop();
    if(!visited[node]) {
      dfs(g, visited, node);
      cout<<endl;
    }
  }
}



int main() {
  Graph g(6, 11);
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

  scc(g, 0);
}
