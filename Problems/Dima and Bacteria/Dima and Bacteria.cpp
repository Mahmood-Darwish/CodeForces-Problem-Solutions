#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

int n, m, k, num, u, v, x;
vector < pair < int , int > > adj[200001], adj3[200001];
vector < int > adj2[200001];
int dis_arr[501][501];
int type[200001];
bool vis[200001];
bool tvis[501];

void DFS(int node)
{
    if(vis[node])
        return;
    vis[node] = true;
    for(auto cur : adj2[node])
        if(!vis[cur])
            DFS(cur);
    return;
}

void dijkstra(int node)
{
    bool type_vis[501];
    int dis[501];
    memset(type_vis, 0, sizeof(type_vis));
    memset(dis, -1, sizeof(dis));
    priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > PQ;
    PQ.push({0, node});
    dis[node] = 0;
    while(!PQ.empty()){
        pair < int , int > U = PQ.top();
        PQ.pop();
        if(type_vis[U.S])
            continue;
        type_vis[U.S] = true;
        for(auto cur : adj3[U.S]){
            if(dis[cur.F] > U.F + cur.S || dis[cur.F] == -1){
                dis[cur.F] = U.F + cur.S;
            }
            if(!type_vis[cur.F])
                PQ.push({dis[cur.F], cur.F});
        }
    }
    for(int i = 1 ; i <= k ; i++){
        dis_arr[node][i] = dis[i];
    }
    return;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int temp = 1;
    for(int i = 1 ; i <= k ; i++){
        scanf("%d", &num);
        while(num--){
            type[temp] = i;
            temp++;
        }
    }
    while(m--){
        scanf("%d %d %d", &u, &v, &x);
        adj[u].pb({v, x});
        adj[v].pb({u, x});
        if(!x){
            adj2[u].pb(v);
            adj2[v].pb(u);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(!tvis[type[i]]){
            DFS(i);
            tvis[type[i]] = true;
            for(int j = 1 ; j <= n ; j++){
                if(type[i] == type[j] && !vis[j]){
                    printf("No\n");
                    return 0;
                }
            }
            memset(vis, 0, sizeof(vis));
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(auto cur : adj[i]){
            if(type[cur.F] != type[i]){
                adj3[type[i]].pb({type[cur.F], cur.S});
            }
        }
    }/*
    for(int i = 1 ; i <= k ; i++){
        cout << "#" << i << ":" << endl;
        for(auto cur : adj3[i]){
            cout << cur.first << ' ';
        }
        cout << endl;
    }*/
    for(int i = 1 ; i <= k ; i++){
        dijkstra(i);
    }
    printf("Yes\n");
    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j <= k ; j++){
            printf("%d ", dis_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}