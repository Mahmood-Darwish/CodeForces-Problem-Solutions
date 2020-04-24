#include <iostream>
#include <cmath>

using namespace std;

unsigned long long n , a , b , p , q , ans1 , ans2 , ans3;

long long GCD(long long y , long long x)
{
    if(!x)return y;
    else return GCD(x,y%x);
}


long long LCM(long long y , long long x)
{
    return (x * y) / (GCD(x,y));
}

int main()
{
    cin >> n >> a >> b >> p >> q;
    if(p >= q)
    {
        ans1 = floor(n/a) * p;
        ans2 = (floor(n/b) - floor(n/LCM(a,b))) * q;
        ans3 = (ans1 + ans2);
        cout << ans3;
        return 0;
    }
    if(p < q)
    {
        ans1 = floor(n/b) * q;
        ans2 = (floor(n/a) - floor(n/LCM(a,b))) * p;
        ans3 = ans1 + ans2;
        cout << ans3;
        return 0;
    }
    return 0;
}