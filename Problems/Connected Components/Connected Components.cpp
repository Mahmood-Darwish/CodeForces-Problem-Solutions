#include <iostream>
#include <stdio.h>

using namespace std;

short n, m, l, r, x[10002], y[10002], q;

struct DSU{
    short par[502] = {0}, comp;
    short findd(short u)
    {
        if(!par[u])
            return u;
        return par[u] = findd(par[u]);
    }
    void mergee(short x, short y)
    {
        x = findd(x);
        y = findd(y);
        if(x != y){
            par[y] = x;
            comp++;
        }
        return;
    }
}leftt[10002], rightt[10002], ans;

int main()
{
    scanf("%hd %hd", &n, &m);
    for(short i = 1 ; i <= m ; i++){
        scanf("%hd %hd", &x[i], &y[i]);
        leftt[i] = leftt[i - 1];
        leftt[i].mergee(x[i], y[i]);
    }
    for(int i = m ; i >= 1 ; i--){
        rightt[i] = rightt[i + 1];
        rightt[i].mergee(x[i], y[i]);
    }
    scanf("%hd", &q);
    while(q--){
        scanf("%hd %hd", &l, &r);
        ans = leftt[l - 1];
        for(int i = 1 ; i <= n ; i++){
            if(rightt[r + 1].par[i]) ans.mergee(i, rightt[r + 1].par[i]);
        }
        printf("%hd\n", n - ans.comp);
    }
    return 0;
}