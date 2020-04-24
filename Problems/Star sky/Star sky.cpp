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
/*
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
*/
int n, q, c;
int a[110][110][15];
int x, y, s;
int t, x1, x2, y2;
int ans[15], sum;

void fix()
{
    for(int i = 1 ; i <= 100 ; i++){
        for(int j = 1 ; j <= 100 ; j++){
            for(int k = 0 ; k <= c ; k++){
                a[i][j][k] += a[i - 1][j][k];
            }
        }
    }
    for(int i = 1 ; i <= 100 ; i++){
        for(int j = 1 ; j <= 100 ; j++){
            for(int k = 0 ; k <= c ; k++){
                a[i][j][k] += a[i][j - 1][k];
            }
        }
    }
}

int main()
{
    cin >> n >> q >> c;
    for(int i = 0 ; i < n ; i ++){
        SF(x);
        SF(y);
        SF(s);
        a[x][y][s]++;
    }
    fix();
    int y1;
    while(q--){
        SF(t);
        SF(x1);
        SF(y1);
        SF(x2);
        SF(y2);
        for(int i = 0 ; i <= c ; i++){
            ans[i] = a[x2][y2][i];
        }
//        for(int i = 0 ; i <= c ; i++){
//            cout << ans[i] << ' ';
//        }
//        cout << endl;
//        cout << x2 << ' ' << y1 << endl;
        for(int i = 0 ; i <= c ; i++){
            ans[i] -= a[x2][y1 - 1][i];
        }
//
//        for(int i = 0 ; i <= c ; i++){
//            cout << ans[i] << ' ';
//        }
//        cout << endl;
        for(int i = 0 ; i <= c ; i++){
            ans[i] -= a[x1 - 1][y2][i];
        }
/*
        for(int i = 0 ; i <= c ; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;*/
        for(int i = 0 ; i <= c ; i++){
            ans[i] += a[x1 - 1][y1 - 1][i];
        }
//
//        for(int i = 0 ; i <= c ; i++){
//            cout << ans[i] << ' ';
//        }
//        cout << endl;
        sum = 0;
        for(int i = 0 ; i <= c ; i++){
            sum += (ans[i] * ((i + t) % (c + 1)));
        }
        printf("%d\n", sum);
    }
}