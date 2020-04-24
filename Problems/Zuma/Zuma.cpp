#include <iostream>
#include <string.h>

using namespace std;

int dp[501][501], a[501], n;

int DP(int i, int j)
{
    if(i > j)
        return 0;
    if(i == j)
        return 1;
    int &cur = dp[i][j];
    if(cur != -1)
        return cur;
    cur = DP(i + 1, j) + 1;
    if(a[i] == a[i + 1])
        cur = min(cur, DP(i + 2, j) + 1);
    for(int pos1 = i + 2 ; pos1 <= j ; pos1++){
        if(a[pos1] == a[i]){
            cur = min(cur, DP(i + 1, pos1 - 1) + DP(pos1 + 1, j));
        }
    }
    return cur;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    memset(dp, -1,sizeof(dp));
    cout << DP(0, n - 1) << endl;
    return 0;
}