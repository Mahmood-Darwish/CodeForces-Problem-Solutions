#include <bits/stdc++.h>
#define F first
#define S second
#define ii pair < int , int >

using namespace std;

typedef long long ll;

ll GCD(ll a , ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b)
{
    return (a * b) / GCD(a,b);
}

ll n , m ;
bool sure;
char c;

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> c;
            if(c == 'M' || c == 'C' || c == 'Y')
                sure = true;
        }
    }
    if(sure)
        cout << "#Color";
    else cout << "#Black&White";
    return 0;
}