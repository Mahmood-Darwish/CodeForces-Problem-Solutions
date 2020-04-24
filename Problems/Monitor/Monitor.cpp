#include <iostream>
#include <cmath>

using namespace std;

long long a , b , x , y;

long long GCD(long long m , long long n)
{
    if(!n)return m;
    return GCD(n,m%n);
}

int main()
{
    cin >> a >> b >> x >> y;
    int temp = GCD(x,y);
    x /= temp;
    y /= temp;
    cout << min(a/x,b/y) * x << " " << min(a/x,b/y) * y;
    return 0;
}