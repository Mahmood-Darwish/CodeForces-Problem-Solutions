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

int INF = (1 << 29);

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

int n, m, B1 , B2, B3  , B4;
char a[110][110];
int bottom , top = -1, leftt, rightt, sum = -1;

bool check(int x, int y, int len)
{
    if(x + len > n || y + len > m)
        return false;
    if(top >= x && bottom <= x + len && leftt >= y && rightt <= y + len){
        return true;
    }
    return false;
}

int get(int x, int y, int len)
{
    int ans = 0;
    for(int i = x ; i <= len + x ; i++){
        for(int j = y ; j <= len + y ; j++){
            if(a[i][j] == 'W'){
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i][j] == 'B'){
                top = i;
                B1 = 1;
                break;
            }
        }
        if(B1) break;
    }
    if(top == -1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = n ; i > 0 ; i--){
        for(int j = 1 ; j <= m ; j++){
            if(a[i][j] == 'B'){
                bottom = i;
                B2 = 1;
                break;
            }
        }
        if(B2) break;
    }
    for(int j = 1 ; j <= m ; j++){
        for(int i  = 1 ; i <= n ; i++){
            if(a[i][j] == 'B'){
                leftt = j;
                B3 = 1;
                break;
            }
        }
        if(B3) break;
    }
    for(int j = m ; j > 0 ; j--){
        for(int i  = 1 ; i <= n ; i++){
            if(a[i][j] == 'B'){
                rightt = j;
                B4 = 1;
                break;
            }
        }
        if(B4) break;
    }
    //cout << top << ' ' << bottom << ' ' << rightt << ' ' << leftt << endl;
    bool B = false;
    for(int len = 0 ; len <= min(n, m) ; len++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(check(i, j, len)){
                    //cout << i << ' ' << j << ' ' << len << endl;
                    sum = get(i, j, len);
                    B = true;
                    break;
                }
            }
            if(B) break;
        }
        if(B) break;
    }
    cout << sum << endl;
    return 0;
}