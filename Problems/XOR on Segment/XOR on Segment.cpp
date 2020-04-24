#include <iostream>
#include <stdio.h>

#define SF(x) scanf("%I64d", &x)

using namespace std;
typedef long long ll;

ll tree[22][100100 * 5];
ll lazy[22][100100 * 5];
ll n, q;
ll a[100100];

void Build(ll temp, ll node, ll st, ll en)
{
    if(st == en){
        tree[temp][node] = (0 != ((1 << temp) & a[st]));
        return ;
    }
    ll mid = (st + en) / 2;
    Build(temp, node * 2, st, mid);
    Build(temp, (node * 2) + 1, mid + 1, en);
    tree[temp][node] = tree[temp][node * 2] + tree[temp][(node * 2) + 1];
    return ;
}

void update(ll temp, ll node, ll st, ll en, ll l, ll r)
{
    if(lazy[temp][node] != 0){
        tree[temp][node] = (en - st + 1) - tree[temp][node];
        if(st != en){
            lazy[temp][node * 2] ^= lazy[temp][node];
            lazy[temp][(node * 2) + 1] ^= lazy[temp][node];
        }
        lazy[temp][node] = 0;
    }
    if(l > en || r < st) return ;
    if(l <= st && r >= en){
        tree[temp][node] = (en - st + 1) - tree[temp][node];
        if(st != en){
            lazy[temp][node * 2] ^= 1;
            lazy[temp][(node * 2) + 1] ^= 1;
        }
        return;
    }
    ll mid = (st + en) / 2;
    update(temp, node * 2, st, mid, l, r);
    update(temp, (node * 2) + 1, mid + 1, en, l, r);
    tree[temp][node] = tree[temp][node * 2] + tree[temp][(node * 2) + 1];
    return;
}

ll Q(ll temp, ll node, ll st, ll en, ll l, ll r)
{
    if(l > en || r < st) return 0;
    if(lazy[temp][node] != 0){
        tree[temp][node] = (en - st + 1) - tree[temp][node];
        if(st != en){
            lazy[temp][node * 2] ^= 1;
            lazy[temp][(node * 2) + 1] ^= 1;
        }
        lazy[temp][node] = 0;
    }
    if(st >= l && en <= r){
        return tree[temp][node];
    }
    ll mid = (st + en) / 2;
    return Q(temp, node * 2, st, mid, l, r) + Q(temp, (node * 2) + 1, mid + 1, en, l, r);
}

int main()
{
    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for(ll i = 0 ; i <= 20 ; i++)
        Build(i, 1, 1, n);
    cin >> q;
    while(q--){
        ll t, r, l, x;
        SF(t);
        if(t == 1){
            SF(l);
            SF(r);
            ll ans = 0;
            for(ll i = 0 ; i <= 20 ; i++){
                ans += (1 << i) * Q(i, 1, 1, n, l, r);
            }
            printf("%I64d\n", ans);
        }
        else{
            SF(l);
            SF(r);
            SF(x);
            for(ll i = 0 ; i <= 20 ; i++){
                if((1 << i) & x){
                    update(i, 1, 1, n, l, r);
                }
            }
        }
    }
    return 0;
}