#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[2016][2016] , a[2016] , MOD = 1e9 + 7 , n , h;

ll DP(int pos , int open)
{
    if(open < 0)return 0;
    if(pos == n)return (open == 0);
    ll &cur = dp[pos][open];
    if(cur != -1)
        return cur;
    cur = 0;
    if(a[pos] + open == h)
        cur += DP(pos + 1 , open) + (DP(pos + 1, open - 1) * open);
    else if(a[pos] + open + 1 == h)
        cur += DP(pos + 1 , open + 1) + (DP(pos + 1 , open) * (open + 1));
    return cur % MOD;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> h;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    cout << DP(0,0);
    return 0;
}