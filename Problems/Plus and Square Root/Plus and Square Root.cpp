#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
ll arr[1000000];

int main(){
    ll n , res = 0;
    cin >> n;
    cout << 2 << endl;
    for(ll i=2;i<=n;i++){
        res = ((i) * (i+1) * (i+1)) - i + 1;
        printf("%I64d\n",res);
    }
    return 0;
}