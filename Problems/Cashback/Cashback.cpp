#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[100100];
ll table[32][100100];
ll a[100100];
ll b[100100];
ll n, c, INF = 1e15;

void Build()
{
    for(ll i = 0 ; i < 32 ; i++){
        for(ll j = 0 ; j <= 100099 ; j++){
            table[i][j] = INF;
        }
    }
    for(ll i = 1 ; i <= n ; i++){
        table[0][i] = a[i];
    }
    for(ll k = 1 ; (1 << k) <= n ; k++){
        for(ll i = 1 ; i <= n ; i++){
            //cout << k << ' ' << i << endl;
            table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
        }
    }
}

ll Q(ll l, ll r)
{
    //cout << l << ' ' << r << endl;
    ll ans = INF;
    for(ll k = 20 ; k >= 0 ; k--){
        if((l + (1 << k) - 1)<= r){
            //cout << k << ' ' << l << endl;
            //cout << table[k][l] << endl;
            ans = min(ans, table[k][l]);
            l += (1 << k);
        }
    }
    //cout << ans << endl;
    return ans;
}

ll DP(ll pos)
{
    if(pos > n) return 0;
    ll &cur = dp[pos];
    if(cur != -1) return cur;
    cur = DP(pos + 1) + a[pos];
    if(pos + c <= n + 1)
        cur = min(cur, DP(pos + c) + b[(pos + c) - 1] - b[pos - 1] - Q(pos, pos + c - 1));
    return cur;
}

int main()
{
    cin >> n >> c;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    b[1] = a[1];
    for(ll i = 2 ; i <= n ; i++){
        b[i] = a[i] + b[i - 1];
    }
    memset(table, -1, sizeof(table));
    memset(dp, -1 ,sizeof(dp));
    Build();
    cout << DP(1) << endl;
    return 0;
}