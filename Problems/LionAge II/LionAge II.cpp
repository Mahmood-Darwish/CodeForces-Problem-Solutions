#include <iostream>
#include <map>

using namespace std;

int n, c, dp[107][27][107], MX = (1 << 25), k;
string s;
map < pair < char , char > , int > m;
char u, v;

int calc(char a, char b)
{
    if(m.find({a , b}) == m.end())
        return 0;
    return m[{a, b}];
}

int DP(int pos, int letter, int how_much)
{
    if(pos == n)return 0;
    int &cur = dp[pos][letter][how_much];
    if(cur != -MX)return cur;
    cur = DP(pos + 1, s[pos] - 'a', how_much) + (calc((char)(letter + 'a'), s[pos]) * (pos != 0));
    for(int i = 0 ; i < 26 ; i++){
        if(how_much > 0)
            cur = max(cur, DP(pos + 1, i, how_much - ((i + 'a') != s[pos])) + calc(letter + 'a', i + 'a'));
    }
    return cur;
}

int main()
{
    for(int i = 0 ; i <= 106 ; i++){
        for(int j = 0 ; j <= 26 ; j++){
            for(int t = 0 ; t <= 106 ; t++){
                dp[i][j][t] = -MX;
            }
        }
    }
    cin >> s >> k;
    cin >> n;
    while(n--)
    {
        cin >> u >> v >> c;
        m[{u,v}] = c;
    }
    n = s.size();
    cout << DP(0,s[0],k) << endl;
    return 0;
}