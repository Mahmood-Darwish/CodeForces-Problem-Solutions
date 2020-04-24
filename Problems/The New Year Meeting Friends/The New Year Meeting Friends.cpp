#include <iostream>
#include <algorithm>
using namespace std;

int a[5];

int main()
{
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    int temp = (a[1] - a[0]) + (a[2] - a[1]);
    cout << temp << endl;
    return 0;
}