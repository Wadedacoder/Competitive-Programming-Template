#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

// Structure for Graph
class Node{
    public:
    vector<vector<int>> edges;
    int dist;
    int parent;
    int size; // size of the component
    Node(){
        dist = inf;
        parent = -1;
        size = 1;
    }

    void add_edge(int u, int v, int x_i){
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edge.push_back(x_i);
        edges.push_back(edge);
    }
};

int distance_calc(int d, vector<int>& edge){
    return d + edge[2];
}

// Structure for Disjoint Set Union
class DSU{
    public:
    vector<Node> nodes;
    DSU(int n){
        for(int i=0; i<n; i++){
            Node node;
            nodes.push_back(node);
        }
    }

    DSU(vector<Node>& nodes){
        this->nodes = nodes;
    }

    int find(int u){
        if(nodes[u].parent == -1){
            return u;
        }
        nodes[u].parent = find(nodes[u].parent); // path compression
        return nodes[u].parent;
    }

    void union_(int u, int v){
        int u_rep = find(u);
        int v_rep = find(v);
        if(u_rep != v_rep){
            if(nodes[u_rep].size < nodes[v_rep].size){
                swap(u_rep, v_rep); // Union by size
            }
            nodes[u_rep].parent = v_rep;
            nodes[v_rep].size += nodes[u_rep].size;
        }
    }

    int size(int u){
        return nodes[find(u)].size;
    }

};
