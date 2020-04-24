#include <iostream>
#include <string.h>

using namespace std;

long long n, x, dp[(1 << 18)][101];
string s;

long long DP(int mask ,int mod)
{
    //cout << mask << ' ' << mod << endl;
    if(__builtin_popcount(mask) == n)
        return !mod;
    long long &cur = dp[mask][mod];
    if(cur != -1)
        return cur;
    cur = 0;
    long long temp = 0LL;
    for(int i = 0 ; i < n ; i++){
        if(!(mask & (1 << i)) && !(temp & (1 << (s[i] - '0')))){
            int num = s[i] - '0';
            temp |= (1 << num);
            cur += DP(mask | (1 << i), ((mod * 10) + num) % x);
        }
    }
    return cur;
}

int main()
{
    cin >> s >> x;
    n = s.size();
    memset(dp, -1,sizeof(dp));
    long long ans = 0;
    long long temp = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] - '0' != 0 && !(temp & (1 << (s[i] - '0')))){
            ans += DP((1 << i), (s[i] - '0') % x);
            temp |= (1 << (s[i] - '0'));
        }
    }
    cout << ans << endl;
    return 0;
}