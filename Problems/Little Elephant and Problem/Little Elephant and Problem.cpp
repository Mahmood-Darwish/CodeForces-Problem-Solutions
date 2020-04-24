#include <iostream>
#include <algorithm>

using namespace std;

long long n , ans;
int a[10000000];
int b[10000000];

int main()
{
    cin >> n;
    for( int  i = 0 ; i < n ;  i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != b[i])
            ans++;
    }
    if(ans > 2)
        cout << "NO\n";
    else cout << "YES\n";
    return 0;
}