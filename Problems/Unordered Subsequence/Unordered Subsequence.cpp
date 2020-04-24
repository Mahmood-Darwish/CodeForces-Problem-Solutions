#include <bits/stdc++.h>

using namespace std;

int a[1000000] , idx_minn , idx_maxx , minn = 99999999999 , maxx = -999999999 , n;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] < maxx && idx_minn < idx_maxx)
        {
            cout << 3 << '\n' << idx_minn << " "<< idx_maxx << " "<<i+1;
            return 0;
        }
        if(a[i] > minn && idx_minn > idx_maxx)
        {
            cout << 3 << '\n' << idx_maxx << " "<< idx_minn << " "<<i+1;
            return 0;
        }
        if(a[i] < minn)
        {
            minn = a[i];
            idx_minn = i + 1;
        }
        if(a[i] > maxx)
        {
            maxx = a[i];
            idx_maxx = i + 1;
        }
    }
    cout << 0;
    return 0;
}