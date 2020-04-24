#include <iostream>
#include <algorithm>

using namespace std;

int n, x, a[1000000],b[1000000], ans;

int main()
{
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> b[i];
    }
    cout << 1 << ' ';
    sort(a, a + n);
    sort(b, b + n);
    int l = 0, r = n - 1;
    while(l < n && r >= 0){
        if(a[l] + b[r] >= x){
            ans++;
            l++;
            r--;
        }
        else
            l++;
    }
    cout << ans << endl;
    return 0;
}