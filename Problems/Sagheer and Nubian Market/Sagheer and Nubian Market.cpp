#include <bits/stdc++.h>
#define SF(x) scanf("%I64d",&x)
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

ll n, s, ans1, ans2;
ll a[100100];
ll price[100100];

ll check(ll x)
{
    memset(price, 0, sizeof(price));
    for(int i = 1 ; i <= n ; i++){
        price[i] = a[i] + (i * x);
    }
    sort(price + 1, price + n + 1);
    /*for(int i = 1 ; i <= n ; i++){
        cout << price[i] << ' ';
    }
    cout << endl;*/
    ll sum = s;
    ll temp = 0;
    for(int i = 1 ; i <= x ; i++){
        if(sum >= price[i]){
            temp++;
            sum -= price[i];
            if(temp == x)
                break;
        }
        else{
            break;
        }
    }
    if(temp == x)
        return sum;
    return -1;
}

int main(){
    cin >> n >> s;
    for(int i = 1 ; i <= n ; i++){
        SF(a[i]);
    }
    ll low = 0, high = n;
    while(low <= high){
        ll mid = (low + high) / 2;
        //cout << mid << ' ' ;
        ll temp = check(mid);
        //cout << temp << endl;
        //cout << mid << ' ' << temp << endl;
        if(temp != -1){
            low = mid + 1;
            ans1 = mid;
            ans2 = s - temp;
        }
        else{
            high = mid - 1;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}