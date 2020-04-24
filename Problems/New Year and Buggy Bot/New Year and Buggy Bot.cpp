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

string s;
int sum;
int n, m;
char a[200][200];
char d[5];

bool ok(int i, int j, int pos)
{
   // cout << i << ' ' << j << ' ' << pos << endl;
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if(a[i][j] == '#')
        return false;
    if(a[i][j] == 'E')
        return true;    
    if(pos >= s.size()) return false;
    if(d[s[pos] - '0'] == 'U'){
        return ok(i - 1, j, pos + 1);
    }
    if(d[s[pos] - '0'] == 'D'){
        return ok(i + 1, j, pos + 1);
    }
    if(d[s[pos] - '0'] == 'R'){
        return ok(i, j + 1, pos + 1);
    }
    if(d[s[pos] - '0'] == 'L'){
        return ok(i, j - 1, pos + 1);
    }
    return false;
}

int main(){
    int x, y;
    cin >> n >> m;
    for(int i= 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                x = i, y = j;
            }
        }
    }
    cin >> s;
    d[0] = 'D';
    d[1] = 'L';
    d[2] = 'U';
    d[3] = 'R';
    sort(d, d + 4);
    do{
        if(ok(x, y, 0)){
            sum++;
        }
    }while(next_permutation(d, d + 4));
    cout << sum << endl;
}