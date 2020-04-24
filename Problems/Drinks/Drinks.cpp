#include <bits/stdc++.h>

using namespace std;
double x,r,w;
int a[100000];
int main()
{
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>a[i];
        r+=a[i];
    }
    w=x;
    cout<<fixed;
    cout<<setprecision(9)<<r/w;
    return 0;
}