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

vector < pair < ll, ll > > V;
ll n, b;
map < ll , ll > m;
ll ans = (1LL << 62);

void find_prime(ll x)
{
    while (x%2 == 0)
    {
        m[2]++;
        x = x/2;
    }
    for (int i = 3; i <= sqrt(x); i = i+2)
    {
        while (x%i == 0)
        {
            m[i]++;
            x = x/i;
        }
    }
    if(x > 1)
        m[x]++;
    for(auto it = m.begin() ; it != m.end() ; it++){
        V.pb({it -> first, it -> second});
    }
}


int main()
{
    cin >> n >> b;
    find_prime(b);
    for(int i = 0 ; i < V.size() ; i++){
        ll sum = 0;
        ll q = V[i].F;
        while(q <= n / V[i].F){
            sum += n / q;
            q *= V[i].F;
        }
        sum += n / q;
            q *= V[i].F;
        sum /= (V[i].S);
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}