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
char a[1000][100];

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
            cin >> a[i][j];
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
            if(a[i][j] == 'O' && a[i][j+1] == 'O')
            {
                a[i][j] = '+';
                a[i][j+1] = '+';
                sure = true;
                break;
            }
        if(sure)break;
    }
    if(sure)
    {
        cout << "YES" << '\n';
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < 5 ; j++)
                cout << a[i][j];
            cout << '\n';
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}