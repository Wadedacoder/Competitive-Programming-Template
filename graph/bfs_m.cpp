#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

void bfs (vector<vector<char>>& v, int xa, int ya, int xb, int yb){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dist(n, vector<int>(m, inf));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;

    q.push({xa, ya});
    dist[xa][ya] = 0;
    par[xa][ya] = {-1, -1};
    while (!q.empty())
    {
       if(dist[xb][yb] != inf){
           break;
       }
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x + 1 < n && v[x + 1][y] != '#' && dist[x + 1][y] == inf){
            dist[x + 1][y] = dist[x][y] + 1;
            par[x + 1][y] = {x, y};
            q.push({x + 1, y});
        }
        if(x - 1 >= 0 && v[x - 1][y] != '#' && dist[x - 1][y] == inf){
            dist[x - 1][y] = dist[x][y] + 1;
            par[x - 1][y] = {x, y};
            q.push({x - 1, y});
        }
        if(y + 1 < m && v[x][y + 1] != '#' && dist[x][y + 1] == inf){
            dist[x][y + 1] = dist[x][y] + 1;
            par[x][y + 1] = {x, y};
            q.push({x, y + 1});
        }
        if(y - 1 >= 0 && v[x][y - 1] != '#' && dist[x][y - 1] == inf){
            dist[x][y - 1] = dist[x][y] + 1;
            par[x][y - 1] = {x, y};
            q.push({x, y - 1});
        }
    }
}