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

int l1, l2 ,l3,l4,r1,r2,r3,r4,s1,s2,s3,s4,p1,p2,p3,p4;

int main(){
    cin >> l1 >> s1 >> r1 >> p1;
    cin >> l2 >> s2 >> r2 >> p2;
    cin >> l3 >> s3 >> r3 >> p3;
    cin >> l4 >> s4 >> r4 >> p4;
    if(l1 || s1 || r1 || l2 || s3 || r4){
        if(p1){
            cout << "YES";
            return 0;
        }
    }
    if(l2 || s2 || r2 || l3 || s4 || r1){
        if(p2){
            cout << "YES";
            return 0;
        }
    }
    if(l3 || s3 || r3 || l4 || s1 || r2){
        if(p3){
            cout << "YES";
            return 0;
        }
    }
    if(l4 || s4 || r4 || l1 || s2 || r3){
        if(p4){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}