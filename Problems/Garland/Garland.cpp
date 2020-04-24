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

ll INF = (1 << 29);

ll a[1000100];
ll arr[1000100];
vector < ll > adj[1000100], V;
ll sum ,n;

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

int DFS(int node, int par = 0)
{
    arr[node] = a[node];
    for(auto cur : adj[node]){
        if(par != cur){
            arr[node] += DFS(cur, node);
        }
    }
    if((sum / 3) == arr[node]){
        V.pb(node);
        return 0;
    }
    return arr[node];
}

int main()
{
    ll u , v, start;
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        scanf("%I64d %I64d", &u, &v);
        if(u == 0){
            start = i;
        }
        a[i] = v;
        adj[i].pb(u);
        adj[u].pb(i);
        sum += v;
    }
    if(sum % 3 != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    DFS(start);
    if(V.size() < 3){
        cout << -1 << endl;
        return 0;
    }
    int t = 0;
    for(auto cur : V){
        if(cur != start){
            cout << cur << ' ';
            t++;
        }
        if(t == 2)
            break;
    }
    return 0;
}