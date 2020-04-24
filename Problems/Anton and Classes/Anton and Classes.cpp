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

ll n, m, l, r, sum;
vector < pair < int , int > > V1, V2, V3, V4;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> l >> r;
        V1.pb({l, r});
        V2.pb({r, l});
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> l >> r;
        V3.pb({l, r});
        V4.pb({r, l});
    }
    sort(V3.begin(), V3.end());
    sort(V4.begin(), V4.end());
    if(V2[0].F <= V3[m - 1].F){
        sum = max(sum, 1LL * V3[m - 1].F - V2[0].F);
    }
    if(V4[0].F <= V1[n - 1].F){
        sum = max(sum , 1LL * V1[n - 1].F - V4[0].F);
    }
    cout << sum << endl;
    return 0;
}