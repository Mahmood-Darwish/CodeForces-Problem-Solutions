#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int n, time[100001], dp[100001];

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        scanf("%d", &time[i]);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        dp[i] = dp[i - 1] + 20;
        for(int j = i - 1 ; j >= 0 ; j--){
            if(time[i] - time[j] < 90)
                dp[i] = min(dp[i], dp[j-1] + 50);
            else break;
        }
        for(int j = i - 1 ; j >= 0 ; j--){
            if(time[i] - time[j] < 1440){
                dp[i] = min(dp[i], dp[j-1] + 120);
            }
            else break;
        }
    }
    int temp = 0;
    for(int i = 1 ; i <= n ; i++){
        //cout << dp[i] << endl;
        printf("%d\n", max(0, dp[i] - temp));
        temp += max(0, dp[i] - temp);
    }
    return 0;
}