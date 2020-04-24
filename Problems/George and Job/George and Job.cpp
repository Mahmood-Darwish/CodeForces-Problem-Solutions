#include <iostream>
#include <string.h>

using namespace std;

long long dp[5010][5010];
int a[6000] , k , m , n;

long long DP(int pos , int how_much)
{
    if(pos >= n || how_much <= 0)return 0;
    long long &cur = dp[pos][how_much];
    if(cur != -1)return cur;
    cur = DP(pos+1,how_much);
    long long sum = 0;
    for(int i = pos , temp = 0 ; i < n && temp < m ; i++ , temp++)
        sum += a[i];
    cur = max(cur,DP(pos+m,how_much-1) + sum);
    return cur;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << DP(0,k) << '\n';
    return 0;
}