#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdio.h>

#define F first
#define S second

using namespace std;

pair < int , int > ans[300100];
vector < pair < int , int > > adj[300100];
int depth[300100], low[300100];
int n, m, timer, u, v;
bool vis[300100];

void DFS(int node, int par = -1)
{
    depth[node] = low[node] = ++timer;
    for(auto cur : adj[node]){
        if(cur.F == par) continue;
        if(depth[cur.F] == -1){
            DFS(cur.F, node);
            low[node] = min(low[node], low[cur.F]);
            if(low[cur.F] > depth[node]){
                cout << "0\n";
                exit(0);
            }
        }
        else low[node] = min(low[node], depth[cur.F]);
        //cout << cur.S << ' ' << node << ' ' << cur.F << endl;
        if(!vis[cur.S])
            ans[cur.S] = {node, cur.F};
        vis[cur.S] = true;
    }
    return;
}

int main()
{
    memset(depth, -1, sizeof(depth));
    memset(low, -1, sizeof(low));
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    DFS(1);
    for(int i = 0 ; i < m ; i++){
        printf("%d %d\n", ans[i].F, ans[i].S);
    }
    return 0;
}