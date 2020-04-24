#include <iostream>

using namespace std;

int n, q, t, k, d, ans;
int a[10000];

int main()
{
    cin >> n >> q;
    while(q--){
        int temp;
        ans = k = t = d = temp = 0;
        cin >> t >> k >> d;
        for(int i = 1 ; i <= n ; i++){
            if(a[i] <= t)
                temp++;
        }
        if(temp < k){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1 ; i <= n && k > 0 ; i++){
            if(k <= 0)
                break;
            if(a[i] <= t && k){
                ans += i;
                a[i] = t + d;
                k--;
                if(k <= 0)
                    break;
            }
            if(k <= 0)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}