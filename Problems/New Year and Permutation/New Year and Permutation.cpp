#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, m, temp, ans;
ll F[250200];

int main()
{
    cin >> n >> m;
    F[0] = 1;
    F[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        F[i] = F[i - 1] * i;
        F[i] %= m;
    }
    for(int i = 1 ; i <= n ; i++){
        ans += ((F[i] * F[n - (i - 1)]) % m);
        ans %= m;
    }
    temp = ans;
    for(int i = 1 ; i <= n ; i++){
        temp -= ((F[i] * F[n - (i - 1)]) % m);
        temp += m;
        temp %= m;
        ans += temp;
        ans %= m;
    }
    cout << ans << endl;
    return 0;
}