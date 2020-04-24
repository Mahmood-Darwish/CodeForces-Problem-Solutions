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

int n, a[1010];
int b[1010];
int ans;

int main(){

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        b[a[i]] = true;
    }
    for(int i = 1 ; i <= 100 ; i++){
        if(b[i]){
            ans++;
            for(int j = 0 ; j <= 100 ; j += i) b[j] = false;
        }
    }
    cout << ans << endl;
    return 0;
}