#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, q;
ll prefix[1000100];
ll a[1000100];
ll temp, k;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    cin >> q;
    for(int i = 1 ; i < n ; i++){
        temp += a[i] * i;
        prefix[i] += prefix[i - 1] + a[i];
    }
    while(q--){
        scanf("%I64d", &k);
        if(k == 1){
            printf("%I64d\n", temp);
            continue;
        }
        ll sz = k, res = 0;
        for(ll i = sz, t = 1 ; ; i += sz, t++){
            res += (prefix[min(i, n - 1)] - prefix[max((i - sz), 0LL)]) * t;
            sz *= k;
            if(i >= n)
                break;
        }
        printf("%I64d\n", res);
    }
    return 0;
}