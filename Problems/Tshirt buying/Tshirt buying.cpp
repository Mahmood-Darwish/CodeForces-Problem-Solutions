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

priority_queue < pair < int , int >,vector < pair < int , int > > , greater < pair < int , int > > > fq, sq, tq;
int n, m, q;
int price[200100];
int color1[200100];
int color2[200100];
bool vis[200100];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
            SF(price[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        SF(color1[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        SF(color2[i]);
    }
    //cout << endl;
    for(int i = 1 ; i <= n ; i++){
        if(color1[i] == 1){
            fq.push({price[i], i});
        }
        if(color1[i] == 2){
            sq.push({price[i], i});
        }
        if(color1[i] == 3){
            tq.push({price[i], i});
        }
        if(color2[i] == 1){
            fq.push({price[i], i});
        }
        if(color2[i] == 2){
            sq.push({price[i], i});
        }
        if(color2[i] == 3){
            tq.push({price[i], i});
        }
        //cout << color1[i] << ' ' << color2[i] << ' '<< price[i] << endl;
    }
    //cout << fq.size() << sq.size() << ' ' << tq.size()
    cin >> m;
    for(int i = 1 ; i <= m ; i++){
        SF(q);
        bool B = true;
        if(q == 1){
            while(fq.size()){
                pair < int , int > u = fq.top();
                fq.pop();
                if(!vis[u.S]){
                    cout << u.F << ' ';
                    vis[u.S] = true;
                    B = false;
                    break;
                }
            }
                if(B){
                    cout << -1 << ' ';
                }
        }
        if(q == 2){
            while(sq.size()){
                pair < int , int > u = sq.top();
                sq.pop();
                if(!vis[u.S]){
                    cout << u.F << ' ';
                    vis[u.S] = true;
                    B = false;
                    break;
                }
            }
                if(B){
                    cout << -1 << ' ';
                }
        }
        if(q == 3){
            while(tq.size()){
                pair < int , int > u = tq.top();
                tq.pop();
                if(!vis[u.S]){
                    cout << u.F << ' ';
                    vis[u.S] = true;
                    B = false;
                    break;
                }
            }
                if(B){
                    cout << -1 << ' ';
                }
        }
    }
    return 0;
}