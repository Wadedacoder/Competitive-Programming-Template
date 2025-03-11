//My template https://github.com/Wadedacoder/Competitive-Programming-Template - only reference
#include <bits/stdc++.h>
#define inf 1e10

struct triplet{
    int x; // u
    int y; // v
    int z; // size of any one of the components
};

vector<triplet> bridges;
vector<int> articulation_points;

// Structure for Graph
class Node{
    public:
    vector<vector<int>> edges;
    // int dist;
    int parent;
    // tarjan bridge detection
    int low;
    int tin;
    bool visited;

    Node(){
        // dist = inf;
        parent = -1;
        low = -1;
        tin = -1;
        visited = false;
    }

    void add_edge(int u, int v){
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edges.push_back(edge);
    }
};

// dfs for finding bridges, returns the size of the component
int dfs(vector<Node> &graph, int u, int time = 0){
    graph[u].visited = true;
    graph[u].tin = time;
    graph[u].low = time;
    time++;
    int size = 0;
    // cout << "Before " << u << " " << graph[u].tin << " " << graph[u].low << endl;
    // bool parent_skip = false;
    for(auto edge: graph[u].edges){
        int v = edge[1];
        if(v == graph[u].parent) continue;
        if(!graph[v].visited){
            graph[v].parent = u;
            int tmp = dfs(graph, v, time);
            graph[u].low = min(graph[u].low, graph[v].low);
            if(graph[v].low > graph[u].tin){
                // cout << "Bridge: " << u << " " << v << " Due to " << graph[u].tin << " " << graph[v].low << endl;
                bridges.push_back({u,v,tmp});
            }
            if(graph[v].low >= graph[u].tin && graph[u].parent != -1){
                // cout << "Articulation Point: " << u << " Due to " << graph[u].tin << " " << graph[v].low << endl;
                articulation_points.push_back(u);
            }
            size += tmp;
        }else{
            graph[u].low = min(graph[u].low, graph[v].tin);
        }
    }
    if (graph[u].parent == -1 && graph[u].edges.size() > 0){
        // cout << "Articulation Point: " << u << " Due to " << graph[u].tin << " " << graph[u].low << endl;
        articulation_points.push_back(u);
    }
    // cout << "After " << u << " " << graph[u].tin << " " << graph[u].low << endl;
    return size+1;
}