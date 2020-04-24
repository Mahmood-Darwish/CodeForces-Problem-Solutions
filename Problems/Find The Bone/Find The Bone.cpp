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

int n, m, k, bone = 1, u, v, num;
bool vis[1000100];

int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; i++){
        cin >> num;
        vis[num] = true;
    }
    bool B = false;
    if(vis[1]){
        B = true;
    }
    while(k--){
        if(!B){
            SF(u);
            SF(v);
            if(bone == u){
                if(vis[v]){
                    B = true;
                }
                bone = v;
                continue;
            }
            if(bone == v){
                if(vis[u]){
                    B = true;
                }
                bone = u;
            }
        }
        else{
            SF(u);
            SF(v);
        }
    }
    cout << bone << endl;
    return 0;
}