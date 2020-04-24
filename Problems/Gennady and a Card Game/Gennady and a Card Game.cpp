#include <bits/stdc++.h>

using namespace std;

string s, s1[10];

int main()
{
    cin >> s;
    for(int i = 1 ; i <= 5 ; i++) cin >> s1[i];
    for(int i = 1 ; i <= 5 ; i++){
        if(s[0] == s1[i][0] || s[1] == s1[i][1]){cout << "YES" << endl; return 0;}

    }
    cout << "NO" << endl;
    return 0;
}