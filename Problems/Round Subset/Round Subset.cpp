#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;


ll dp[2][205][205 * 27 + 3], n, k;
ll a[203];
ll b[203][4];

int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        ll x = a[i];
        while(x % 2 == 0){
            b[i][0]++;
            x /= 2;
        }
        x = a[i];
        while(x % 5 == 0){
            b[i][1]++;
            x /= 5;
        }
    }
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j <= k ; j++){
            for(int t = 0 ; t <= 205 * 27 ; t++){
                dp[i][j][t] = -(1 << 30);
            }
        }
    }
    dp[0][0][0] = 0;
    int cur = 0;
    for(int i = 0; i < n ; i++){
        cur = 1 - cur;
        for(int j = 0; j <= k ; j++){
            for(int t = 0 ; t <= 205 * 27; t++){
                dp[cur][j][t] = max(dp[cur][j][t], dp[1 - cur][j][t]);
                if(j > 0 && b[i][1] <= t)
                    dp[cur][j][t] = max(dp[cur][j][t], dp[1 - cur][j - 1][t - b[i][1]] + b[i][0]);
            }
        }
    }
    ll ans = 0;
    for(ll i = 0 ; i <= 203 * 27 ; i++){
        ans = max(ans, min(i, dp[cur][k][i]));
    }
    cout << ans << endl;
    return 0;
}