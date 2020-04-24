#include <iostream>
#include <string.h>

using namespace std;

int MOD = 1000000007;
long long dp[1000007][6] , n;
string s;

long long DP(int pos , int c)
{
    if(pos == n)return (c != 2 && c != 1);
    long long &cur = dp[pos][c];
    if(cur != -1)return cur;
    cur = 0;
    if(c == 0)
    {
        if(s[pos] == '0')
            cur += DP(pos + 1 , 0);
        if(s[pos] == '1')
            cur += DP(pos + 1 , 1);
        if(s[pos] == '?')
            cur += DP(pos + 1 , 0) + DP(pos + 1 , 1);
    }
    if(c == 1)
    {
        if(s[pos] == '*')
            cur += DP(pos + 1 , 3);
        if(s[pos] == '?')
            cur += DP(pos + 1 , 3);
    }
    if(c == 2)
    {
        if(s[pos] == '*')
            cur += DP(pos + 1 , 3);
        if(s[pos] == '?')
            cur += DP(pos + 1 , 3);
    }
    if(c == 3)
    {
        if(s[pos] == '*')
            cur += DP(pos + 1 , 3);
        if(s[pos] == '1')
            cur += DP(pos + 1 , 4);
        if(s[pos] == '2')
            cur += DP(pos + 1 , 2);
        if(s[pos] == '?')
            cur += ((DP(pos + 1 , 3) + DP(pos + 1 , 4)) % MOD + DP(pos + 1 , 2)) % MOD;
    }
    if(c == 4)
    {
        if(s[pos] == '0')
            cur += DP(pos + 1 , 0);
        if(s[pos] == '1')
            cur += DP(pos + 1 , 1);
        if(s[pos] == '?')
            cur += DP(pos + 1 , 0) + DP(pos + 1 , 1);
    }
    return cur % MOD;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> s;
    n = s.size();
    if(s[n-1] == '2' || s[0] == '2')
    {
        cout << 0;
        return 0;
    }
    long long ans = 0;
    if(s[0] == '0')
        ans = DP(1 , 0);
    if(s[0] == '1')
        ans = DP(1 , 1);
    if(s[0] == '*')
        ans = DP(1 , 3);
    if(s[0] == '?')
        ans = (((DP(1 , 1) + DP(1 , 0)) % MOD) + DP(1 , 3)) % MOD;
    cout << ans;
    return 0;
}