#include <iostream>
#include <string.h>
#include <vector>

#define F first
#define S second
#define pb push_back

using namespace std;
typedef long long ll;

ll dp[300100];
ll n, MX = (1LL << 60);
ll w[300100];
ll dp2[300100];
vector < pair < ll , ll > > adj[300100];

ll DP1(int pos, int par)
{
    if(dp[pos] != -MX) return dp[pos];
    ll &cur = dp[pos];
    cur = w[pos];
    for(unsigned int i = 0 ; i < adj[pos].size() ; i++){
        pair < ll , ll > u = adj[pos][i];
        if(u.F == par) continue;
        cur = max(cur, DP1(u.F, pos) - u.S + w[pos]);
    }
    return cur;
}

ll DP2(int pos, int par)
{
    ll &cur = dp2[pos];
    if(cur != -MX) return cur;
    cur = w[pos];
    ll mx1 = -MX, mx2 = -MX;
    for(unsigned int i = 0 ; i < adj[pos].size() ; i++){
        pair < ll , ll > u = adj[pos][i];
        if(u.F == par) continue;
        cur = max(cur, DP1(u.F, pos) - u.S + w[pos]);
        if(DP1(u.F, pos) - u.S >= mx1){mx2 = mx1, mx1 = DP1(u.F, pos) - u.S;}
        else if(DP1(u.F, pos) - u.S >= mx2) {mx2 = DP1(u.F, pos) - u.S;}
        DP2(u.F, pos);
    }
    cur = max(cur, mx1 + mx2 + w[pos]);
    return cur;
}

int main()
{
    ll x, y, z;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> w[i];
    for(int i = 1 ; i < n ; i++) {
        cin >> x >> y >> z;
        adj[x].pb({y, z});
        adj[y].pb({x, z});
    }
    for(int i = 1 ; i <= n ; i++) dp[i] = -MX, dp2[i] = -MX;
    DP1(1, -1);
    DP2(1, -1);
    ll ans = -MX;
    for(int i = 1 ; i <= n ; i++){
        ans = max(ans, DP2(i, -1));
    }
    cout << ans << endl;
    return 0;
}