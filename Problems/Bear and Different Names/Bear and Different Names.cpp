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

ll n, k, temp;
vector < string > V;
string a[100];
string arr[] = {"B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T",
"U","V","W","X","Y","Z","Aa","Bb","Cc","Dd","Ee","Ff","Gg","Hh","Ii","Jj","Kk","Ll","Mm","Nn","Oo","Pp",
"Qq","Rr","Ss","Tt","Uu","Vv","Ww","Xx","Yy","Zz","Aaa","Bbb","Ccc","Ddd","Eee","Fff","Ggg","Hhh","Iii","Jjj","Kkk","Lll","Mmm","Nnn","Ooo","Ppp","Qqq","Rrr","Sss","Ttt","Uuu","Vvv","Www","Xxx","Yyy","Zzz"};


int main()
{
    cin >> n >> k;
    cin >> a[0];
    if(a[0] == "NO"){
        V.pb("A");
        V.pb("A");
        for(int i = 2 ; i < k; i++){
            V.pb(arr[temp++]);
        }
    }
    else{
        for(int i = 0 ; i < k; i++){
            V.pb(arr[temp++]);
        }
    }
    for(int i = 1 ; i <= n - k; i++){
        cin >> a[i];
        if(a[i] == "NO"){
            V.pb(V[(V.size() - (k - 1))]);
        }
        else{
            V.pb(arr[temp++]);
        }
    }
    for(auto cur : V){
        cout << cur << ' ' ;
    }
    cout << endl;
}