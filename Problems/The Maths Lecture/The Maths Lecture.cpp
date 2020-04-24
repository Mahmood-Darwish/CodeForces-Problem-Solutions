#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[1007][107][2], MOD, n, k, ans;

ll pw(ll b,ll a,ll kk){
    if(a<0)return 0;
    if(a==0)return 1;
    if(a==1){
        return b%kk;
    }
    else{
        ll x=pw(b,a/2,kk);
        x*=x;
        x%=kk;
        if(a%2)
            return (x*b)%kk;
        else
            return x;
    }
}

ll DP(int pos, int mod, bool ok)
{
    if(pos == n){
        if(!ok)
            return 0;
        return (mod == 0);
    }
    ll &cur = dp[pos][mod][ok];
    if(cur != -1)
        return cur;
    cur = 0;
    if(!mod && ok){
        cur = (9 * pw(10, (n - pos) - 1, MOD) % MOD);
        return cur;
    }
    for(int i = 0 ; i < 10; i++){
        cur = ((cur % MOD) + (DP(pos + 1, (mod + (i * pw(10,pos,k))) % k , i) % MOD)) % MOD;
    }
    return cur;
}

int main()
{
    cin >> n >> k >> MOD;
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < 10 ; i++){
        ans = ((ans % MOD) + (DP(1, (i % k), i) % MOD)) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}