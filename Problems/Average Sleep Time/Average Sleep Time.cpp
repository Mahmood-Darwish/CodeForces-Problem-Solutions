#include <bits/stdc++.h>

using namespace std;

long double n, k;
int a[200100];
long double sum, ans;

int main()
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < k ; i++){
        sum += a[i];
    }
    ans += sum;
    long double temp = 1.0;
    for(int i = k ; i < n ; i++){
        sum -= a[(int)(i - k)];
        sum += a[i];
        ans += sum;
        temp++;
    }
    cout << setprecision(12) << fixed << ((ans + 0.0) / (temp + 0.0)) << endl;
    return 0;
}