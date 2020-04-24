#include <bits/stdc++.h>
using namespace std;
int p;
int i,i2,i3,res=0,n;
int a[1000000];
int main() {
	cin>>n;
	cin>>a[0];
	res+=a[0];
	for(i=1;i<n;i++){
		cin>>a[i];
		res+=a[i];	
	}
	
	sort(a,a+n);
	int r=0,maj=0;
	for(int i2=n-1;i2>=0;i2--){
		if(maj>res/2.0)break;
		maj+=a[i2];
		r++;
	}
	cout<<r;
	return 0;
}