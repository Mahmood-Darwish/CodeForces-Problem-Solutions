#include <iostream>

using namespace std;

int n, sum, mn = 99999999, mx = -999999999;
int a[100100];

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(a[i] >= 0){
            sum += a[i];
            if(a[i] % 2){
                mn = min(mn, a[i]);
            }
        }
        else{
            if((-a[i]) % 2){
                mx = max(mx, a[i]);
            }
        }
    }
    if(sum % 2){
        cout << sum << endl;
    }
    else{
        cout << max(sum + mx, sum - mn) << endl;
    }
    return 0;
}