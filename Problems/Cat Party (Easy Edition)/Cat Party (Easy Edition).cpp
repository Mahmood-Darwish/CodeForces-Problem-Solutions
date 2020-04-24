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

ll m, n;
ll k;
ll a[100100];
ll takrar1[100100];
ll takrar2[100100];
ll vis[100100];
ll ans = 1;
ll c;

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        takrar2[takrar1[a[i]]]--;
        if(takrar2[takrar1[a[i]]] == 0) c--;
        takrar1[a[i]]++;
        takrar2[takrar1[a[i]]]++;
        if(takrar2[takrar1[a[i]]] == 1) c++;
        if(!vis[a[i]]){
            vis[a[i]] = true;
            k++;
        }
        if(takrar2[takrar1[a[i]]] == 1 && takrar2[takrar1[a[i]] - 1] == k - 1 && c == 2){
            ans = i;
        }
        if(takrar2[takrar1[a[i]]] == k - 1 && takrar2[1] == 1 && c == 2 && takrar1[a[i]] != 1){
            ans = i;
        }
        if(takrar2[takrar1[a[i]]] == k - 1 && takrar2[takrar1[a[i]] + 1] == 1 && c == 2){
            ans = i;
        }
        if(c == 1 && k == 1){
            ans = i;
        }
        if(c == 1 && takrar2[1] > 0){
            ans = i;
        }
        if(takrar1[a[i]] == 1 && c == 2 && takrar2[1] == 1){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}