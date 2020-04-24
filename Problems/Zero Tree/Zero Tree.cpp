#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n, a, b, INF = (1 << 63), ans;
ll val[200100];
vector < ll > adj[200100];
ll mn[200100], mx[200100];

void DFS(ll node, ll par)
{
    for(auto x : adj[node]){
        if(par == x) continue;
        DFS(x, node);
        mx[node] = max(mx[node], mx[x]);
        mn[node] = max(mn[node], mn[x]);
    }
    val[node] += mx[node];
    val[node] -= mn[node];
    //cout << node << ' '  << val[node]  << ' ' << mx[node] << ' ' << mn[node] << ' ' << ans << endl;
    if(val[node] > 0){
        mn[node] += val[node];
    }
    else{
        mx[node] += -val[node];
    }
    //cout << node << ' '  << val[node]  << ' ' << mx[node] << ' ' << mn[node] << ' ' << ans << endl;
    return;
}

int main()
{
    cin >> n;
    for(ll i = 1 ; i < n ; i++){
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);adj[b].push_back(a);
    }
    for(ll i = 1 ; i <= n ; i++){
        scanf("%lld", &val[i]);
    }
    DFS(1, -1);
    cout << mx[1] + mn[1] << endl;
    return 0;
}
/*
5

2 3

4 5

2 5

1 3

0 2 1 4 3
*/