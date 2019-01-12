#include "graph.h"

Graph::Graph(int v, int e) {
  V = v;
  E = e;
  adj = new vector<graphpair>[V];
}

void Graph::addEdge(int u, int v, int w) {
  adj[u].push_back(make_pair(v, w));
  edges.push_back(make_pair(w, make_pair(u, v)));
}

void Graph::printGraph() {
  vector<pair<int,pair<int,int> > >::iterator it;
  for(it = edges.begin(); it != edges.end(); it++) {
    cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
  }
}

void Graph::printAdjListRepresentation() {
  vector<graphpair>::iterator it;
  for(int i = 0; i < V; i++) {
    for(it = adj[i].begin();it!=adj[i].end();++it){
      cout<<"Edge is present from "<<i<<" to "<<it->first<<" and the weight is "<<it->second<<endl;
    }
  }
}

void Graph::sortEdges() {
  sort(edges.begin(), edges.end());
}

// int main() {
//   Graph g(8, 9);
//   g.addEdge(1, 2, 1);
//   g.addEdge(1, 5, 1);
//   g.addEdge(5, 6, 1);
//   g.addEdge(6, 7, 1);
//   g.addEdge(7, 3, 1);
//   g.addEdge(3, 2, 1);
//   g.addEdge(2, 4, 1);
//   g.printGraph();
//   g.printAdjListRepresentation();
// }
