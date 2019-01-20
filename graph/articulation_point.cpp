#include "graph.h"

void APUtil(Graph g, int node, vector<bool> &visited, vector<bool> &AP, vector<int> &parent, vector<int> &disc, vector<int> &low) {
  static int time = 0;
  int children = 0;
  time++;

  visited[node] = true;
  low[node] = disc[node] = time;

  vector<graphpair>::iterator it;
  for(it = g.adj[node].begin(); it != g.adj[node].end(); it++) {
    if (!visited[it->first]) {
      children++;
      parent[it->first] = node;
      APUtil(g, it->first, visited, AP, parent, disc, low);

      low[node] = min(low[node], low[it->first]);

      if(parent[node] == -1 && children > 0) {
        cout<<node<<" is an articulation point"<<endl;
        AP[node] = true;
      }

      if(parent[node] != -1 && low[it->first] > disc[node])
      {
        cout<<node<<" is an articulation point"<<endl;
        cout<<"The edge from "<<node<<" to "<<it->first<<" is a bridge in the given graph"<<endl;
        AP[node] = true;
      }

    } else if(it->first != parent[node]) {
      low[node] = min(low[node], disc[it->first]);
    }

  }
 }

int main() {
  Graph g(6, 6);
  g.addEdge(0, 1, 16);
  g.addEdge(1, 2, 12);
  g.addEdge(2, 3, 20);
  g.addEdge(3, 4, 13);
  g.addEdge(3, 5, 4);
  g.addEdge(5, 1, 10);
  g.printGraph();
  cout<<endl;
  g.printAdjListRepresentation();

  vector<bool> visited(g.V, false), AP(g.V, false);
  vector<int> parent(g.V, -1), disc(g.V, -1), low(g.V, -1);

  for(int i = 0; i < g.V; i++) {
    if(!visited[i])
      APUtil(g, 0, visited, AP, parent, disc, low);
  }

  // cout<<"Disc and low values"<<endl;
  // for(int i = 0; i < g.V; i++) {
  //   cout<<i<<" "<<disc[i]<<" "<<low[i]<<endl;
  // }
  // cout<<endl;

  // cout<<"Articulation points are "<<endl;
  //   for(int i = 0; i < g.V; i++) {
  //     if(AP[i]) {
  //       cout<<i<<endl;
  //     }
  //   }
  //   cout<<endl;s
}
