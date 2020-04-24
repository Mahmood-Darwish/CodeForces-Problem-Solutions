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

ll n;
ll x[10011];
ll y[100100];
ll Y1[100100];
ll x1[100100];
map < pair < ll , ll > , bool > m;


int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n ; i++){
        cin >> x1[i] >> Y1[i];
        m[{x1[i], Y1[i]}] = true;
    }
    for(int i = 1 ; i <= n ; i++){
        pair < ll, ll > u = {x[1] + x1[i], y[1] + Y1[i]};
        bool B = true;
        for(int j = 1 ; j <= n ; j++){
            if(!m[{u.F - x[j], u.S - y[j]}]){
                B = false;
                break;
            }
        }
        if(B){
            cout << u.F << ' ' << u.S << endl;
            return 0;
        }
    }
    return 0;
}