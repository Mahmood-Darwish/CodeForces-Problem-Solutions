#include <bits/stdc++.h>
#define SF(x) scanf("%d",&x)
#define F first
#define S second
#define MEM(a,b) memset(a,b,sizeof(a))
#define DB(x) cout << #x << " is " << x << endl
#define ffs(x) __builtin_ffs(x) // This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
#define clz(x) __builtin_clz(x) // This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define ctz(x) __builtin_ctz(x) // This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define popcount(x) __builtin_popcount(x) // This function returns number of active bits in the binary represintation of the number
#define pb push_back

using namespace std;
typedef long long ll;

ll INF = (1LL << 29LL);

ll Mypow(ll X,ll Y){
    if(Y < 0)return 0;
    if(Y == 0)return 1;
    if(Y == 1){
        return X;
    }
    else{
        ll x = Mypow(X ,Y / 2);
        x *= x;
        if(Y % 2)
            return (x * X);
        else
            return x;
    }
}

ll dp[5050][5050];
ll MX = (1 << 30);
ll a[5050];
ll n;
ll l[5050];
ll r[5050];

ll DP(ll pos1, ll pos2)
{
    if(pos1 == 1 && pos2 == n) return 0;
    ll &cur = dp[pos1][pos2];
    if(cur != -1) return cur;
    cur = MX;
    if(a[pos2 + 1] == a[pos1 - 1] && pos1 != 1 && pos2 != n){
        cur = DP(l[pos1 - 1], r[pos2 + 1]) + 1;
    }
    else{
        if(pos1 != 1)
            cur = min(DP(l[pos1 - 1], pos2) + 1, cur);
        if(pos2 != n)
            cur = min(DP(pos1, r[pos2 + 1]) + 1, cur);
    }
    return cur;
}

void fix(ll pos)
{
    for(ll i = pos + 1; i <= n + 1; i++){
        if(a[i] != a[pos] || i == n + 1){
            r[pos] = i - 1;
            break;
        }
    }
    for(ll i = pos - 1; i >= 0; i--){
        if(a[i] != a[pos] || i == 0){
            l[pos] = i + 1;
            break;
        }
    }
    return;
}


int main()
{
    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for(ll i = 1 ; i <= n ; i++){
        fix(i);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = MX;
    for(ll i = 1 ; i <= n ; i++){
        ans = min(ans, DP(l[i], r[i]));
    }
    cout << ans << endl;
    return 0;
}