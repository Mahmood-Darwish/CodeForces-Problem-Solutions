#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MEM(i,n) memset(i,n,sizeof(i))

using namespace std;
typedef long long ll;

ll GCD(ll a , ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b)
{
    return ( a * b ) / GCD(a,b);
}


ll n;
bool sure;
ll a[600][600] , b[600][600] , c[600][600];
ll sum1 , sum2 , temp1 , temp2 , ans , num;

int main()
{
    cin >> n;
    if(n == 1)
    {
        cin >> num;
        if(num == 0)
            cout << 1;
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0)
            {
                temp1 = i;
                temp2 = j;
            }
        }
    for(int i = 1 ; i <= n ; i++)
    {
        b[i][1] = a[i][1];
        for(int j = 2 ; j <= n ; j++)
        {
            b[i][j] += b[i][j-1] + a[i][j];
        }
    }
    if(temp1 != n)
        a[temp1][temp2] = abs(b[temp1][n] - b[temp1+1][n]);
    else a[temp1][temp2] = abs(b[temp1][n] - b[temp1-1][n]);
    ans = a[temp1][temp2];
    b[temp1][n] += ans;
    for(int i = 1 ; i<= n ; i++)
    {
        c[1][i] = a[1][i];
        for(int j = 2 ; j <= n ; j++)
        {
            c[j][i] = c[j-1][i] + a[j][i];
        }
    }
    for(int i = 1 ; i <= n - 1; i++)
    {
        if(b[i][n] != b[i+1][n] || c[n][i] != c[n][i+1])
        {
            sure = true;
        }
    }
    if(sure)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        sum1 += a[i][i];
    }
    if(sum1 != b[temp1][n])
    {
        cout << -1;
        return 0;
    }
    for(int i = 1 , j = n; i <= n ; j-- , i++)
    {
        sum2 += a[i][j];
    }
    if(sum2 != sum1)
        cout << -1;
    else
    {
        if(ans > 0)
            cout << ans;
        else cout << -1;
    }
    return 0;
}