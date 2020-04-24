#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, x, y[100100], ans, mx, mn, mn2, temp;
vector < ll > V1, V2;

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%I64d", &x);
        mx = -1;
        mn = 1000005;
        for(int i = 1 ; i <= x ; i++){
            scanf("%I64d", &y[i]);
            if(y[i] > mx) mx = y[i];
            if(y[i] < mn) mn = y[i];
        }
        bool B = false;
        mn2 = 999999999;
        for(int i = 1 ; i <= x ; i++){
            if(y[i] < mn2)mn2 = y[i];
            if(y[i] > mn2){
                temp++;
                B = true;
                break;
            }
        }
        if(B) continue;
        V1.push_back(mx);
        V2.push_back(mn);
    }
    ans += temp * (2 * (n - temp));
    ans += temp * temp;
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    for(int i = 0 ; i < V2.size() ; i++){
        ans += V1.end() - upper_bound(V1.begin(), V1.end(), V2[i]);
    }
    cout << ans << endl;
    return 0;
}