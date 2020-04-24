#include <iostream>

using namespace std;

unsigned long long n , dp[500000][5];
string a[500000];
string b[500000];
unsigned long long arr[500000];

string rev(string word)
{
    string s = "";
    for(int i = word.size() - 1 ; i >= 0 ;i--)
        s.push_back(word[i]);
    return s;
}




int main()
{
    cin >> n;
    for(int i = 0 ;  i <= n ; i++)
    {
        dp[i][0] = 9999999999999999;
        dp[i][1] = 9999999999999999;
    }
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
        b[i] = rev(a[i]);
    }
    dp[0][0] = 0;
    dp[0][1] = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] >= a[i-1])
            dp[i][0] = min(dp[i-1][0],dp[i][0]);
        if(b[i] >= a[i-1])
            dp[i][1] = min(dp[i-1][0] + arr[i] , dp[i][1]);
        if(a[i] >= b[i-1])
            dp[i][0] = min(dp[i-1][1] , dp[i][0]);
        if(b[i] >= b[i-1])
            dp[i][1] = min(dp[i-1][1] + arr[i] , dp[i][1]);
    }
    unsigned long long m = min(dp[n-1][0] , dp[n-1][1]);
    if(m == 9999999999999999)
        cout << -1 << '\n';
    else cout << m << '\n';
    return 0;
}
/*
4

0 0 8 6

bi

qp

bt

ya
*/