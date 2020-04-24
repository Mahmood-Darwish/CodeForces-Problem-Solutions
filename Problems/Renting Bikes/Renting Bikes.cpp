#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n,m,money,a[1000000],b[10000000],pos2,ans,sum;

bool check(int x)
{
    long long sum = 0,temp = money;
    vector < long long > V, boys;
    if(x > m || x > n)return false;
    for(int i = 0 ; i < x ; i++){
        V.push_back(b[i]);
        boys.push_back(a[i]);
    }
    reverse(V.begin(),V.end());
    for(int i = 0 ; i < x ; i++)
    {
        if(boys[i] >= V[i])
            sum += V[i];
        else{
            if(boys[i] + temp >= V[i])
            {
                sum += boys[i];
                temp -= (V[i] - boys[i]);
            }
            else return false;
        }
    }
    return true;
}

long long calc(int x)
{
    long long sum = 0,temp = money;
    vector < long long > V, boys;
    for(int i = 0 ; i < x ; i++){
        V.push_back(b[i]);
        boys.push_back(a[i]);
    }
    reverse(V.begin(),V.end());
    for(int i = 0 ; i < x ; i++)
    {
        if(boys[i] >= V[i])
            sum += V[i];
        else{
            if(boys[i] + temp >= V[i])
            {
                sum += boys[i];
                temp -= (V[i] - boys[i]);
            }

        }
    }
    return max(0LL,(sum - max(temp,0LL)));
}

int main()
{
    cin >> n >> m >> money;
    for(int i = 0 ; i < n; i++)
        cin >> a[i];
    for(int i = 0 ;i < m ; i++)
        cin >> b[i];
    sort(a,a+n);
    reverse(a,a+n);
    sort(b,b+m);
    long long low = 0, high = n, mid;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if(check(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << ans << ' ' << calc(ans) << endl;
    return 0;
}