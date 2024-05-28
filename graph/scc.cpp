#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

// Structure for Graph
class Node{
    public:
    vector<int> edges;
    int comp;
    bool visited;
    Node(){
        visited = false;
        comp = -1;
    }

    void add_edge(int v){
        edges.push_back(v);
    }
};

// Structure for SCC
class SCC{
    public:
    vector<Node> nodes;
    vector<Node> rev_nodes;
    vector<int> order;
    int n;
    int comp_count;
    SCC(int n){
        this->n = n;
        nodes.resize(n);
        rev_nodes.resize(n);
        comp_count = 0;
    }

    void add_edge(int u, int v){
        nodes[u].add_edge(v);
        rev_nodes[v].add_edge(u);
    }

    void dfs1(int u){
        nodes[u].visited = true;
        for(int i = 0; i < nodes[u].edges.size(); i++){
            int v = nodes[u].edges[i];
            if(!nodes[v].visited){
                dfs1(v);
            }
        }
        order.push_back(u);
    }

    void dfs2(int u){
        nodes[u].visited = true;
        nodes[u].comp = comp_count;
        for(int i = 0; i < rev_nodes[u].edges.size(); i++){
            int v = rev_nodes[u].edges[i];
            if(!nodes[v].visited){
                dfs2(v);
            }
        }
    }

    void kosaraju(){
        for(int i = 0; i < n; i++){
            if(!nodes[i].visited){
                dfs1(i);
            }
        }
        reverse(order.begin(), order.end()); 
        for(int i = 0; i < n; i++){
            nodes[i].visited = false;
        }
        for(int i = 0; i < n; i++){
            int u = order[i];
            if(!nodes[u].visited){
                dfs2(u);
                comp_count++;
            }
        }
    }

    void print_scc(){
        for(int i = 0; i < n; i++){
            cout << i << " " << nodes[i].comp << endl;
        }
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        scc.add_edge(u, v);
    }
    scc.kosaraju();
    if(scc.comp_count == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
        // find a node with comp = 0 and a node with comp = 1
        // print the nodes
        int u = -1, v = -1;
        for(int i = 0; i < n; i++){
            if(scc.nodes[i].comp == 0){
                u = i;
            }
            if(scc.nodes[i].comp == 1){
                v = i;
            }
            if(u != -1 && v != -1){
                break;
            }
        }
        // check if node u is reachable from node v
        // if yes, print v and u
        // else print u and v
        bool flag = false;
        for(int i = 0; i < n; i++){
            scc.nodes[i].visited = false;
        }
        scc.dfs1(u);
        if(scc.nodes[v].visited){
            cout << v + 1 << " " << u + 1 << endl;
        }
        else{
            cout << u + 1 << " " << v + 1 << endl;
        }

    }
    // scc.print_scc();
}