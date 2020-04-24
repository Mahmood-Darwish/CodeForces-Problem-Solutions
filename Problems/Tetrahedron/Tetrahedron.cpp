#include <iostream>
#include <string.h>

using namespace std;

int dp[5][10000001], n, MOD = 1e9 + 7;

int main()
{
    cin >> n;
    dp[1][n] = 1;
    for(int i = n ; i >= 0 ; i--){
        for(int j = 1 ; j <= 4 ; j++){
            if(j != 1){
                dp[j][i] += dp[1][i + 1];
                dp[j][i] %= MOD;
            }
            if(j != 2){
                dp[j][i] += dp[2][i + 1];
                dp[j][i] %= MOD;
            }
            if(j != 3){
                dp[j][i] += dp[3][i + 1];
                dp[j][i] %= MOD;
            }
            if(j != 4){
                dp[j][i] += dp[4][i + 1];
                dp[j][i] %= MOD;
            }
        }
    }
    cout << dp[1][0] << endl;
    return 0;
}