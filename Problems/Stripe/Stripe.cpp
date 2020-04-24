#include <iostream>

using namespace std;

int n , sum , a[1000000];

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 1 ; i < n ; i++)
        a[i] += a[i-1];
    for(int i = 0 ; i < n - 1; i++)
        if(a[n-1] - a[i] == a[i])
            sum++;
    cout << sum;
    return 0;
}