#include <bits/stdc++.h>
using namespace std;
int n,sum;
int a[100000];
int b[100000];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    b[0]=a[0];
    for(int i=1;i<n-1;i++){
        b[i]=b[i-1]+a[i];
        if(b[i]>a[i+1]){
            a[i+1]=0;
            sum++;
        }
    }
    cout<<n-sum;
    return 0;
}