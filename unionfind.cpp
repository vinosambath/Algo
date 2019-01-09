#include <iostream>
#include <vector>
using namespace std;

/*

Union Find by rank algorithm finds cycle in an undirected graph
It is an optimized version of Union Find algorithm
Time complexity of Union Find by rank is O(log n)
It uses rank and path compression to find cycle in a graph
The idea is to flatten the tree when find() is called

*/

struct Edge {
  int u, v, weight;
};

class UnionFind {
public:
  int *parent, cnt, *rank;
  UnionFind(int N) {
    cnt = N;
    parent = new int[N];
    rank = new int[N];
    for(int i = 0; i < N; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  int find(int x) {
    cout<<"Find"<<x<<endl;
    if(parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void merge(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    if(xRoot == yRoot) return;
    if(rank[xRoot] < rank[yRoot]) {
      parent[xRoot] = yRoot;
    } else if(rank[xRoot] > rank[yRoot]){
      parent[yRoot] = xRoot;
    } else {
      parent[yRoot] = xRoot;
      rank[yRoot]++;
    }
  }

  bool connected(int x, int y) {
    return parent[x] == parent[y];
  }
};

// int main() {
//   UnionFind uf(10);
//   vector<int> a, b;
//   a.push_back(1); b.push_back(2);
//   a.push_back(2); b.push_back(3);
//   a.push_back(1); b.push_back(5);
//   a.push_back(2); b.push_back(4);
//   a.push_back(5); b.push_back(6);
//   a.push_back(6); b.push_back(7);
//   a.push_back(3); b.push_back(7);
//   for(int i = 0; i < 7; i++) {
//     cout<<"I am here"<<endl;
//     if(!uf.connected(a[i], b[i])) {
//       uf.merge(a[i], b[i]);
//     } else {
//       cout<<"Cycle found"<<a[i]<<" "<<b[i]<<endl;
//     }
//   }
//   return 0;
// }
