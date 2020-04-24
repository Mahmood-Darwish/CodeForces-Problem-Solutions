#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m, a[100], ans;
vector < ll > V1, V2;

void F(ll pos, ll sum, ll fin)
{
    sum %= m;
    if(pos > fin) {
        if(fin == (n / 2)){
            V1.push_back(sum);
        }
        else{
            V2.push_back(sum);
        }
        return;
    }
    F(pos + 1, (sum + a[pos]) % m, fin);
    F(pos + 1, sum % m, fin);
}

int main()
{
    cin >> n >> m;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
        a[i] %= m;
        ans = max(ans, a[i]);
    }
    if(n == 1){
        return cout << a[1] << endl, 0;
    }
    F(1, 0, n / 2);
    F((n / 2) + 1, 0, n);
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    for(ll i = 0 ; i < V1.size() ; i++){
        auto it = lower_bound(V2.begin(), V2.end(), m - V1[i]);
        it--;
        if(it != V2.end()){
            ans = max(ans, (V1[i] + (*(it))) % m);
        }
    }
    cout << ans << endl;
    return 0;
}