#include <iostream>

using namespace std;

string s1 , s2;
int sum  , n , m;

bool check(int num)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(s1[i] != s2[i % num])
            return false;
    }
    for(int i = 0 ; i < m ; i++)
    {
        if(s2[i] != s1[i % num])
            return false;
    }
    return true;
}

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    for(int i = 1 ; i <= min(n,m) ; i++)
    {
        if(n % i == 0 && m % i == 0 && check(i))
            sum++;
    }
    cout << sum;
    return 0;
}