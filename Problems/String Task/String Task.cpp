#include <bits/stdc++.h>
using namespace std;
int p;
string s,s1;
int main() {
	cin>>s;
	p=s.size();
	for(int i=0;i<p;i++){
	    if(isupper(s[i])){
		s[i]=tolower(s[i]);
		}
		if(s[i]=='a'||s[i]=='e'||s[i]=='u'||s[i]=='y'||s[i]=='i'||s[i]=='o'){
			continue;
		}
		else cout<<"."<<s[i];
	}
	return 0;
}