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

bool vis[100100];
vector < int > V, te[100100];

map < int , int > m;
int a[100100];

void fix(int ind)
{
    vis[ind] = true;
    V.pb(ind);
    if(vis[m[a[ind]]]) return;
    else fix(m[a[ind]]);
}

int n;
int b[100100];
int ans;

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0 ; i < n ; i++){
        m[b[i]] = i;
    }
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            fix(i);
            ans++;
            for(int i = 0 ; i < V.size() ; i++){
                te[ans].pb(V[i]);
            }
            V.clear();
        }
    }
    cout << ans << endl;
    for(int i = 1 ; i <= ans ; i++){
        cout << te[i].size() << ' ';
        for(int j = 0 ; j < te[i].size() ; j++){
            cout << te[i][j] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}