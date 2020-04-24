#include <iostream>
#include <string.h>

using namespace std;

int dp[5007][5007], n, m, INF = 5005, arr[5007];

int DP(int pos, int last_taken)
{
    if(pos == n)return 0;
    int &cur = dp[pos][last_taken];
    if(cur != -1)return cur;
    if(arr[pos] >= last_taken){
        cur = DP(pos + 1, arr[pos]) + 1;
    }
    cur = max(cur ,DP(pos + 1,  last_taken));
    return cur;
}

int main()
{

    double k;
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] >> k;
    }
    cout << n - DP(0, 0) << endl;
    return 0;
}