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

int n, m, x, tree[600100], temp = 1;

int Update(int node, int st, int en, int idx)
{
    if(st == en && st == idx) {
        tree[node]++;
        return tree[node];
    }
    if(idx > en || idx < st) return tree[node];
    int mid = (st + en) / 2;
    Update(node * 2, st, mid, idx);
    Update((node * 2) + 1, mid + 1, en, idx);
    tree[node] = min(tree[node * 2], tree[(node * 2) + 1]);
    return tree[node];
}


int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        SF(x);
        Update(1, 1, n, x);
        if(tree[1] >= temp){
            cout << 1;
            temp++;
        }
        else cout << 0;
    }
    return 0;
}