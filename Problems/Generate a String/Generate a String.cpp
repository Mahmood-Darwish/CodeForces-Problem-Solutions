#include <iostream>

using namespace std;

long long dp[10000000] , x , y , n;

int main()
{
    cin >> n >> x >> y;
    dp[1] = x;
    for(int i = 2 ; i <= n ; i++)
        dp[i] = 99999999999999999;
    for(int i = 2 ; i <= n ; i++)
    {
        dp[i] = min(dp[i-1] + x,dp[i]);
        if(i%2)
            dp[i] = min(dp[(i/2) + 1] + y + x,dp[i]);
        else
            dp[i] = min(dp[i/2] + y,dp[i]);
    }
    cout << dp[n];
    return 0;
}