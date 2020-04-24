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

ll n , a[1000000] , temp , b[1000000] , sure;

int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i++)
        scanf("%I64d",&a[i]);
    temp = a[n];
    b[n] = a[n];
    for(int i = n - 1 ; i > 0 ; i--)
    {
        if(sure)
        {
            b[i] = a[i] - temp;
            temp += b[i];
        }
        else
        {
            b[i] = a[i] + temp;
            temp -= b[i];
        }
        sure = 1 - sure;
    }
    for(int i = 1 ; i <= n ; i++)
        printf("%I64d ",b[i]);
    return 0;
}