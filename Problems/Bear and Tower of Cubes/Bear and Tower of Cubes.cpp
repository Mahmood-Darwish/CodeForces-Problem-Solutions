#include <iostream>

using namespace std;
typedef long long ll;

pair <ll,ll> ans;

void DP(ll m , ll sub , ll vol)
{
    if(!m)
    {
        ans = max(ans , {sub , vol});
        return;
    }
    ll x = 1;
    while((x+1)*(x+1)*(x+1) <= m)x++;
    DP(m - (x*x*x) , sub + 1 , vol + (x*x*x));
    if(x - 1 >= 0)
        DP((x*x*x) - 1 - ((x-1)*(x-1)*(x-1))  , sub + 1 , vol + ((x-1)*(x-1)*(x-1)));
    return;
}

int main()
{
    ll m;
    cin >> m;
    DP(m ,0 ,0);
    cout << ans.first << " " << ans.second;
    return 0;
}