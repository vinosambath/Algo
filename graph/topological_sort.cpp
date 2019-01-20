#include "graph.h"
#include <iostream>
#include <stack>
using namespace std;

void topological_sort(Graph g, int source, vector<bool> &visited, stack<int> &toplogical_order) {
  vector<graphpair>::iterator it;
  visited[source] = true;
  for(it = g.adj[source].begin(); it != g.adj[source].end(); it++) {
    if(!visited[it->first]) {
      topological_sort(g, it->first, visited, toplogical_order);
    }
  }
  toplogical_order.push(source);
}

int main() {
  Graph g(6, 9);
  g.addEdge(0, 1, 16);
  g.addEdge(1, 3, 12);
  g.addEdge(3, 5, 20);
  g.addEdge(0, 2, 13);
  g.addEdge(1, 2, 10);
  g.addEdge(2, 4, 14);
  g.addEdge(3, 2, 9);
  g.addEdge(4, 5, 4);
  g.addEdge(4, 3, 7);
  g.printGraph();
  cout<<endl;
  g.printAdjListRepresentation();

  stack<int> toplogical_order;
  vector<bool> visited(g.V, false);

  for(int i = 0; i < g.V; i++) {
    if(!visited[i]) {
      topological_sort(g, i, visited, toplogical_order);
    }
  }

  cout<<"The topological order is "<<endl;
  while(!toplogical_order.empty()) {
    cout<<toplogical_order.top()<<endl;
    toplogical_order.pop();
  }

}
