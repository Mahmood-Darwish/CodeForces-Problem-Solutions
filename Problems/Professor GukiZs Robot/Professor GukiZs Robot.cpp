#include <bits/stdc++.h>
using namespace std;

int main() {
	int x1,y1,x2,y2,d,x,y;
	cin>>x1>>y1;
	cin>>x2>>y2;
	y=abs(y1-y2);
	x=abs(x1-x2);
	d=max(x,y);
	cout<<d;
	return 0;
}