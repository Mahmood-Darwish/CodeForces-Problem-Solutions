#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>

#define F first
#define S second
#define SF(x) scanf("%d",&x)

using namespace std;
typedef long long ll;

int n, dp[(1 << 25)], MX = (1 << 26), dis[26][26];
pair < int , int > arr[26];

int DP(int mask)
{
    if(mask == 0)return 0;
    int &cur = dp[mask];
    if(cur != -1)return cur;
    cur = DP(mask & ~(1 << (__builtin_ffs(mask) - 1))) + (dis[0][__builtin_ffs(mask)] * 2);
    for(int i = 0; i < n ; i++)
    {
        if(i != (__builtin_ffs(mask) - 1) && (1 & (mask >> i))){
            cur = min(cur, DP((mask & ~(1 << i)) & ~(1 << (__builtin_ffs(mask) - 1))) + dis[0][__builtin_ffs(mask)] + dis[__builtin_ffs(mask)][i + 1] + dis[i + 1][0]);
        }
    }
    return cur;
}

void find_sol(int mask, int ans)
{
    if(mask == 0)return;
    if(DP(mask & ~(1 << (__builtin_ffs(mask) - 1))) + (dis[0][__builtin_ffs(mask)] * 2) == ans){
        cout << __builtin_ffs(mask) << ' ' << 0 << ' ';
        find_sol(mask & ~(1 << (__builtin_ffs(mask) - 1)), ans - (dis[0][__builtin_ffs(mask)] * 2));
        return;
    }
    for(int i = 0; i < n ; i++)
    {
        if(i != (__builtin_ffs(mask) - 1) && (1 & (mask >> i))){
            if(ans == DP((mask & ~(1 << i)) & ~(1 << (__builtin_ffs(mask) - 1))) + dis[0][__builtin_ffs(mask)] + dis[__builtin_ffs(mask)][i + 1] + dis[i + 1][0]){
                cout << __builtin_ffs(mask) << ' ' << i + 1 << ' ' << 0 << ' ';
                find_sol((mask & ~(1 << i)) & ~(1 << (__builtin_ffs(mask) - 1)), ans - (dis[0][__builtin_ffs(mask)] + dis[__builtin_ffs(mask)][i + 1] + dis[i + 1][0]));
                return;
            }
        }
    }
    return;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    SF(arr[0].F);SF(arr[0].S);
    SF(n);
    for(int i = 1 ; i <= n ; i++){
        SF(arr[i].F);SF(arr[i].S);
    }
    for(int i = 0; i <= n ; i++)
        for(int j = i ; j <= n ; j++)
            dis[i][j] = dis[j][i] = ((arr[i].F - arr[j].F) * (arr[i].F - arr[j].F)) + ((arr[i].S - arr[j].S) * (arr[i].S - arr[j].S));
    printf("%d\n",DP((1 << n) - 1));
    printf("0 ");
    find_sol((1 << n) - 1, DP((1 << n) - 1));
    return 0;
}