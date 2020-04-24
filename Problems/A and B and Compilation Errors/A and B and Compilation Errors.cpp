#include <bits/stdc++.h>

using namespace std;
int a[1000000],b[1000000],c[1000000];
int num,n,i,sure,sum1,sum2,sum3;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum1+=a[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>b[i];
        sum2+=b[i];
    }
    cout<<sum1-sum2<<endl;
    for(int i=0;i<n-2;i++){
            cin>>c[i];
            sum3+=c[i];
    }
    cout<<sum2-sum3;

    return 0;
}