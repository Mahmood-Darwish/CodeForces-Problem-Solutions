#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MEM(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long ll;

set < string > m;

string shift(string s)
{
    string temp = "";
    temp += s[s.size() - 1];
    temp += s;
    temp.pop_back();
    return temp;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    while(n--){
        s = shift(s);
        m.insert(s);
    }
    cout << m.size() << endl;
    return 0;
}