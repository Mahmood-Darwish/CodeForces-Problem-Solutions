#include <bits/stdc++.h>
#define S second
#define F first
#define pb push_back

using namespace std;
typedef long long ll;

string s;
ll num = -1, num1 = -1;

int main()
{
    cin >> s;
    num = s.size() - 1;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] != 'a')break;
        else num1 = i;
    }
    num = num1 + 1;
    for(int i = num ; i < s.size() ; i++)
    {
        if(s[i] != 'a')num = i;
        else break;
    }
    if(num1 == s.size() - 1 && num == s.size())
    {
        for(int i = 0 ; i < s.size() -1 ; i++)
            cout << 'a';
        cout << 'z';
        return 0;
    }
    for(int i = 0 ; i <= num1 ; i++)
    {
        cout << s[i];
    }
    for(int i = num1 + 1 ; i <= num ; i++)
    {
        cout << (char)(s[i] - 1);
    }
    for(int i = num + 1; i < s.size() ; i++)
        cout << s[i];
    return 0;
}