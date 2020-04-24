#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll n , l , a[205][5] , dp[3005][105][105];
ll MOD = 1000000007;

ll DP(ll len , ll type , ll sizee)
{
    if(len > l)return 0;
    if(len == l)return 1;
    long long &cur = dp[len][type][sizee];
    if(cur != -1)return cur;
    cur = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(type != i)
        {
            if(a[i][0] == sizee)
            {
                cur += DP(len + a[i][0] , i , a[i][1]);
                cur %= MOD;
            }
            if(a[i][0] == a[i][1])continue;
            if(a[i][1] == sizee)
            {
                cur += DP(len + a[i][1] , i , a[i][0]);
                cur %= MOD;
            }
        }
    }
    return cur % MOD;
}


int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> l;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i][0] >> a[i][1];
    ll ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ans += DP(a[i][0] , i , a[i][1]);
        ans %= MOD;
        if(a[i][0] == a[i][1])continue;
        ans += DP(a[i][1] , i , a[i][0]);
        ans %= MOD;
    }
    ans %= MOD;
    cout << ans % MOD;
    return 0;
}