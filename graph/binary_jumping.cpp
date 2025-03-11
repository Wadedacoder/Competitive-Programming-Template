#include <bits/stdc++.h>
#define inf 1e10

const int maxn = 1e6 + 5;
int N = 4*1e6;
constexpr int LOG = 20;

int k_than[maxn][LOG];

class Node{
    public:
    int data;
    vector<int> children;
    int parent;
    int depth;
    Node(){
        data = 0;
        parent = -1;
        depth = -1;
    }
};

void dfs(int node, int parent, int depth, vector<Node> &nodes){
    k_than[node][0] = parent;
    nodes[node].parent = parent;
    nodes[node].depth = depth;
    for(int i = 1; i < LOG; i++){
        // cout << "node: " << node << " i: " << i << " k_than[node][i-1]: " << k_than[node][i-1] << endl;
        k_than[node][i] = k_than[k_than[node][i-1]][i-1];
    }
    for(auto child: nodes[node].children){
        if(child != parent){
            dfs(child, node, depth+1, nodes);
        }
    }
    
}

int find_kth_ancestor(int node, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1<<i)){
            node = k_than[node][i];
        }
    }
    return node;
}

int LCA(int a, int b, vector<Node> &nodes){
    if(nodes[a].depth < nodes[b].depth){
        swap(a, b);
    }
    // same depth
    a = find_kth_ancestor(a, nodes[a].depth - nodes[b].depth);
    // if a is the ancestor of b
    if(a == b){
        return a;
    }
    // find the lowest common ancestor
    for(int i = LOG-1; i >= 0; i--){
        // if not the same ancestor then move up
        if(k_than[a][i] != k_than[b][i]){
            a = k_than[a][i];
            b = k_than[b][i];
        }
    }
    return k_than[a][0];
}
