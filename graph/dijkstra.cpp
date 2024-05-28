#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

//Dijkstra's Algorithm
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

// Dijkstra's Algorithm
void Dijkstra(vector<Node>& nodes, int s){
    nodes[s].dist = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        int d_init = pq.top().first;
        pq.pop();
        if(nodes[u].dist < d_init){ 
            continue;
        }
        for(int i = 0; i < nodes[u].edges.size(); i++){
            int v = nodes[u].edges[i][1];
            int d2 = distance_calc(d_init, nodes[u].edges[i]);
            if(d2 < nodes[v].dist){
                nodes[v].dist = d2;
                nodes[v].parent = u;
                pq.push({nodes[v].dist, v});
            }
        }
    }
}