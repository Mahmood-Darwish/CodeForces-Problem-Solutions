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

ll getXor2(ll a) {
     ll ressssss[] = {a, 1, a+1, 0};
     return ressssss[a % 4];
}

ll getXor(ll a, ll b) {
     return getXor2(b) ^ getXor2(a - 1);
}

ll n, m, k, a[10000], ans = INF;

int main()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <=n ; i++){
        cin >> a[i];
        if(a[i] == 0)
            a[i] = INF;
    }
    for(int i = m + 1 ; i <= n ; i++){
        if(a[i] <= k){
            ans = min(ans, abs(i - m));
        }
    }
    for(int i = m - 1 ; i > 0 ; i--){
        if(a[i] <= k){
            ans = min(ans, abs(i - m));
        }
    }
    cout << ans * 10 << endl;
    return 0;
}