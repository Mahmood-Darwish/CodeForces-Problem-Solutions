#include <iostream>
#include <string.h>

using namespace std;

int n, t, dp[33][13][13][13][13];

int DP(int pos, int last, int before_last, int how_much, int hump)
{
    if(pos == n && how_much == 0 && hump == 0)return 1;
    if(pos == n)return 0;
    int &cur = dp[pos][last][before_last][how_much][hump];
    if(cur != -1)return cur;
    cur = 0;
    for(int i = 1 ; i <= 4 ; i++)
    {
        if(i == last)continue;
        if(pos > 1)
        {
            if(i > last && before_last > last && how_much)
            {
                cur += DP(pos + 1, i, last, how_much - 1, hump);
                continue;
            }
            if(i > last && before_last > last)
                continue;
            if(i < last && last > before_last && hump)
            {
                cur += DP(pos + 1, i, last, how_much, hump - 1);
                continue;
            }
            if(i < last && last > before_last)
                continue;
        }
        cur += DP(pos + 1, i, last, how_much, hump);
    }
    return cur;
}

int main()
{
    cin >> n >> t;
    memset(dp,-1,sizeof(dp));
    cout << DP(0, 10, 10, t - 1, t) << endl;
    return 0;
}