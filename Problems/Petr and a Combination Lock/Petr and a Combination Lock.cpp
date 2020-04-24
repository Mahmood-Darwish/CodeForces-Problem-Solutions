#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
ll a[20];

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < (1 << n) ; i++){
        ll sum = 0;
        for(int j = 0 ; j < 15 ; j++){
            if((1 << j) & i){
                sum += a[j];
                sum %= 360;
            }
            else{
                sum -= a[j];
                if(sum < 0)
                    sum += 360;
            }
        }
        if(sum == 0){
            cout << "YES" << endl;
            return 0;
        }

    }
    cout << "NO" << endl;
    return 0;
}