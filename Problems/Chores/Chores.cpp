#include <bits/stdc++.h>

using namespace std;
int n,a,b;
int c[100000];
int main(){
cin>>n>>a>>b;
for(int i=0;i<n;i++){
cin>>c[i];
}
sort(c,c+n);
for(int i=0;i<n;i++){
if(c[i+1]!=c[i]){
if(i+1==b&&n-(1+i)==a){
cout<<c[i+1]-c[i];
return 0;
}}}
cout<<0;
return 0;
}