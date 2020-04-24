#include <bits/stdc++.h>
using namespace std;
int p;
int i,i2,i3;
int a[100000];
string s1,s;
int main() {
	cin>>s>>s1;
	p=s.size();
	for(int i=0 ; i<p; i++){
		if(s[i]=='+'){continue;}
		else {
			a[i2]=s[i]-48;
			i2++;
		}
	}
	sort(a,a+i2);
	cout<<a[0];
	for(int i3=1;i3<i2;i3++){
		cout<<'+'<<a[i3];
	}
	return 0;
}