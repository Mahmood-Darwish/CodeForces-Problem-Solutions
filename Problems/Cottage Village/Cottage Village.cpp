#include <iostream>
#include <algorithm>

using namespace std;

long long n , t , sum;
pair < double , double > a[1000000];

int main()
{
    cin >> n >> t;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i].first >> a[i].second;
        a[i].second /= 2;
    }
    sort(a,a+n);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if((a[i+1].first - a[i+1].second) - (a[i].first + a[i].second) > t)sum += 2;
        else if((a[i+1].first - a[i+1].second) - (a[i].first + a[i].second) == t)sum++;
    }
    cout << sum + 2;
    return 0;
}