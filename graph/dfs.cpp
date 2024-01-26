
class Node{
    public:
    vector<int> edges;
    bool visited;
    int dist;
    int parent;
    Node(){
        dist = inf;
        parent = -1;
        visited = false;
    }

    void add_edge(int v){
        edges.push_back(v);
    }
};

void dfs(vector<Node>& nodes, int u){
    nodes[u].visited = true;
    for(int i = 0; i < nodes[u].edges.size(); i++){
        int v = nodes[u].edges[i];
        if(!nodes[v].visited){
            dfs(nodes, v);
        }
    }
}