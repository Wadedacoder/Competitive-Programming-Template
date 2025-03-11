#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

//Dijkstra's Algorithm
class Node{
    public:
    vector<vector<int>> edges;
    int wt;
    int parent;
    Node(){
        wt = inf;
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

int distance_calc(vector<int>& edge){
    int u = edge[0];
    int v = edge[1];
    int x_i = edge[2];
    return x_i;
}

// Prim's Algorithm
int Prim(vector<Node>& nodes, int s){ // return the max wt edge in the tree
    nodes[s].wt = 0;
    int max_wt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        int d_init = pq.top().first;
        pq.pop();
        if(nodes[u].wt < d_init){ 
            continue;
        }
        max_wt = max(max_wt, nodes[u].wt);
        for(int i = 0; i < nodes[u].edges.size(); i++){
            int v = nodes[u].edges[i][1];
            int d2 = distance_calc(nodes[u].edges[i]);
            if(d2 < nodes[v].wt){
                nodes[v].wt = d2;
                nodes[v].parent = u;
                pq.push({nodes[v].wt, v});
            }
        }
    }
}