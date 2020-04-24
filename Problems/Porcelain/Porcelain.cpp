#include <bits/stdc++.h>
#define F first
#define B break
#define S second
#define ll long long
#define pb push_back
#define SI size()
#define C continue
#define R return
using namespace std;

int n, m, MX = 99999999;
int a[110][110];
int dp1[110][110][110];
int dp2[110][110];
int dp3[110][11100];
int x[110];

int DP1(int l, int r, int leftt, int arr)
{
    if(leftt == 0) return 0;
    int &cur = dp1[l][r][leftt];
    if (cur != -1) return cur;
    cur = max(DP1(l + 1, r, leftt - 1, arr) + a[arr][l], DP1(l, r - 1, leftt - 1, arr) + a[arr][r]);
    return cur;
}

int DP2(int pos, int leftt)
{
    if(pos > n){
        if(leftt == 0) return 0;
        else return -MX;
    }
    int &cur = dp3[pos][leftt];
    if(cur != -1) return cur;
    for(int i = 0 ; i <= min(x[pos], leftt) ; i++){
        cur = max(cur, DP2(pos + 1, leftt - i) + dp2[pos][i]);
    }
    return cur;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &x[i]);
        for(int j = 1 ; j <= x[i] ; j++) scanf("%d", &a[i][j]);
    }
    for(int i = 1 ; i <= n ; i++){
        memset(dp1, -1, sizeof(dp1));
        for(int j = 1 ; j <= x[i] ; j++){
            dp2[i][j] = DP1(1, x[i], j, i);
        }
    }
    memset(dp3, -1, sizeof(dp3));
    printf("%d\n", DP2(1, m));
    R 0;
}