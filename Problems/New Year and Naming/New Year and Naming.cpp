#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, m, q, y;
string a[1000];
string b[1000];

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> b[i];
    }
    cin >> q;
    while(q--){
        cin >> y;
        if(y % n == 0) cout << a[n];
        else cout << a[y % n];
        if(y % m == 0) cout << b[m] << endl;
        else cout << b[y % m] << endl;
    }
    return 0;
}