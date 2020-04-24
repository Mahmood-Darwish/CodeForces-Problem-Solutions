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

int n;
char a[5500];
ll dp[2][5005];
ll x[2][5005];
ll MOD = (1e9) + 7;
ll sum;

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    dp[1][0] = 1;
    int cur = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(a[i] == 's'){
                x[cur][0] += dp[cur^1][j];
                x[cur][j + 1] -= dp[cur^1][j];
            }
            else{
                dp[cur][j + 1] += dp[cur^1][j];
                dp[cur][j + 1] %= MOD;
            }
        }
        sum = 0;
        for(int j = 0 ; j <= n ; j++){
            sum += x[cur][j];
            dp[cur][j] = ((sum % MOD) + (dp[cur][j] % MOD)) % MOD;
        }
        for(int j = 0 ; j <= n ; j++){
            dp[cur^1][j] = 0;
            x[cur^1][j] = x[cur][j] = 0;
        }
        cur ^= 1;
    }
    cout << dp[cur^1][0] % MOD << endl;
}