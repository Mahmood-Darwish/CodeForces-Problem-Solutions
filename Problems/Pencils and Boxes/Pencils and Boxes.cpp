#include <iostream>
#include <algorithm>
#include <stdio.h>

typedef long long ll;
using namespace std;

int a[500100], pre[5000500];
int n, d, k;
int dp[500100];

int main()
{
    cin >> n >> k >> d;
    if(k == 1) {cout << "YES" << endl; return 0;}
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    dp[1] = 1;
    pre[1] = 0;
    int l = 1;
    for(int i = 1 ; i <= n; i++){
        while(a[i] - a[l] > d) l++;
        if((i - k) + 1 >= l && a[i] - a[l] <= d && pre[(i - k) + 2] - pre[l] >= 1)
            dp[i + 1] = 1;
        else dp[i + 1] = 0;
        pre[i + 1] = dp[i] + pre[i];
    }
    if(dp[n + 1]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}