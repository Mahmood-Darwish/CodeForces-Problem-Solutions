#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[5000][5000];
ll n, MX = (1LL << 60);
ll t[2010];
ll c[2010];


ll DP(int pos, int taken)
{
    if(pos > n){
        if(taken < n) return MX;
        return 0;
    }
    ll &cur = dp[pos][taken];
    if(cur != -1) return cur;
    if(taken >= n) return cur = 0;
    cur = min(DP(pos + 1, taken), DP(pos + 1, taken + t[pos]) + c[pos]);
    return cur;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ;i++){
        cin >> t[i] >> c[i];
        t[i]++;
    }
    memset(dp, -1, sizeof(dp));
    cout << DP(1, 0) << endl;
    return 0;
}