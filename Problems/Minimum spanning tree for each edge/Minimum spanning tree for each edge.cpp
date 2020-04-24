#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define F first
#define S second

using namespace std;
typedef long long ll;

int n, m;
int lvl[200100];
int dp[20][200100];
int par[200100];
ll cost[20][200100];
pair < ll , pair < int , int > > edge[200100];
ll sum;
vector < pair < int , ll > > adj[200100], adj2[200100];
priority_queue < pair < ll , pair < int , int > > > Q;

int findd(int x)
{
    if(par[x] == x) return x;
    return par[x] = findd(par[x]);
}

bool Is_Same(int x, int y)
{
    return findd(x) == findd(y);
}

void mergee(int x, int y)
{
    x = findd(x), y = findd(y);
    par[x] = par[y];
    return;
}

void DFS(int node)
{
    for(auto x : adj2[node]){
        if(x.F == dp[0][node]) continue;
        lvl[x.F] = lvl[node] + 1;
        dp[0][x.F] = node;
        cost[0][x.F] = x.S;
        DFS(x.F);
    }
}

void Build()
{
    for(int i = 1 ; i <= 18 ; i++){
        for(int j = 1 ; j <= n ; j++){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            cost[i][j] = max(cost[i - 1][j], cost[i - 1][dp[i - 1][j]]);
        }
    }
}

ll LCA(int x, int y)
{
    ll ans = 0;
    if(lvl[y] > lvl[x]){
        swap(x, y);
    }
    for(int i = 18 ; i >= 0 ; i--){
        if(lvl[dp[i][x]] >= lvl[y]){
            ans = max(ans, cost[i][x]);
            x = dp[i][x];
        }
    }
    if(x == y)
        return ans;
    for(int i = 18 ; i >= 0 ; i--){
        if(dp[i][x] != dp[i][y]){
            ans = max(ans, max(cost[i][x], cost[i][y]));
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return max(ans, max(cost[0][x], cost[0][y]));
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        par[i] = i;
    }
    int a, b;
    ll c;
    for(int i = 1 ; i <= m ; i++){
        scanf("%d%d", &a, &b);
        scanf("%lld", &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        Q.push({-c , {-a, -b}});
        edge[i] = {c, {a, b}};
    }
    pair < ll , pair < int , int > > u;
    while(!Q.empty()){
        u = Q.top();
        Q.pop();
        if(Is_Same(-u.S.F, -u.S.S)) continue;
        sum += -u.F;
        mergee(-u.S.F, -u.S.S);
        adj2[-u.S.F].push_back({-u.S.S, -u.F});
        adj2[-u.S.S].push_back({-u.S.F, -u.F});
    }
    lvl[1] = 1;
    DFS(1);
    Build();
    ll temp;
    for(int i = 1 ; i <= m ; i++){
        temp = (sum - LCA(edge[i].S.F, edge[i].S.S) + edge[i].F);
        printf("%lld\n", temp);
    }
    return 0;
}