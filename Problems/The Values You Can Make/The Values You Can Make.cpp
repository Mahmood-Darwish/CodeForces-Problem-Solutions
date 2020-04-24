#include <bits/stdc++.h>

using namespace std;

int n, k;
bool dp[501][501][501];
int a[501];
set < int > sol;

void DP(int pos, int sum, int subset)
{
    if(sum == k)
        sol.insert(subset);
    if(pos >= n || sum > k)
        return;
    if(dp[pos][sum][subset])
        return;
    dp[pos][sum][subset] = true;
    DP(pos + 1, sum + a[pos], subset);
    DP(pos + 1, sum + a[pos], subset + a[pos]);
    DP(pos + 1, sum, subset);
    return;
}

int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    DP(0, 0, 0);
    cout << sol.size() << endl;
    for(auto it = sol.begin() ; it != sol.end() ; it++){
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}