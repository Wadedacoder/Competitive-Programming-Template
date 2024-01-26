#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

// Structure for Graph
class Node{
    public:
    vector<vector<int>> edges;
    int dist;
    int parent;
    Node(){
        dist = inf;
        parent = -1;
    }

    void add_edge(int u, int v, int x_i){
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edge.push_back(x_i);
        edges.push_back(edge);
    }
};

int distance_calc(int d1, vector<int> edge){
    int u = edge[0];
    int v = edge[1];
    int x_i = edge[2];
    int cur_dist = d1;
    return cur_dist + x_i;
}
