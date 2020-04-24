#include <iostream>

using namespace std;

long long n , m , k;

bool check(long long mid)
{
    long long sum = 0;
    for(int i = 1 ; i <= n ; i++)
        sum += min(m , (long long)(mid-1)/i);
    return sum < k;
}

int main()
{
    cin >> n >> m >> k;
    long long low = 1 , high = (m * n) + 1 , mid;
    while(high - low > 1)
    {
        mid = ( low + high ) / 2;
        if(check(mid))
            low = mid;
        else high = mid;
    }
    mid = ( low + high ) / 2;
    cout << mid;
    return 0;
}