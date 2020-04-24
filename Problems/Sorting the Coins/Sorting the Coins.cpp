#include <iostream>
#include <stdio.h>

using namespace std;

int n, b[300100];
int a[300100], sum, p;

void fix()
{
    while(a[p - 1] == 1) p--;
}

int main()
{
    cin >> n;
    cout << 1 << ' ';
    p = n + 1;
    for(int i = 0 ; i < n ; i++){
        int x;
        scanf("%d", &x);
        a[x] = 1;
        sum++;
        fix();
        if(p == n + 1) printf("%d ", sum + 1);
        else printf("%d ", sum - ((n - p) + 1) + 1);
    }
    return 0;
}