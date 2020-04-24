#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, mx, a[1000100], ans;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    sort(a, a + n);
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 1) continue;
        if(i && a[i] == a[i - 1]) continue;
        for(int j = a[i] * 2 ; j <= mx ; j += a[i]){
            int low = 0, high = n, temp = 0;
            while(low <= high){
                int mid = (low + high) / 2;
                if(a[mid] >= j){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                    temp = mid;
                }
            }
            ans = max(ans, a[temp] % a[i]);
        }
        if(a[n - 1] > a[i]) ans = max(ans, a[n - 1] % a[i]);
    }
    cout << ans << endl;
    return 0;
}