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

int n, a, b, sum = (999999);
vector < pair < int , int > > V;

int F(int x, int y)
{
    int temp = 0;
    while(temp < 4000){
        if(x == a && y == b){
            return temp;
        }
        temp++;
        y += n;
        if(y >= 60){
            y %= 60;
            x++;
        }
        if(x >= 24){
            x %= 24;
        }
    }
    return temp;
}

int main()
{
    for(int j = 0 ; j <= 23 ; j++){
        V.push_back({j, 7});            V.push_back({j, 17});            V.push_back({j, 27});            V.push_back({j, 37});            V.push_back({j, 47});            V.push_back({j, 57});
    }
    for(int i = 0 ; i <= 59; i++){
        V.push_back({7, i});
        V.push_back({17, i});
    }
    cin >> n;
    cin >> a >> b;
    for(int i = 0 ; i < V.size() ; i++){
        sum = min(sum, F(V[i].F, V[i].S));
    }
    cout << sum << endl;
}