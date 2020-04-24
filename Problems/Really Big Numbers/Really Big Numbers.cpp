#include <iostream>

using namespace std;
typedef long long ll;

ll s;

bool check(ll x)
{
    ll temp = x, sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return (temp - sum >= s);
}

int main()
{
    ll n, ans;
    cin >> n >> s;
    ans = n + 1;
    ll low = 0, high = n;
    while(low <= high){
        ll mid = (high + low) / 2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << n - ans + 1 << endl;
    return 0;
}