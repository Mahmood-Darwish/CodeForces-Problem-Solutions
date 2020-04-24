#include <iostream>
#include <string.h>

using namespace std;

int n;
int a[2000];
int dp[2000][2000];

int DP(int pos1, int pos2)
{
    if(pos1 == n){
        return max(a[pos1], a[pos2]);
    }
    if(pos1 > n){
        return a[pos2];
    }
    int &cur = dp[pos1][pos2];
    if(cur != -1) return cur;
    cur = min(DP(pos1 + 2, pos2) + max(a[pos1], a[pos1 + 1]), min(DP(pos1 + 2, pos1) + max(a[pos2], a[pos1 + 1]), DP(pos1 + 2, pos1 + 1) + max(a[pos1], a[pos2])));
    return cur;
}

void find_sol(int pos1, int pos2)
{
    if(pos1 == n){
        cout << pos1 << ' ' << pos2 << endl;
        return;
    }
    if(pos1 > n){
        cout << pos2 << endl;
        return;
    }
    int ans = DP(pos1, pos2);
    if(DP(pos1 + 2, pos2) + max(a[pos1], a[pos1 + 1]) == ans){
        cout << pos1 << ' ' << pos1 + 1 << endl;
        find_sol(pos1 + 2, pos2);
        return;
    }
    if(DP(pos1 + 2, pos1) + max(a[pos2], a[pos1 + 1]) == ans){
        cout << pos2 << ' ' << pos1 + 1 << endl;
        find_sol(pos1 + 2, pos1);
        return;
    }
    if(DP(pos1 + 2, pos1 + 1) + max(a[pos2], a[pos1]) == ans){
        cout << pos1 << ' ' << pos2 << endl;
        find_sol(pos1 + 2, pos1 + 1);
        return;
    }
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[1] << endl;
        cout << 1 << endl;
        return 0;
    }
    if(n == 2){
        cout << max(a[1], a[2]) << endl;
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << min(min(DP(4, 1) + max(a[2], a[3]), DP(4, 2) + max(a[1], a[3])), DP(4, 3) + max(a[2], a[1])) << endl;
    if(DP(4, 1) + max(a[2], a[3]) == min(min(DP(4, 1) + max(a[2], a[3]), DP(4, 2) + max(a[1], a[3])), DP(4, 3) + max(a[2], a[1]))){
        cout << 2 << ' ' << 3 << endl;
        find_sol(4, 1);
    }
    else{
        if(DP(4, 2) + max(a[1], a[3]) == min(min(DP(4, 1) + max(a[2], a[3]), DP(4, 2) + max(a[1], a[3])), DP(4, 3) + max(a[2], a[1]))){
            cout << 1 << ' ' << 3 << endl;
            find_sol(4, 2);
        }
        else {
            if(DP(4, 3) + max(a[2], a[1]) == min(min(DP(4, 1) + max(a[2], a[3]), DP(4, 2) + max(a[1], a[3])), DP(4, 3) + max(a[2], a[1]))){
                cout << 2 << ' ' << 1 << endl;
                find_sol(4, 3);
            }
        }
    }
    return 0;
}