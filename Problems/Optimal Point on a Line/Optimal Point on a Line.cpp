#include <iostream>
#include <algorithm>

using namespace std;

int a[1000000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);
    if(n%2)
    {
        cout << a[n/2];
        return 0;
    }
    else
    {
        cout << a[(n/2)-1];
        return 0;
    }
    return 0;
}