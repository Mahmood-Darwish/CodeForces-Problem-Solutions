#include <bits/stdc++.h>

using namespace std;
int p[100000];
int q[100000];
main(){
int n,res=0;
cin>>n;
for(int i=0;i<n;i++){
cin>>p[i]>>q[i];
}
for(int w=0;w<n;w++){
 if(q[w]-p[w]>=2){
 res++;
 }
 }
 cout<<res;
return 0;
}