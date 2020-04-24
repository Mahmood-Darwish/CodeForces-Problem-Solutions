#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sf(x) scanf("%I64d", &x)

using namespace std;
typedef long long ll;

string s, s1, temp;

int main()
{
    cin >> s;
    int n = s.size();
    int m = n / 2, k = 0;
    if(n % 2) m++;
    m--;
    s1 = s[m];
    k++;
    while(m + k < n || m - k >= 0){
        if(m + k < n)
            s1 += s[m + k];
        if(m - k >= 0){
            s1 += s[m - k];
        }
        k++;
    }
    cout << s1 << endl;
    return 0;
}