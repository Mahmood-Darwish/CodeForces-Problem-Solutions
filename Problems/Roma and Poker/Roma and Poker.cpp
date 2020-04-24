#include <iostream>
#include <string.h>

using namespace std;

string s;
int n, k, INF = (1 << 31);
int dp[3010][3010];

int DP(int pos, int diff)
{
    //cout << pos << ' ' << diff << endl;
    if(pos == n && abs(diff - 2000) == k)
        return 1;
    if(pos == n)
        return -INF;
    if(abs(diff - 2000) >= k)
        return -INF;
    int &cur = dp[pos][diff];
    if(cur != -1)
        return cur;
    cur = 0;
    if(s[pos] == 'W'){
        return cur = DP(pos + 1, diff + 1) + 1;
    }
    if(s[pos] == 'D'){
        return cur = DP(pos + 1, diff);
    }
    if(s[pos] == 'L'){
        return cur = DP(pos + 1, diff - 1);
    }
    if(s[pos] == '?'){
        return cur = max(DP(pos + 1, diff + 1) + 1, max(DP(pos + 1, diff), DP(pos + 1, diff -1)));
    }
}

void find_sol(int pos, int diff)
{
    if(pos == n && abs(diff - 2000) == k)
        return ;
    if(pos == n)
        return ;
    if(abs(diff - 2000) >= k)
        return ;
    int ans = DP(pos, diff);
    if(s[pos] == 'W'){
        find_sol(pos + 1, diff + 1);
        return;
    }
    if(s[pos] == 'D'){
        find_sol(pos + 1, diff);
        return;
    }
    if(s[pos] == 'L'){
        find_sol(pos + 1, diff - 1);
        return;
    }
    if(s[pos] == '?'){
        if(DP(pos + 1, diff + 1) + 1 == ans){
            s[pos] = 'W';
            find_sol(pos + 1, diff + 1);
            return;
        }
        if(DP(pos + 1, diff) == ans){
            s[pos] = 'D';
            find_sol(pos + 1, diff);
            return;
        }
        if(DP(pos + 1, diff - 1) == ans){
            s[pos] = 'L';
            find_sol(pos + 1, diff - 1);
            return;
        }
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cin >> s;
    if(DP(0, 2000) > 0){
        find_sol(0, 2000);
        cout << s << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}