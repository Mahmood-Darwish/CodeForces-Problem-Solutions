#include <bits/stdc++.h>

using namespace std;
int a[1000000];
int n,d,m,fine,bones,i,i2;
int main()
{
    cin>>n>>d;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    sort(a,a+n);
    for(i2=0;i2<m;i2++){
        if(i2>i-1){
            fine+=d;
        }
        else{
        bones+=a[i2];
        }
    }
    cout<<bones-fine;
    return 0;
}