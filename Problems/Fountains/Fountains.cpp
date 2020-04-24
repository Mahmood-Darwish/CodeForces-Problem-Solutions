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

int n, ans1, ans2, ans3, c, d, b, p, mx11, mx12 ,mx21, mx22, INF = (1 << 29);
int ind11, ind12, ind21, ind22;
char C;
vector < pair < int , int > > coin, dims;
vector < pair < int , pair < pair < int , int > , pair < int , int > > > > V1, V2;

int main()
{
    cin >> n >> c >> d;
    for(int i = 1 ; i <= n ; i++){
        SF(b);
        SF(p);
        cin >> C;
        if(C == 'C' && p <= c){
            coin.push_back({p, b});
        }
        if(C == 'D' && p <= d){
            dims.push_back({p, b});
        }
    }
    sort(coin.begin(), coin.end());
    sort(dims.begin(), dims.end());
    for(int i = 0 ; i < coin.size() ; i++){
        if(coin[i].S > mx11){
            mx11 = coin[i].S;
            ind11 = i;
        }
        else{
            if(coin[i].S >= mx12){
                mx12 = coin[i].S;
                ind12 = i;
            }
        }
        V1.push_back({coin[i].F, {{mx11, ind11}, {mx12, ind12}}});
    }
    for(int i = 0 ; i < dims.size() ; i++){
        if(dims[i].S > mx21){
            mx21 = dims[i].S;
            ind21 = i;
        }
        else{
            if(dims[i].S >= mx22){
                mx22 = dims[i].S;
                ind22 = i;
            }
        }
        V2.push_back({dims[i].F, {{mx21, ind21}, {mx22, ind22}}});
    }
    if(mx21 && mx11){
        ans1 = mx11 + mx21;
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    for(int i = 0 ; i < coin.size() ; i++){
        int low = 0, high = V1.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(c - coin[i].F >= V1[mid].F){
                low = mid + 1;
                if(V1[mid].S.F.S != i){
                    ans2 = max(ans2, coin[i].S + V1[mid].S.F.F);
                }
                else{
                    if(V1[mid].S.S.S != i)
                        ans2 = max(ans2, coin[i].S + V1[mid].S.S.F);
                }
            }
            else{
                high = mid - 1;
            }
        }
    }
    for(int i = 0 ; i < dims.size() ; i++){
        int low = 0, high = V2.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(d - dims[i].F >= V2[mid].F){
                low = mid + 1;
                if(V2[mid].S.F.S != i){
                    ans3 = max(ans3, dims[i].S + V2[mid].S.F.F);
                }
                else{
                    if(V2[mid].S.S.S != i)
                    ans3 = max(ans3, dims[i].S + V2[mid].S.S.F);
                }
            }
            else{
                high = mid - 1;
            }
        }
    }
    cout << max(max(ans1, ans2), ans3) << endl;
    return 0;
}