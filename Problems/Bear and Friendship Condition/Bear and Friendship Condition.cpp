#include <bits/stdc++.h>
#define SF(x) scanf("%d",&x)
#define F first
#define S second
#define MEM(a,b) memset(a,b,sizeof(a))
#define DB(x) cout << #x << " is " << x << endl
#define ffs(x) __builtin_ffs(x) // This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
#define clz(x) __builtin_clz(x) // This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define ctz(x) __builtin_ctz(x) // This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define popcount(x) __builtin_popcount(x) // This function returns number of active bits in the binary represintation of the number
#define pb push_back

using namespace std;
typedef long long ll;

ll Mypow(ll X,ll Y){
    if(Y < 0)return 0;
    if(Y == 0)return 1;
    if(Y == 1){
        return X;
    }
    else{
        ll x = Mypow(X ,Y / 2);
        x *= x;
        if(Y % 2)
            return (x * X);
        else
            return x;
    }
}

int n, m, a, b;
vector < int > adj[150100];
int degree[150100];
vector < int > V[150100];
bool vis[150100];


void DFS(int node, int color)
{
    if(vis[node])
        return;
    vis[node] = true;
    V[color].pb(node);
    for(int i = 0 ; i < adj[node].size() ; i++){
        DFS(adj[node][i], color);
    }
    return;
}

int main()
{
    cin >> n >> m;
    int u, v;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        degree[u]++;
        degree[v]++;
    }
    int col = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            DFS(i, col++);
        }
    }
    for(int i = 0 ; i < col ; i++){
        ll have = 0;
        for(int j = 0 ; j < V[i].size() ; j++){
            have += degree[V[i][j]];
        }
        have /= 2;
        ll need = V[i].size();
        if(have < (need * (need - 1)) / 2){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}