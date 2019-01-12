#include "graph.h"
#include "unionfind.h"
class Kruskal {
public:
  vector<pair<int, int> > MST;
  int MSTWeight;
  Kruskal() {
    MSTWeight = 0;
  }

  // TODO to pass objects in constructor
  void FindMST(Graph g, UnionFind uf) {
    g.sortEdges();

    int count = 0;
    for(int i = 0; count < g.V - 1 && i < g.E; i++) {
      int u = g.edges[i].second.first;
      int v = g.edges[i].second.second;
      int w = g.edges[i].first;

      cout<<u<<" "<<v<<endl;
      if(!uf.connected(u, v)) {
        uf.merge(u, v);
        MST.push_back(make_pair(u, v));
        count++;
      }
    }
  }

  void printMST() {
    vector<pair<int,int> >::iterator it;
    for(it = MST.begin(); it != MST.end(); it++) {
      cout<<it->first<<" "<<it->second<<endl;
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

  UnionFind uf(7);

  Kruskal k;
  k.FindMST(g, uf);
  k.printMST();
}
