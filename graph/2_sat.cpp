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

bool sat2(int n, vector<pair<int, int>> &clauses){
    SCC scc(2*n);
    for(auto &clause: clauses){
        int u = clause.first;
        int v = clause.second;
        if(u < 0){
            u = 2*(-u) - 1;
        }
        else{
            u = 2*u - 2;
        }
        if(v < 0){
            v = 2*(-v) - 1;
        }
        else{
            v = 2*v - 2;
        }
        scc.add_edge(u^1, v);
        scc.add_edge(v^1, u);
    }
    scc.kosaraju();
    for(int i = 0; i < n; i++){
        if(scc.nodes[2*i].comp == scc.nodes[2*i + 1].comp){
            return false;
        }
    }
    return true;
    
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> clauses;
    for(int i = 0; i < n; i++){
        clauses.push_back({a[0][i], a[1][i]});
        clauses.push_back({a[1][i], a[2][i]});
        clauses.push_back({a[2][i], a[0][i]});
    }
    if(sat2(n, clauses)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}