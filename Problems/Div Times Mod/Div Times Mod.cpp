#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sf(x) scanf("%I64d", &x)

using namespace std;
typedef long long ll;

ll n, k, x, ans = (1LL << 60);

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            for(int j = i * k ; j < (i + 1) * k ; j++){
                x = j;
                if((n / i) == (x % k)) ans = min(ans, x);
            }
            for(int j = (n / i) * k ; j < ((n / i) + 1) * k ; j++){
                x = j;
                if(i == (x % k)) ans = min(ans, x);
            }

        }

    }
    cout << ans << endl;
    return 0;
}