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

ll INF = (1LL << 29LL);

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

int n, m;
bool vis1[500500];
bool vis2[500500];
int ans[500500];
vector < int > adj[500500];

int DFS1(int node, int par)
{
    vis1[node] = true;
    int sum = 1;
    for(int i = 0 ; i < adj[node].size() ; i++){
        int u = adj[node][i];
        if(u == par) continue;
        if(vis1[u]) continue;
        sum += DFS1(u, node);
    }
    return sum;
}

int DFS2(int node, int par, int sum)
{
    vis2[node] = true;
    ans[node] = sum;
    for(int i = 0 ; i < adj[node].size() ; i++){
        int u = adj[node][i];
        if(u == par) continue;
        if(vis2[u]) continue;
        DFS2(u, node, sum);
    }
}

int b[500500];

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k ; j++){
            cin >> b[j];
            if(j > 1){
                adj[b[j]].pb(b[j - 1]);
                adj[b[j - 1]].pb(b[j]);
            }
        }
    }
    for(int i = 1; i <= n ; i++){
        if(!vis1[i]){
            int sum = DFS1(i, -1);
            DFS2(i, -1, sum);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}