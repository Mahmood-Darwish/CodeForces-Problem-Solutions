#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int dp1[510][510];
int dp[510][510];
string a[502];
vector < int > V;
int n, m, k, MX = (1 << 30);

int DP(int pos, int leftt)
{
    if(pos > n) return 0;
    int &cur = dp[pos][leftt];
    if(cur != -1) return cur;
    cur = MX;
    int j = leftt;
    for(int i = leftt ; i >= 0 ; i--){
        cur = min(cur, DP(pos + 1, i) + dp1[pos][j - i]);
    }
    return cur;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i <= 502 ; i++){
        for(int j = 0 ; j <= 502 ; j++){
            dp1[i][j] = MX;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        V.clear();
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == '1'){
                V.push_back(j);
            }
        }
        for(int j = 0 ; j < V.size() ; j++){
            for(int t = j; t < V.size() ; t++){
                dp1[i][V.size() - ((t - j) + 1)] = min(dp1[i][V.size() - ((t - j) + 1)], (V[t] - V[j]) + 1);
            }
        }
        dp1[i][V.size()] = 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << DP(1, k) << endl;
    return 0;
}