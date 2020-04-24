#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000000];
int main()
{
    ll n , c;
    cin >> n >> c;
    ll res = 1;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i+1<n; i++)
    {
        if(a[i+1] - a[i] <= c)
            res++;
        else res=1;
    }
    cout << res << endl;
    return 0;
}