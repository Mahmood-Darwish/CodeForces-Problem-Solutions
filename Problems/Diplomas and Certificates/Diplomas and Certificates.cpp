#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    cout << (n / 2) / (k + 1) << ' ' << ((n / 2) / (k + 1)) * k << ' ' << n - (((n / 2) / (k + 1)) * (k + 1)) << endl;
    return 0;
}