#include <iostream>

using namespace std;

int n , k , ans , a , b , j;
string s;

int main()
{
    cin >> n >> k;
    cin >> s;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == 'a')a++;
        if(s[i] == 'b')b++;
        if(a > k && b > k)
        {
            for( ; j <= i ; j++)
            {
                if(s[j] == 'a')a--;
                else b--;
                if(a <= k || b <= k)
                {
                    j++;
                    break;
                }
            }
        }
        else ans = max(ans , (i - j) + 1);
    }
    cout << ans;
    return 0;
}