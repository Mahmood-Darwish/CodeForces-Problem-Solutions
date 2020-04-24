#include <bits/stdc++.h>
#define MEM(a,b) memset(a,b,sizeof(a))
#define ii pair < int , int >
#define F first
#define S second

using namespace std;
typedef long long ll;

ll GCD(ll a , ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b){
    return (a * b) / GCD(a , b);
}

ll a[1000] , n;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    if(a[n-1] == 15){cout << "DOWN";return 0;}
    if(a[n-1] == 0){cout << "UP";return 0;}
    if(n == 1){cout << -1;return 0;}
    if(a[n-1] > a[n-2] && a[n-1] != 15)cout << "UP";
    else cout << "DOWN";
    return 0;
}