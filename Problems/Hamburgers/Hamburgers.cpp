#include <iostream>

using namespace std;

typedef long long ll;

ll needed_cheese , needed_sausge , needed_bread , owned_cheese , owned_bread , owned_sausge , price_bread , price_sausge , price_cheese , have_bread , have_sausge , have_cheese;
ll r;
string s;
ll mid;
ll ans;

bool check(ll num)
{
    return (((price_bread * num) * (needed_bread)) + ((price_cheese * num) * (needed_cheese )) + ((price_sausge * num) * (needed_sausge)) <= r);
}


int main()
{
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == 'B')
            needed_bread++;
        if(s[i] == 'S')
            needed_sausge++;
        if(s[i] == 'C')
            needed_cheese++;
    }
    cin >> have_bread >> have_sausge >> have_cheese;
    cin >> price_bread >> price_sausge >> price_cheese;
    cin >> r;
    while(have_bread * needed_bread || have_cheese * needed_cheese || have_sausge * needed_sausge)
    {
        if(have_bread < needed_bread)
        {
            r -= (needed_bread - have_bread) * price_bread ;
            if(r < 0)
            {
                cout << ans ;
                return 0;
            }
            have_bread = needed_bread;
        }

        if(have_cheese < needed_cheese)
        {
            r -= (needed_cheese - have_cheese) * price_cheese ;
            if(r < 0)
            {
                cout << ans ;
                return 0;
            }
            have_cheese = needed_cheese;
        }

        if(have_sausge < needed_sausge)
        {
            r -= (needed_sausge - have_sausge) * price_sausge;
            if(r < 0)
            {
                cout << ans ;
                return 0;
            }
            have_sausge = needed_sausge;
        }
        have_bread -= needed_bread;
        have_sausge -= needed_sausge;
        have_cheese -= needed_cheese;
        ans++;
    }
    ll low = 0;
    ll high = 10000000000000;
    ll mid;
    while(high - low > 1)
    {
        mid = (low + high) / 2;
        if(check(mid))
            low = mid;
        else high = mid;
    }
    mid = (low + high) / 2;
    if(check(mid))
        ans += mid;
    else ans += low;
    ll num = low;
    cout << ans;
    return 0;
}