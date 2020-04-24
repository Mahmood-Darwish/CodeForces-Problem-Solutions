#include <iostream>
#include <string.h>

#define F first
#define S second

using namespace std;

int dp[605][305][305];
int a[305][305];
int n, MX = (1 << 30);
pair < int , int > d[] = {{0, 1}, {1, 0}, {1, 1}, {0, 0}};

bool cool(int time, int x1, int x2)
{
    int y1 = (time - x1) + 1;
    int y2 = (time - x2) + 1;
    if(x1 > n || x1 < 1 || x2 > n || x2 < 1 || y1 > n || y1 < 1 || y2 > n || y2 < 1) return false;
    return true;
}

int DP(int time, int x1, int x2)
{
    if(x1 == n && time == n + n - 1 && x2 == n){
        return a[n][n];
    }
    if(!cool(time, x1, x2)) return -MX;
    int &cur = dp[time][x1][x2];
    if (cur != -MX) return cur;
    int y1 = (time - x1) + 1;
    int y2 = (time - x2) + 1;
    for(int i = 0 ; i < 4 ; i++){
        if(x1 == x2) cur = max(cur, DP(time + 1, x1 + d[i].F, d[i].S + x2) + a[x1][y1]);
        else cur = max(cur, DP(time + 1, x1 + d[i].F, d[i].S + x2) + a[x1][y1] + a[x2][y2]);
    }
    return cur;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i <= 600; i++){
        for(int j = 0 ; j <= 300 ; j++){
            for(int k = 0 ; k <= 300 ; k++){
                dp[i][j][k] = -MX;
            }
        }
    }
    cout << DP(1, 1, 1) << endl;
    return 0;
}