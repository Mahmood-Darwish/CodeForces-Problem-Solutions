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

ll n ,side , up , l ,r , u ,d;
string s;

int main()
{
    cin >> s;
    n = s.size();
    if(n % 2)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == 'L')
            l++;
        if(s[i] == 'R')
            r++;
        if(s[i] == 'U')
            u++;
        if(s[i] == 'D')
            d++;
    }
    double num = (double)(abs(l - r) / 2.0) + (double)(abs(u - d) / 2.0);
    cout << ceil(num);
    return 0;
}