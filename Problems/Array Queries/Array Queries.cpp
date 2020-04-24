#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>

#define SF(x) scanf("%d", &x)

using namespace std;

int n, Q, a[100100], p, k;
int dp[100100][333];

int DP(int pos, int temp)
{
    if(pos > n)
        return 0;
    int &cur = dp[pos][temp];
    if(cur != -1){
        return cur;
    }
    return cur = DP(pos + a[pos] + temp, temp) + 1;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        SF(a[i]);
    }
    SF(Q);
    while(Q--){
        SF(p);
        SF(k);
        if(k <= sqrt(n)){
            printf("%d\n", DP(p, k));
        }
        else{
            int sum = 0;
            while(p <= n){
                p = p + a[p] + k;
                sum++;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}