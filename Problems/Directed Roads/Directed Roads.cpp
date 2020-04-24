#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#define pb push_back
using namespace std;
typedef long long ll;
vector < int > adj1[300100], V;
short vis[300100];
long long n, com, MOD = (1e9) + 7;

ll POW(ll x , ll y){
    if(y == 0) return 1;
    if(y == 1) return x;
    ll ans = POW(x , y / 2) % MOD;
    ans *= ans;
    ans %= MOD;
    if(y % 2 == 0) return ans;
    return (ans * x) % MOD;
}

void Cycle(int node, int dis)
{
    if(vis[node] == 2 || vis[node] == 3){
        V.pb(dis);
        return;
    }
    vis[node] = 3;
    for(auto Cur : adj1[node])
        Cycle(Cur, dis + 1);
    return;
}
void DFS(int node)
{
    if(vis[node] == 2 || vis[node] == 3)
        return;
    if(vis[node] == 1){
        Cycle(node, 0);
        return;
    }
    vis[node] = 1;
    for(auto Cur : adj1[node])
        DFS(Cur);
    vis[node] = 2;
    return;
}
void scc()
{
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i])
            DFS(i);
    }
    return;
}
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> com;
        adj1[i].pb(com);
    }
    scc();
    com = V.size();
    ll ans = 1LL;
    for(int i = 0 ; i < com ; i++){
        if(V[i] == 1) { continue; }
        ll temp = (POW(2, V[i]) - 2) % MOD;
        ans *= temp;
        ans %= MOD;
        n -= V[i];
    }
    ans = max(1LL, ans);
    ans *= POW(2, n);
    ans %= MOD;
    cout << ans << endl;
    return 0;
}