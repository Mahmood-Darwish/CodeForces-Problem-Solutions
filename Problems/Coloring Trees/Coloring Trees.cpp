#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MEM(i,n) memset(i,n,sizeof(i))

using namespace std;
typedef long long ll;

ll GCD(ll a , ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b)
{
    return ( a * b ) / GCD(a,b);
}

ll n , k , m , dp[200][200][200];
vector <int> adj[1000];
ll a[200];


ll DP(ll pos , ll cur , ll last)
{
    if(cur > k)return 9999999999999;
    if(pos == n && cur == k)return 0;
    if(pos == n)return 9999999999999;
    if(dp[pos][cur][last] != -1)return dp[pos][cur][last];
    if(a[pos] != 0)
        return dp[pos][cur][last] = DP(pos+1,cur + (last != a[pos]),a[pos]);
    dp[pos][cur][last] = 9999999999999;
    for(int i = 1 ; i <= m ; i++)
    {
        dp[pos][cur][last] = min(dp[pos][cur][last] , DP(pos+1,cur + (last != i), i) + adj[pos][i]);
    }
    return dp[pos][cur][last];
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        adj[i].pb(0);
        for(int j = 1 ; j <= m ; j++)
        {
            ll num;
            cin >> num;
            adj[i].pb(num);
        }
    }
    memset(dp,-1,sizeof(dp));
    if(DP(0,0,0) == 9999999999999)
        cout << -1;
    else cout << DP(0,0,0);
    return 0;
}