#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << a[(n - k) + 1] << endl;
}