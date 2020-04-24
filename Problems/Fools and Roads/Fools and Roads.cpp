#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, k, fool1[100100], a, b;
ll fool2[100100];
vector < pair < ll , ll > > adj[100100];
ll dp[25][100100];
ll lvl[100100];
ll arr[100100];
ll ans[100100];


void pre_DFS(ll node, ll par)
{
    for(auto x : adj[node]){
        if(x.F == par) continue;
        lvl[x.F] = lvl[node] + 1;
        dp[0][x.F] = node;
        pre_DFS(x.F, node);
    }
}

void Build()
{
    ll x;
    for(ll i = 1 ; i <= 19 ; i++){
        for(ll j = 1 ; j <= n ; j++){
                x = dp[i - 1][j];
                dp[i][j] = dp[i - 1][x];
        }
    }
}

ll LCA(ll x, ll y)
{
    if(lvl[y] > lvl[x])
        swap(x, y);
    for(ll i = 19 ; i >= 0 ; i--){
        if(lvl[dp[i][x]] >= lvl[y]){
            x = dp[i][x];
        }
    }
    if(x == y){
        return x;
    }
    for(ll i = 19 ; i >= 0 ; i--){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}

ll DFS(ll node, ll par)
{
    ll temp = arr[node];
    for(auto x : adj[node]){
        if(x.F == par) continue;
        ll xx = DFS(x.F, node);
        ans[x.S] += xx;
        temp += xx;
    }
    return temp;
}

int main()
{
    cin >> n;
    for(ll i = 1 ; i <= n - 1 ; i++){
        scanf("%I64d %I64d", &a , &b);
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    cin >> k;
    for(ll i = 1 ; i <= k ; i++){
        scanf("%I64d %I64d", &fool1[i], &fool2[i]);
    }
    lvl[1] = 1;
    pre_DFS(1, -1);
    Build();
    for(ll i = 1 ; i <= k ; i++){
        arr[fool1[i]]++;
        arr[fool2[i]]++;
        arr[LCA(fool1[i], fool2[i])] -= 2;
    }
    DFS(1, -1);
    for(int i = 1  ; i <= n - 1 ; i++){
        printf("%I64d ", ans[i]);
    }
    return 0;
}