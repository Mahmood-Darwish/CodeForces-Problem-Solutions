#include <bits/stdc++.h>
#define SF(x) scanf("%I64d",&x)
#define F first
#define S second
#define MEM(a,b) memset(a,b,sizeof(a))
#define DB(x) cout << #x << " is " << x << ' '
#define ffs(x) __builtin_ffs(x) // This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
#define clz(x) __builtin_clz(x) // This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define ctz(x) __builtin_ctz(x) // This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define popcount(x) __builtin_popcount(x) // This function returns number of active bits in the binary represintation of the number
#define pb push_back

using namespace std;
typedef long long ll;

ll INF = (1 << 30);

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

ll n, k, ans, sum;
ll a[1000100];
ll dp[1000100];
map < ll , ll > m;
ll MAXX = 1e16;

int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        SF(a[i]);
    }
    dp[0] = 1;
    ll J = 0;
    while(k != 1 && k != -1){
        if(abs(dp[J]) > MAXX)
            break;
        dp[J + 1] = dp[J] * k;
        J++;
    }
    if(k == 1){
        dp[0] = 1;
        J = 0;
    }
    if(k == -1){
        dp[0] = 1, dp[1] = -1;
        J = 1;
    }
    sum = 0LL;
    m[0]++;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        m[sum]++;
        for(int j = 0 ; j <= J ; j++){
            ll temp = sum - dp[j];
            if(m.find(temp) != m.end()){
                ans += m[temp];
            }
        }
    }
    cout << ans << endl;
    return 0;
}