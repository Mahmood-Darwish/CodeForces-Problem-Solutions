#include <iostream>
#include <string.h>
#include <set>

using namespace std;

int n;
bool dp[10000][5];
set < string > sol;
string s;

void DP(int pos , string last)
{
    if(dp[pos][last.size()])return;
    if(pos < 4)return;
    string t = "";
    t += s[pos-1];
    t += s[pos];
    if(t != last && pos - 1 > 4)
    {
        sol.insert(t);
        DP(pos-2 , t);
    }
    t = "";
    t += s[pos-2];
    t += s[pos-1];
    t += s[pos];
    if(t != last && pos - 2 > 4)
    {
        sol.insert(t);
        DP(pos-3 , t);
    }
    dp[pos][last.size()] = true;
    return;
}

int main()
{
    cin >> s;
    n = s.size();
    s += "###";
    DP(n-1,"###");
    cout << sol.size() << '\n';
    for(set < string >::iterator it = sol.begin() ; it != sol.end() ; it++)
        cout << (*it) << '\n';
    return 0;
}