#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[20][(1 << 10) + 5][3];
ll dp2[20][(1 << 10) + 5][3];
ll pow[25];
ll n, l, r, MOD = 998244353, k;

ll F(ll x)
{
    ll temp = 0;
    while(x){
        x /= 10;
        temp++;
    }
    return temp;
}

ll G(ll x, ll ind)
{
    while(ind){
        x /= 10;
        ind--;
    }
    return x % 10;
}

ll mod(ll a)
{
    ll ans = a % MOD;
    if(ans < 0) return ans + MOD;
    return ans;
}

ll calc(ll x)
{
    if(x < 0) return 0;
    ll ans = 0LL;
    for(ll len = F(x) - 1;  len >= 0 ; len--){
        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));
        ll cur = G(x, len);
        if(len == F(x) - 1){
            for(ll i = 1 ; i < cur ; i++){
                dp[len][(1 << i)][0]++;
                dp2[len][(1 << i)][0] = mod(mod(dp2[len][(1 << i)][0]) + mod(pow[len] * i));
            }
            dp[len][(1 << cur)][1]++;
            dp2[len][(1 << cur)][1] = mod(mod(dp2[len][(1 << cur)][1]) + mod(pow[len] * cur));
        }
        else{
            for(ll i = 1 ; i <= 9 ; i++){
                dp[len][(1 << i)][0]++;
                dp2[len][(1 << i)][0] = mod(mod(dp2[len][(1 << i)][0]) + mod(pow[len] * i));
            }
        }
        for(ll i = len - 1; i >= 0; i--){
            cur = G(x, i);
            for(ll j = 0 ; j < 1024 ; j++){
                for(ll t = 0 ; t <= 9 ; t++){
                    dp[i][j | (1 << t)][0] = mod(mod(dp[i + 1][j][0]) + mod(dp[i][j | (1 << t)][0]));
                }
                for(ll t = 0 ; t < cur ; t++){
                    dp[i][j | (1 << t)][0] = mod(mod(dp[i + 1][j][1]) + mod(dp[i][j | (1 << t)][0]));
                }
                dp[i][j | (1 << cur)][1] = mod(mod(dp[i + 1][j][1]) + mod(dp[i][j | (1 << cur)][1]));
            }
        }
        for(ll i = len - 1 ; i >= 0 ; i--){
            cur = G(x, i);
            for(ll j = 0 ; j < 1024 ; j++){
                for(ll t = 0 ; t <= 9 ; t++){
                    dp2[i][j | (1 << t)][0] = mod(mod(dp2[i][j | (1 << t)][0]) + mod(mod(dp2[i + 1][j][0]) + mod(mod(dp[i + 1][j][0]) * mod(pow[i] * t))));
                }
                for(ll t = 0 ; t < cur ; t++){
                    dp2[i][j | (1 << t)][0] = mod(mod(dp2[i][j | (1 << t)][0]) + mod(mod(dp2[i + 1][j][1]) + mod(mod(dp[i + 1][j][1]) * mod(pow[i] * t))));
                }
                dp2[i][j | (1 << cur)][1] = mod(mod(dp2[i][j | (1 << cur)][1]) + mod(mod(dp2[i + 1][j][1]) + mod(mod(dp[i + 1][j][1]) * mod(pow[i] * cur))));
            }
        }
        for(ll i = 0 ; i < 1024 ; i++){
            if(__builtin_popcount(i) > k) continue;
            ans = mod(mod(ans) + mod(dp2[0][i][0]));
            ans = mod(mod(dp2[0][i][1]) + mod(ans));
        }
    }
    return mod(ans);
}

int main()
{
    pow[0] = 1;
    for(ll i = 1 ; i <= 20 ; i++)
        pow[i] = mod(pow[i - 1] * 10);
    cin >> l >> r >> k;
    cout << mod(calc(r) - calc(l - 1)) << endl;
    return 0;
}