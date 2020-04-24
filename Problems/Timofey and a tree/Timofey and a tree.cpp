#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define SF(x) scanf("%d",&x)
#define MEM(a,b) memset(a,b,sizeof(a))
#define DB(x) cout << #x << " is " << x << endl
#define popcount(x) __builtin_popcount(x)
#define ffs(x) __builtin_ffs(x) // This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
#define clz(x) __builtin_clz(x) // This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define ctz(x) __builtin_ctz(x) // This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.

using namespace std;
typedef long long ll;

ll INF = (1 << 60);

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

ll color[100100],n,u,v;
vector < ll > adj[100100];

pair < bool , pair < int , int > > DFS(int node, int par)
{
    bool Fi = false;
    int Se = color[node], Th = -1;
    for(auto cur : adj[node]){
        if(cur == par)
            continue;
        pair < bool , pair < int , int > > P = DFS(cur, node);
        if(P.F){
            return {true , {Se, P.S.S}};
        }
        if(P.S.F != Se){
            return {true ,{Se, node}};
        }
    }
    return {Fi, {Se, Th}};
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n - 1; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> color[i];
    }
    ll wrong = 0LL, last = 0;
    for(auto cur : adj[1]){
        pair < bool , pair < int , int > > P = DFS(cur, 1);
        if(P.F){
            wrong++;
            last = P.S.S;
        }
    }
    if(wrong > 1){
        cout << "NO\n";
        return 0;
    }
    if(wrong == 0){
        cout << "YES\n" << 1 << endl;
        return 0;
    }
    wrong = 0;
    for(auto cur : adj[last]){
        pair < bool , pair < int , int > > P = DFS(cur, last);
        if(P.F){
            wrong++;
        }
    }
    if(wrong >= 1){
        cout << "NO\n";
        return 0;
    }
    if(wrong == 0){
        cout << "YES\n" << last << endl;
        return 0;
    }
    return 0;
}