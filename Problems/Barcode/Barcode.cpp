#include <iostream>
#include <string.h>

using namespace std;

long long dp[1007][5][1007];
long long turn[1007][5];
char a[1007][1007];
long long x , y , n , m;

long long DP(int pos , int type , int how_much)
{
    if(pos > m + 1 || how_much > y)return 9999999999;
    if(pos == m + 1 && how_much >= x && how_much <= y){return 0;}
    long long &ret = dp[pos][type][how_much];
    if(ret != -1)return ret;
    ret = DP(pos + 1, type , how_much + 1) + turn[pos][1 - type];
    if(how_much >= x && how_much <= y)
        ret = min(ret , DP(pos + 1 , 1 - type , 1) + turn[pos][type]);
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= n ; i++)
        for(int j = 1; j <= m ; j++)
            cin >> a[i][j];
    for(int i = 1 ; i <= m ; i++)
    {
        int temp1 = 0;
        int temp2 = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(a[j][i] == '.')temp1++;
            else temp2++;
        }
        turn[i][0] = temp1;
        turn[i][1] = temp2;
    }
    cout << min(DP(1,0,0),DP(1,1,0));
    return 0;
}