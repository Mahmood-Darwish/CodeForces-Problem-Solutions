#include <iostream>
#include <string.h>

using namespace std;

int dp[2000][2000] , n , m , ans;
string s1 , s2;

int DP(int i , int j)
{
    if(i == n)return m - j;
    if(j == m)return n - i;
    int &cur = dp[i][j];
    if(cur != -1)return cur;
    cur = min(DP(i , j + 1) + 1 , DP(i + 1 , j) + 1);
    cur = min(cur , DP(i + 1 , j + 1) + 1);
    if(s1[i] == s2[j])
        cur = min(cur , DP(i + 1 , j + 1));
    return cur;
}

int pos = 0;

void find_sol(int i , int j)
{
    pos++;
    if(i == n && j == m)return;
    if(i == n){
        cout << "INSERT " << pos << " " << s2[j] << '\n';
        ans--;
        find_sol(i , j + 1);
        return;
    }
    if(j == m){
        cout << "DELETE " << pos << '\n';
        pos--;
        find_sol(i + 1 , j);
        return;
    }
    if(DP(i + 1 , j) + 1 == ans){
        ans--;
        cout << "DELETE " << pos << '\n';
        pos--;
        find_sol(i + 1 , j);
        return;
    }
    if(DP(i , j + 1) + 1 == ans){
        ans--;
        cout << "INSERT " << pos << " " << s2[j] << '\n';
        find_sol(i , j + 1);
        return;
    }
    if(DP(i + 1 , j + 1) + 1 == ans){
        ans--;
        cout << "REPLACE " << pos << " " << s2[j] << '\n';
        find_sol(i + 1 , j + 1);
        return;
    }
    if(s1[i] == s2[j]){
        if(DP(i + 1 , j + 1) == ans){
            find_sol(i + 1 , j + 1);
            return;
        }
    }
    return;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> s1;
    cin >> s2;
    n = s1.size();
    m = s2.size();
    ans = DP(0,0);
    cout << ans << '\n';
    find_sol(0,0);
    return 0;
}