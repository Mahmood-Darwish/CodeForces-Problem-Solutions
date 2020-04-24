#include <bits/stdc++.h>

using namespace std;

int  prime[10000000] , plindrom[10000000];
double p , q;

void cal_prime()
{
    for(int i = 2 ; i <= 2000 ; i++)
    {
        if(prime[i])
        {
            for(int j = i + i ; j <= 4000000 ; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for(int i = 1 ; i <= 4000000 ; i++)
        prime[i] += prime[i-1];
}

void cal_plindrom()
{
    for(int i = 1 ; i <= 1000001 * 2; i++)
    {
        int num = i;
        int n = num;
        int rev = 0;
        while (num > 0)
        {
            int dig = num % 10;
            rev = rev * 10 + dig;
            num = num / 10;
        }
        if(n == rev)
            plindrom[i]++;
    }
    for(int i = 1 ; i <= 1000001 * 2; i++)
        plindrom[i] += plindrom[i-1];
}

int main()
{
    int ans = -1;
    for(int i = 2 ; i <= 1000001 * 2; i++)
        prime[i] = 1;
    cin >> p >> q;
    double a = p / q + 0.0;
    cal_prime();
    cal_plindrom();
    int i = 1;
    while(i <= 2000001)
    {
        if(prime[i] <= floor(a * plindrom[i]))ans = i;
        i++;
    }
    if(ans == -1)cout << "Palindromic tree is better than splay tree";
    else cout << ans;
    return 0;
}