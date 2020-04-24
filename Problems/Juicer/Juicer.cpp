#include <bits/stdc++.h>
#define S second
#define F first
#define pb push_back

using namespace std;
typedef long long ll;

ll n , b , d , temp , num , ans;
ll a[1000000];

int main()
{
    cin >> n >> b >> d;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] > b)continue;
        temp += a[i];
        if(temp > d)
        {
            ans++;
            temp = 0;
        }
    }
    cout << ans;
    return 0;
}