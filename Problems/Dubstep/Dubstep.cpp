#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
cin>>s;
n=s.size();
for(int i=0;i<n;i++){
if( s[i]=='W' && s[i+1]=='U' && s[i+2]=='B' ){
cout<<" ";
i+=2;
}
else {
cout<<s[i];
}}
	return 0;
}