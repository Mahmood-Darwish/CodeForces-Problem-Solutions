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
typedef int ll;

ll INF = (1 << 29);

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

ll n;
ll A[100100];
map < pair < pair < int , int >, int > , int > dp;

ll GCD(int a, int b)
{
    if(!b) return a;
    return GCD(b, a % b);
}

ll DP(int a, int b, int c)
{
    //cout << a << ' ' << b << ' ' << c << endl;
    if(c == 1 || b == 1) return 0;
    if(a >= n) return INF;
    if(dp[{{a, b}, c}] != 0) return dp[{{a, b}, c}];
    ll cur = INF;
    cur = min(cur, DP(a + 1, c, A[a + 1]));
    dp[{{a, b}, c}] = cur;
    if(b == c) return cur;
    if(GCD(c, b) != b) cur = min(cur, DP(a, GCD(b, c), c) + 1);
    if(GCD(c, b) != c) cur = min(cur, DP(a, b, GCD(b, c)) + 1);
    dp[{{a, b}, c}] = min(dp[{{a, b}, c}], cur);
    return cur;
}

int main()
{
    cin >> n;
    cin >> A[0];
    ll x = A[0];
    int ones = (A[0] == 1);
    for(int i = 1 ; i < n ; i++){
        scanf("%d", &A[i]);
        x = GCD(A[i], x);
        ones += (A[i] == 1);
    }
    if(ones){
        cout << n - ones << endl;
        return 0;
    }
    if(x != 1) cout << -1 << endl;
    else cout << DP(1, A[0], A[1]) + n - 1 << endl;
    return 0;
}