#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back

using namespace std;
typedef long long ll;

ll n,k,sum = 1;
vector < ll > V;
int main()
{
    cin >> n >> k;
    while(n % 2 == 0){
        n /= 2;
        V.pb(2);
    }
    for(int i = 3 ; i <= n ; i += 2){
        while(n % i == 0){
            n /= i;
            V.pb(i);
        }
    }
    if(n > 1)
        V.pb(n);
    if(k > V.size()){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0 ; i < k - 1; i++){
        cout << V[i] << ' ';
    }
    for(int i = k - 1 ; i < V.size() ; i++){
        sum *= V[i];
    }
    cout << sum << endl;
    return 0;
}