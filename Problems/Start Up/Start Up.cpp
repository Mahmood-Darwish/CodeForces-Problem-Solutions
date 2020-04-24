#include <iostream>

using namespace std;

bool a[] = {1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0};
string s;

int main()
{
    cin >> s;
    int n = s.size();
    for(int i = 0 ; i < n ; i++)
        if(s[i] != s[(n-1) - i] || !a[s[i]-'A'])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}