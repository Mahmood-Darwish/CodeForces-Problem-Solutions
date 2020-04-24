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

bool prime(ll x)
{
    for(int i = 2 ; i <= sqrt(x) ; i++){
        if(x % i == 0) return false;
    }
    return true;
}

ll n, m, sum;
vector < pair < ll , ll > > adj[100100];


int main()
{
    cin >> n >> m;
    if(n == 2){
        cout << 2 << ' ' << 2 << endl;
        cout << 1 << ' '  << 2 << ' ' << 2 << endl;
        return 0;
    }
    adj[1].push_back({n, 2});
    sum += 2;
    for(int i = 2 ; i <= n - 2 ; i++){
        adj[1].pb({i, 1});
        sum++;
    }
    m -= (n - 1);
    sum++;
    while(!prime(sum)){
        sum++;
    }
    adj[1].pb({n-1,(sum - n) + 1});
    //cout << m << ' ' << sum << endl;
    for(int i = 2 ; i <= n ; i++){
        for(int j = i + 1 ; j <= n ; j++){
            if(m == 0) break;
            adj[i].pb({j,1e9});
            m--;
        }
        if(m == 0) break;
    }
    cout << 2 << ' ' << sum << endl;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 0 ; j < adj[i].size() ; j++){
            printf("%I64d %I64d %I64d\n", i, adj[i][j].F, adj[i][j].S);
        }
    }
}