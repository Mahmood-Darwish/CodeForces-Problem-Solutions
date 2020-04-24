#include <bits/stdc++.h>

using namespace std;
int n,i,i2,i3,sum1,m,minn,res;
int a[10000];
int b[10000];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a,a+m);
    for(int i=0;i+n-1<=m;i++,i2++){
     b[i]=a[i+n-1]-a[i];
    }
    res=b[0];
    for(int i=0;i<i2-1;i++){
        res=min(res,b[i]);
    }
    cout<<res;
    return 0;
}