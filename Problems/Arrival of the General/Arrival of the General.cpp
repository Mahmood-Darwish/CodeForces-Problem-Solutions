#include <iostream>

using namespace std;
int a[1000000];
int n,i,i2,maxx,minn,mx,mn,res,c,d,sure,sum;
int main()
{
    cin>>n;
    cin>>a[1];
    maxx=minn=a[1];
    mx=mn=1;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxx){
            maxx=a[i];
            mx=i;
        }
        if(a[i]<=minn){
            minn=a[i];
            mn=i;
        }
    }
    if(mn<mx){
        sure=1;
    }
    sum+=mx-1;

    if(sure==1){
        sum+=n-mn-1;
    }
    else {
        sum+=n-mn;
    }
    cout<<sum;
    return 0;
}