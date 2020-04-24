#include <iostream>
#include <string.h>

using namespace std;

long long n , k , dp[2016][2016] , MOD = 1e9 + 7;

long long DP(int pos , int last)
{
    if(last>n)return 0;
    if(pos > k)return 0;
    if(pos == k)return 1;
    long long &cur = dp[pos][last];
    if(dp[pos][last] != -1)return cur;
    cur = 0;
    for(int i = 1 ; i * last <= n ; i++)
    {
         cur += DP(pos + 1 , i * last);
         cur%=MOD;
    }
    return cur % MOD;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    cout << DP(0,1);
    return 0;
}