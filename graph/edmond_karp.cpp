const bool SCALING = 0;
const int init_thresh = 1e9;
int thresh = init_thresh;

struct Node{
public:
    vector<int> edges;
    int level;
    
    Node(int n){
        edges.resize(n);
        level = -1;
    }
        

    void add_edge(int v, int cap){
        edges[v] += cap;
    }

    void add_flow(int v, int flow){
        edges[v] -= flow;
    }
};


int max_flow_scaling(int s, int t, vector<Node> &nodes){
    int ans = 0;
    while(thresh > 0){
        vector<int> parent(nodes.size(), -1);
        vector<int> flow(nodes.size(), 0);
        queue<int> q;
        q.push(s);
        flow[s] = inf;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v = 0; v < nodes.size(); v++){
                if(parent[v] == -1 && nodes[u].edges[v] >= thresh){
                    parent[v] = u;
                    flow[v] = min(flow[u], nodes[u].edges[v]);
                    if(v == t){
                        break;
                    }
                    q.push(v);
                }
            }
        }
        if(flow[t] == 0){
            thresh /= 2;
            continue;
        }
        ans += flow[t];
        int v = t;
        while(v != s){
            int u = parent[v];
            nodes[u].add_flow(v, flow[t]);
            nodes[v].add_flow(u, -flow[t]);
            v = u;
        }
    }
    return ans;
}