#include <iostream>
#include <string.h>

using namespace std;

int n, m, mod, arr[501], ones, zeros;
long long dp[2][501][501];
string s;

int main()
{
    cin >> n >> m >> mod;
    for(int i = 0 ; i < m ; i++){
        cin >> s;
        for(int j = 0 ; j < n ; j++){
            arr[j] += (s[j] == '1');
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 1){
            ones++;
        }
        if(arr[i] == 0){
            zeros++;
        }
    }
    dp[0][zeros][ones] = dp[1][zeros][ones] = 1;
    int cur = 0;
    for(int i = m + 1 ; i <= n ; i++){
        cur = 1 - cur;
        for(int j = 0 ; j <= min(n, (n - i + 1) * 2) ; j++){
            for(int k = 0 ; k <= min(n, (n + 1 - i) * 2) ; k++){
                if(j + k > n)
                    break;
                if(dp[cur][j][k] == 0)
                    continue;
                if(j - 2 >= 0 && k + 2 <= 500){
                    dp[1 - cur][j - 2][k + 2] += ((dp[cur][j][k] % mod) * (((j * (j - 1)) / 2) % mod)) % mod;
                }
                if(j - 1 >= 0){
                    dp[1 - cur][j - 1][k] += ((dp[cur][j][k] % mod) * ((j * k) % mod)) % mod;
                }
                if(k - 2 >= 0){
                    dp[1 - cur][j][k - 2] += ((dp[cur][j][k] % mod) * (((k * (k - 1)) / 2) % mod)) % mod;
                }
                dp[cur][j][k] = 0;
            }
        }
    }
    cout << dp[1 - cur][0][0] << endl;
    return 0;
}