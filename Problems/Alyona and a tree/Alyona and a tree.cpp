#include <iostream>
#include <vector>
#include <string.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, val[200100];
vector < pair < ll , ll > > adj[200100];
ll ans[200100];
ll dp[30][200100];
ll dis[200100];
ll lvl[200100];
ll temp_arr[200100];

void DFS(ll node, ll dist, ll par = -1)
{
    for(auto cur: adj[node]){
        if(cur.F == par) continue;
        lvl[cur.F] = lvl[node] + 1;
        dp[0][cur.F] = node;
        dis[cur.F] = dist + cur.S;
        DFS(cur.F, dist + cur.S, node);
    }
    return;
}

void Build()
{
    ll x;
    for(int i = 1 ; i < 21 ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(dp[i - 1][j] == -1) continue;
            x = dp[i - 1][j];
            if(dp[i - 1][x] == -1) continue;
            x = dp[i - 1][x];
            dp[i][j] = x;
        }
    }
    return;
}

void calc(ll node)
{
    ll temp = node;
    for(int i = 20 ; i >= 0 ; i--){
        if(dp[i][node] == -1) continue;
        if(dis[temp] - dis[dp[i][node]] <= val[temp]){
            node = dp[i][node];
        }
    }
    temp_arr[temp]++;
    temp_arr[node]--;
    return;
}

ll Second_DFS(ll node, ll par, ll temp)
{
    ll x = temp;
    for(int i = 0 ; i < adj[node].size() ; i++){
        if(adj[node][i].first == par) continue;
        temp += Second_DFS(adj[node][i].first, node, x);
    }
    ans[node] += temp;
    temp += temp_arr[node];
    return temp;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%I64d", &val[i]);
    }
    ll a, b;
    for(int i = 2 ; i <= n ; i++){
        scanf("%I64d %I64d", &a, &b);
        adj[i].push_back({a, b});
        adj[a].push_back({i, b});
    }
    lvl[1] = 1;
    DFS(1, 0);
    Build();
    for(int i = 1 ; i <= n ; i++){
        calc(i);
    }
    Second_DFS(1, -1, 0);
    for(int i = 1 ; i <= n ; i++){
        printf("%I64d ", ans[i]);
    }
    cout << endl;
    return 0;
}