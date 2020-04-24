#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

int n, a[10001];
int dp[1001][20001][2], MOD = (1e9) + 7;

ll DP(int pos, int sum, bool ok)
{
    if(pos == n)
        return (sum == 10000 && ok);
    int &cur = dp[pos][sum][ok];
    if(cur != -1)
        return cur;
    cur = (sum == 10000 && ok);
    cur += DP(pos + 1, sum + a[pos], 1);
    cur %= MOD;
    cur += DP(pos + 1, sum - a[pos], 1);
    cur %= MOD;
    return cur;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    ll ans = 0LL;
    for(int i = 0 ; i < n ; i++){
        ans += DP(i, 10000, 0);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}