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

ll INF = (1 << 30);

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

int n;
string s, s1 = "miao.", s2 = "lala.";

int main()
{
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin, s);
        if(s.size() < 5){
            cout <<"OMG>.< I don't know!\n";
            continue;
        }
        bool V = true, B = true;
        for(int i = 0 ; i < 5 ; i++){
            if(s[i] != s1[i]){
                B = false;
            }
        }
        for(int i = s.size() - 5 , j = 0; j < 5 ; i++, j++ ){
            if(s[i] != s2[j]){
                V = false;
            }
        }
        if(V && B){
        cout << "OMG>.< I don't know!\n";
            continue;
        }
        if(!V && B){
            cout << "Rainbow's\n";
            continue;
        }
        if(!B && V){
            cout << "Freda's\n";
            continue;
        }
        cout << "OMG>.< I don't know!\n";
    }
}