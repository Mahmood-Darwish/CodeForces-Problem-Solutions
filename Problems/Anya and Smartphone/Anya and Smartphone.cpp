#include <iostream>
#include <cmath>
#include <map>

using namespace std;

long long n , m , k , a[100000] , q , sum;
map < int , int > mym;

int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        mym[a[i]] = i;
    }
    while(m--)
    {
        cin >> q;
        sum++;
        sum += mym[q] / k;
        if(mym[q] == 0)continue;
        swap(a[mym[q]] , a[mym[q]-1]);
        mym[a[mym[q]]] = mym[q];
        mym[a[mym[q]-1]] = mym[q]-1;
    }
    cout << sum;
    return 0;
}