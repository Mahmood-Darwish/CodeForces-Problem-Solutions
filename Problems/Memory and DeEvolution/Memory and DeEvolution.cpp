#include <bits/stdc++.h>
#define F first
#define S second
#define ii pair < long long , long long >

using namespace std;
typedef long long ll;

ll GCD(ll a,ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b)
{
    return (a * b) / GCD(a ,b);
}

ll x , y , a[5] , sum;

bool check()
{
    if(a[0] == a[1] && a[1] == a[2] && a[2] == x)
        return true;
    return false;
}

int main()
{
    cin >> x >> y;
    a[0] = a[1] = a[2] = y;
    while(!check())
    {
        sort(a,a+3);
        a[0] = min(x , a[1] + a[2] - 1);
        sum++;
    }
    cout << sum;
    return 0;
}