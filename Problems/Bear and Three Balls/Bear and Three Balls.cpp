#include <bits/stdc++.h>

using namespace std;
int n,a[10000];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int i2=0;i2<n;i2++){
            for(int i3=0;i3<n;i3++){
                if(a[i]+1==a[i2]&&a[i2]+1==a[i3]){
                    cout<<"Yes";
                    return 0;
                }
            }
        }
    }
    cout<<"No";
    return 0;
}