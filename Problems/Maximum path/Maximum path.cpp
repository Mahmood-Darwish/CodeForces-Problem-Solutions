#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[17][100007][17], a[17][100007], n, INF = 1e17;

bool check(int x, int y)
{
    if(x > 3 || x <= 0 || y <= 0 || y > n)
        return false;
    return true;
}

ll DP(int x, int y, int cur_col)
{
    if(!check(x, y))
        return -INF;
    if(x == 3 && y == n)
        return a[x][y];
    ll &cur = dp[x][y][cur_col];
    if(cur != -1)
        return cur;
    cur = DP(x, y + 1, 0) + a[x][y];
    if(x == 1){
        if(!(cur_col & 2)){
            cur = max(cur, DP(2, y, cur_col | 1) + a[x][y]);
        }
    }
    if(x == 2){
        if(!(cur_col & 1)){
            cur = max(cur, DP(1, y, cur_col | 2) + a[x][y]);
        }
        if(!(cur_col & 4)){
            cur = max(cur, DP(3, y, cur_col | 2) + a[x][y]);
        }
    }
    if(x == 3){
        if(!(cur_col & 2)){
            cur = max(cur, DP(2, y, cur_col | 4) + a[x][y]);
        }
    }
    ll temp = -INF;
    if(y < n && !cur_col){
        if(x == 1){
            temp = a[1][y] + a[2][y] + a[3][y] + a[1][y + 1] + a[2][y + 1] + DP(3 , y + 1, 3);
        }
        if(x == 3){
            temp = a[1][y] + a[2][y] + a[3][y] + a[3][y + 1] + a[2][y + 1] + DP(1 , y + 1, 6);
        }
    }
    cur = max(temp, cur);
    return cur;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= 3 ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << DP(1, 1, 0) << endl;
    return 0;
}