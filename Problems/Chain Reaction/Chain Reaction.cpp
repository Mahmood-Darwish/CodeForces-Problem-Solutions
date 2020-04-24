#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int a[1000100];
int dp[1000100];

int main()
{
    int n , ans = -1 , num1 , num2;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> num1 >> num2;
        a[num1] = num2;
    }
    for(int i = 0 ; i <= 1000100; i++)
    {
        if(i - a[i] > 0)
            dp[i] = dp[i - a[i] - 1] + (a[i] != 0);
        else dp[i] = (a[i] != 0);
        ans = max(ans , dp[i]);
    }
    cout << n - ans;
    return 0;
}