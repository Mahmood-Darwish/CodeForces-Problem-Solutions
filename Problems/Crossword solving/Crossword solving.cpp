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

ll fact(ll a)
{
    if(a == 0)
        return 1;
    return a * fact(a - 1);
}

ll ans = INF , n, m;
vector < int > V;
string s, t;

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0 ; i < t.size() ; i++){
        ll sum = 0;
        vector < int > temp;
        for(int j = 0 ; j < s.size() ; j++){
            if(j + i >= t.size()){
                sum = INF + 5;
                break;
            }
            if(s[j] != t[i + j]){
                sum++;
                temp.push_back(j + 1);
            }
        }
        if(ans > sum){
            ans = sum;
            V = temp;
        }
    }
    cout << ans << endl;
    for(int i = 0 ; i < V.size() ; i++){
        cout << V[i] << ' ';
    }
    cout << endl;
}