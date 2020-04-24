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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

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

int FX, FY;
char Down = 'D', Up = 'U', Left = 'L', Right = 'R';
int n, m;
char a[110][110];
int pos_x, pos_y, temp_x, temp_y;

bool check(int x, int y)
{
    if(x > n || x < 1 || y > m || y < 1 || a[x][y] == '*')
        return false;
    return true;
}

void BFS(int start_x, int start_y)
{
    bool vis[110][110];
    pair < int , int > par[110][110];
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    queue < pair < pair < int , int > , pair < int , int > > > Q;
    Q.push({{start_x, start_y}, {-1, -1}});
    while(!Q.empty()){
        pair < pair < int , int > , pair < int , int > > u = Q.front();
        Q.pop();
        if(!check(u.F.F, u.F.S)){
            continue;
        }
        if(vis[u.F.F][u.F.S]){
            continue;
        }
        vis[u.F.F][u.F.S] = true;
        par[u.F.F][u.F.S] = {u.S.F, u.S.S};
        for(int i = 0 ; i < 4 ; i++){
            Q.push({{u.F.F + dx[i], u.F.S + dy[i]}, {u.F.F, u.F.S}});
        }
    }
    int x = FX;
    int y = FY;
    string s = "";
    while(x != -1 && y != -1){
        if(par[x][y].F == x - 1){
            s += Down;
        }
        if(par[x][y].F == x + 1){
            s += Up;
        }
        if(par[x][y].S == y + 1){
            s += Left;
        }
        if(par[x][y].S == y - 1){
            s += Right;
        }
        int temp1 = par[x][y].F, temp2 = par[x][y].S;
        x = temp1, y = temp2;
    }
    reverse(s.begin(), s.end());
    for(int i = 0 ; i < s.size() ; i++){
        cout << s[i] << endl;
        cin >> x >> y;
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
            if(a[i][j] == 'F'){
                FX = i;
                FY = j;
            }
        }
    }
    if(a[2][1] != '*'){
        cout << Down << endl;
        cin >> pos_x >> pos_y;
        if(pos_x == FX && FY == pos_y){
            return 0;
        }
        if(pos_x == 1 && pos_y == 1){
            swap(Down, Up);
        }
        cout << Up << endl;
        cin >> pos_x >> pos_y;
        while(a[pos_x][pos_y + 1] == '*'){
            cout << Down << endl;
            cin >> pos_x >> pos_y;
            if(pos_x == FX && pos_y == FY){
                return 0;
            }
        }
        if(a[pos_x][pos_y + 1] != '*'){
            cout << Right << endl;
            cin >> temp_x >> temp_y;
            if(temp_x == FX && FY == temp_y){
                return 0;
            }
            if(pos_x == temp_x && pos_y == temp_y){
                swap(Left, Right);
            }
            pos_x = temp_x, pos_y= temp_y;
        }
    }
    else{
        cout << Right << endl;
        cin >> pos_x >> pos_y;
        if(pos_x == FX && FY == pos_y){
            return 0;
        }
        if(pos_x == 1 && pos_y == 1){
            swap(Left, Right);
        }
        cout << Left << endl;
        cin >> pos_x >> pos_y;
        while(a[pos_x + 1][pos_y] == '*'){
            cout << Right << endl;
            cin >> pos_x >> pos_y;
            if(pos_x == FX && pos_y == FY){
                return 0;
            }
        }
        if(a[pos_x + 1][pos_y] != '*'){
            cout << Down << endl;
            cin >> temp_x >> temp_y;
            if(temp_x == FX && FY == temp_y){
                return 0;
            }
            if(pos_x == temp_x && pos_y == temp_y){
                swap(Up, Down);
            }
            pos_x = temp_x, pos_y= temp_y;
        }
    }
    BFS(pos_x, pos_y);
    return 0;
}