#include <bits/stdc++.h>
#define SF(x) scanf("%I64d",&x)
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

ll INF = (1 << 29);

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
/*
void Sieve_Of_Eratosthenes(int n)
{
    MEM(PRIME, 1);
    for (int p = 2; p * p <= n ; p++)
    {
        if (PRIME[p])
        {
            for (int i = p + p ; i <= n ; i += p)
                PRIME[i] = false;
        }
    }
    return;
}
*/

bool vis[100100];
ll sum, n, x, y, m, val[100100];
vector < ll > adj[100100];

ll DFS(int node, int par)
{
    ll q = val[node];
    vis[node] = true;
    for(int i = 0 ; i < adj[node].size() ; i++){
        if(adj[node][i] != par && !vis[adj[node][i]])
            q = min(q, DFS(adj[node][i], node));
    }
    return q;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        SF(val[i]);
    }
    while(m--){
        SF(x);
        SF(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            sum += DFS(i, -1);
        }
    }
    cout << sum << endl;
    return 0;
}