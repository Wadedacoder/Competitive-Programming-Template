const bool SCALING = 0;
const int init_thresh = (1LL << 30); // make it a power of 2 for correctness
int thresh = init_thresh;

int n, m;

int adj[maxn][maxn];
vector<int> edges[maxn];
int level[maxn];
int ptr[maxn];

void add_cap(int u, int v, int cap){
    adj[u][v] += cap;
}

void remove_flow(int u, int v, int flow){
    adj[u][v] -= flow;
}

bool bfs(int s, int t){
    queue<int> q;
    q.push(s);
    memset(level, -1, sizeof(level));
    level[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : edges[u]){
            if(level[v] == -1 && adj[u][v] >= thresh){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int flow, int t){
    if(u == t || flow == 0){
        return flow;
    }
    for(int &i = ptr[u]; i < edges[u].size(); i++){
        int v = edges[u][i];
        if(level[v] == level[u] + 1 && adj[u][v] >= thresh){
            int pushed = dfs(v, min(flow, adj[u][v]), t);
            if(pushed){
                remove_flow(u, v, pushed);
                add_cap(v, u, pushed);
                return pushed;
            }
        }
    }
    return 0;
}

int max_flow_scaling_dinic(int s, int t){
    int flow = 0;
    if(!SCALING){
        thresh = 1;
    }
    for(thresh = init_thresh; thresh >= 1; thresh >>= 1){
        while(bfs(s, t)){
            memset(ptr, 0, sizeof(ptr));
            while(int pushed = dfs(s, inf, t)){
                flow += pushed;
            }
        }
    }
    return flow;
}
