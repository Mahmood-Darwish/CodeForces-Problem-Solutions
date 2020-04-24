#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;

ll MOD = (1e9) + 7;
ll m, k, non;
ll dp[1050][1050];
ll c[1050];
ll factorial[100100];
vector < ll > V;
ll n;

ll power(ll a, ll b, ll mod){
	ll x = 1, y = a;
	while (b > 0){
		if (b % 2){
			x = (x * y) % mod;
		}
		y = (y * y) % mod;
		b /= 2;
	}
	return x % mod;
}

ll modular_inverse(ll N, ll mod){
	return power(N, mod - 2, mod);
}

ll nCr(ll N, ll K, ll mod){
    return (factorial[N] * ((modular_inverse(factorial[K], mod) * modular_inverse(factorial[N - K], mod)) % mod)) % mod;
}


ll DP(ll pos, ll x)
{
    if(x == m) return 1;
    if(pos > k) {
        if(non < m - x) return 0;
        return nCr(non, m - x, MOD);
    }
    ll &cur = dp[pos][x];
    if(cur != -1) return cur;
    cur = 0;
    cur += ((DP(pos + 1, x + 1) % MOD) * (c[pos] % MOD)) % MOD;
    cur += DP(pos + 1, x);
    cur %= MOD;
    return cur % MOD;
}

bool ok(ll x)
{
    while(x){
        if(x % 10 != 4 && x % 10 != 7){
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    ll x;
    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++){
        cin >> x;
        if(ok(x)){
            V.push_back(x);
        }
        else non++;
    }
    sort(V.begin(), V.end());
    if(V.size() > 0)
        k++;
    for(unsigned int i = 1 ; i < V.size() ; i++){
        c[k]++;
        if(V[i] != V[i - 1]){
            k++;
        }
    }
    factorial[0] = factorial[1] = 1;
    for(ll i = 2 ; i <= 100050 ; i++){
        //cout << i << endl;
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    c[k]++;
    memset(dp, -1, sizeof(dp));
    cout << DP(1, 0) << endl;
    return 0;
}