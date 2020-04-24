#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <cmath>

#define SF(n) scanf("%I64d",&n)

using namespace std;
typedef long long ll;

ll n, m, w, a[1001000], V[1001000];

bool check(ll num)
{
    memset(a,0,sizeof(a));
    ll budget = 0LL, sum = 0LL;
    for(int i = 0 ; i < n ; i++){
        sum -= a[i];
        if(V[i] + sum < num){
            ll t = (num - (V[i] + sum));
            sum += t;
            budget += t;
            if(budget > m)
                return false;
            a[(i + w)] += t;
        }
    }
    if(budget <= m)
        return true;
    else return false;
}

int main()
{
    SF(n);
    SF(m);
    SF(w);
    for(int i = 0 ; i < n ; i++){
        SF(V[i]);
    }
    ll high = (1e9 + 1e5 + 1) * 1LL, low = 0LL;
    ll ans = 0LL;
    while(low < high)
    {
        ll mid = (low + high) / 2;
        if(check(mid)){
            low = mid + 1;
            ans = mid;
        }
        else high = mid;
    }
    printf("%I64d\n",ans);
    return 0;
}