#include <iostream>

using namespace std;

long long sweets, cost, n, T, ans, mn = (1LL << 60);
long long a[200100];

void calc()
{
    sweets = 0, cost = 0;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] <= T - cost){
            sweets++;
            cost += a[i];
        }
    }
    return;
}

int main()
{
    cin >> n >> T;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    while(T >= mn){
        calc();
        if(!cost) break;
        ans += sweets * (T / cost);
        T %= cost;
    }
    cout << ans << endl;
    return 0;
}