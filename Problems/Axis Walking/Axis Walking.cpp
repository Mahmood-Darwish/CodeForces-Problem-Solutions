#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

long long dp[(1 << 24)], arr[24], MOD = (1e9) + 7, n, k, V[2], sum[(1 << 24)];

int main()
{
    scanf("%I64d", &n);
    for(int i = 0 ; i < n ; i++)
        scanf("%I64d", &arr[i]);
    scanf("%I64d", &k);
    V[0] = V[1] = -1;
    for(int i = 0 ; i < k ; i++)
        scanf("%I64d", &V[i]);
    int temp;
    for(int i = 1 ; i < (1 << n) ; i++){
        temp = __builtin_ctz(i);
        sum[i] = sum[i ^ (1 << temp)] + arr[temp];
        if(sum[i] == V[0] || sum[i] == V[1])
            dp[i] = -1;
    }
    dp[0] = 1;
    for(int i = 0 ; i < (1 << n) ; i++){
        if (dp[i] == -1) {
            dp[i] = 0;
        }
        else {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    dp[i] += dp[i ^ (1 << j)];
                }
            }
            dp[i] %= MOD;
        }
    }
    printf("%I64d\n",dp[((1 << n) - 1)]);
    return 0;
}