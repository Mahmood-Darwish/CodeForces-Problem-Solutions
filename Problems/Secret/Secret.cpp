#include <iostream>

using namespace std;

int n , k , a[1000007], num = 1;

int main()
{
    cin >> n >> k;
    if(n / k < 3){
        cout << -1 << endl;
        return 0;
    }
    a[0] = k;
    for(int i = 1 ; i <= n ; i += 6){
        if(num < k){
            a[i] = num;a[i + 1] = num;a[i + 2] = num + 1;a[i + 3] = num;a[i + 4] = num + 1;a[i + 5] = num + 1;
            num += 2;
        }
        else{
            a[i] = k;a[i + 1] = k;a[i + 2] = k;a[i + 3] = k;a[i + 4] = k ;a[i + 5] = k;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
    return 0;
}