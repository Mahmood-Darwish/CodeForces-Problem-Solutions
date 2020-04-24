#include <bits/stdc++.h>
#define R return
#define F first
#define S second
#define B break
#define pb push_back
#define pq priority_queue
#define ll long long
#define C continue
using namespace std;
int a[1000005];
int b[1000005];
int pr[1001010];

pair <int,int> p,p1;
bool check(int x,int y){
	bool b = 1,b1 = 1, b2 = 1;
	int f = p.F;
	int s = p.S;
	if (((x>f)&&(y<s))||(y<f)||(x>s)){
		b = 0;
	}
	f = p1.F;
	s = p1.S;
	if (((x>f)&&(y<s))||(y<f)||(x>s)){
		b1 = 0;
	}
	if(x != 1){
		if(pr[x - 1] > y){
			b2 = 0;
		}
	}
	R (b2&(b1&b));
}
int main() {
	int n,x;
	cin>>n>>x;
	p = {0,0};
	p1 = {x+1,x+1};
	int mx = 0,mn = x+1;
	for (int i=0;i<n;i++){
	    scanf("%d", &a[i]);
		if (a[i]<mx){
			int o = p.F;
			if (a[i]>o){
				p = {a[i],mx};
			}
		}
		mx = max (mx,a[i]);
	}
	for (int i=n-1;i>=0;i--){
		if (a[i]>mn){
			int o = p1.S;
			if (o>a[i]){
				p1 = {mn,a[i]};
			}
		}
		mn = min(a[i],mn);
	}
	if (p.F == 0){
		if (p1.F == x+1){
			ll k = x;
			cout<<(k*(k+1))/2;
			R 0;
		}
	}
	set < int > s;
	for(int i = 0 ; i < n ; i++){
		auto temp = s.upper_bound(a[i]);
		if(temp != s.end()){
			auto temp2 = s.end();
			temp2--;
			if(temp2 != s.end())
				b[a[i]] = *(temp2);
			else b[a[i]] = -1;
		}
		else b[a[i]] = -1;
		s.insert(a[i]);
	}
	pr[0] = 0;
	for(int i = 1 ; i <= x ; i++){
		if(b[i] != -1)
			pr[i] = max(b[i], pr[i - 1]);
		
		//cout << pr[i] << ' ';
	}
	//cout << endl;
	/*
	cout<<p.F<<' '<<p.S<<endl;
	cout<<p1.F<<' '<<p1.S<<endl;
	*/
	ll ans = 0;
	for (int l=1;l<=x;l++){
		int L = l,r = x;
		int temp = -1;
		while (L<=r){
			int mid = (L+r)/2;
			if (check(l,mid)){
				r = mid-1;
				temp = mid;
			}
			else {
				L = mid+1;
			}
		}
		//cout<<l<<' '<<temp<<endl;
		if (temp == -1) C;
		ans+=(x-temp+1);
	}
	cout<<ans<<endl;
    R 0;
}