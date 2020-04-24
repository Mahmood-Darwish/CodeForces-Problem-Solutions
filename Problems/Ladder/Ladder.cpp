#include <iostream>

using namespace std;

int n , m , a[1000000] , b[1000000] , c[1000000];

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    b[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(a[i] > a[i-1])
            b[i] = i;
        else b[i] = b[i-1];
    }
    c[n] = n;
    for(int i = n - 1 ; i > 0 ; i--)
    {
        if(a[i] > a[i+1])
            c[i] = i;
        else c[i] = c[i+1];
    }
    while(m--)
    {
        int l , r;
        scanf("%d%d",&l,&r);
        if(l == r || r - l == 1)
        {
            printf("Yes\n");
            continue;
        }
        if(c[l] >= b[r])
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}