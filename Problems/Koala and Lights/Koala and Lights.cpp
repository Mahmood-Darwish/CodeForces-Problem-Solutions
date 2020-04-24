#include <bits/stdc++.h>

#define F first
#define S second
#define SF(x) fastscan(x)

using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

string s;
int n, a[1010];
int b[1010];
int ans;
int c[110][10100];

int main(){

    cin >> n;
    cin >> s;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] >> b[i];
        for(int j = 0 ; j < b[i] ; j++){
            c[i][j] = s[i - 1] - '0';
        }
        int temp = s[i - 1] - '0';
        c[i][b[i]] = 1 - temp;
        temp = 1 - temp;
        for(int j = b[i] + 1 ; j <= 10000 ; j++){
            if(((j - b[i]) % a[i]) == 0) temp = 1 - temp;
            c[i][j] = temp;
        }
    }
    for(int i = 0 ; i <= 10000 ; i++){
        int sum = 0;
        for(int j = 1 ; j <= n ; j++){
            if(c[j][i] == 1) sum++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}