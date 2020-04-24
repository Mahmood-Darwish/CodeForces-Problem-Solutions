#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll n , d , ans , a[1000000];

int main()
{
    cin >> n >> d;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    ll j = 0;
    for(int i = 0 ; i < n ; i++)
    {
        while(a[i] - a[j] > d) j++;
        ans += (long long) ((i - j) * (i-j-1) / 2);
    }
    cout << ans << '\n';
    return 0;
}