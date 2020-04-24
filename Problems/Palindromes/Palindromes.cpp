#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k, dp[507][507], cor[507][507];
string s;

int calc(int pos1 , int pos2)
{
    int sum = 0;
    if(pos2 == -1)
    {
        pos2 = n - 1;
    }
    while(pos1 < pos2)
    {
        if(s[pos1] != s[pos2])
            sum++;
        pos1++;
        pos2--;

    }
    return sum;
}

void correct(int pos1 , int pos2)
{
    for(int i = pos1 ; i <= pos2 ; i++){
        int pos = pos2 - (i - pos1);
        s[i] = s[pos];
        cout << s[i];
    }
}

int DP(int pos , int how_much)
{
    if(pos == n)return 0;
    if(how_much == 0)return cor[pos][n - 1];
    int &cur = dp[pos][how_much];
    if(cur != -1){
        return cur;
    }
    cur = DP(n, how_much) + cor[pos][n - 1];
    for(int i = pos ; i < n ; i++){
        if(how_much)
            cur = min(cur, DP(i + 1, how_much - 1) + cor[pos][i]);
    }
    return cur;
}

void find_sol(int pos, int how_much, int ans)
{
    if(n == pos)return;
    if(how_much == 0){
        correct(pos, n - 1);
        return;
    }
    if(DP(n, how_much) + cor[pos][n - 1] == ans){
        correct(pos, n - 1);
        return;
    }
    for(int i = pos ; i < n ; i++){
        if(DP(i + 1, how_much - 1) + cor[pos][i] == ans){
            correct(pos, i);
            cout << '+';
            find_sol(i + 1, how_much - 1, ans - cor[pos][i]);
            return;
        }
    }
    return;
}

int main()
{
    cin >> s >> k;
    n = s.size();
    memset(dp,-1,sizeof(dp));
    k--;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            cor[i][j] = calc(i,j);
        }
    }
    cout << DP(0,k) << endl;
    find_sol(0,k,DP(0,k));
    return 0;
}