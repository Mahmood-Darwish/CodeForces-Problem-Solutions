#include <bits/stdc++.h>

using namespace std;
int a[100000];
main(){
int n,m,x,i,i2,res=0;
cin>>n>>m;
for(i=0;i<n;i++){
    cin>>a[i];
}
x=a[m-1];
for(i2=0;i2<n;i2++){
    if(a[i2]>=x && a[i2]>0){
    res++;
}
}
cout<<res;
return 0;
}