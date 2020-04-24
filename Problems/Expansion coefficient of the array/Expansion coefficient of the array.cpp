#include <bits/stdc++.h>
#define SF(x) scanf("%d",&x)
#define F first
#define S second
#define MEM(a,b) memset(a,b,sizeof(a))
#define DB(x) cout << #x << " is " << x << endl
#define ffs(x) __builtin_ffs(x) // This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
#define clz(x) __builtin_clz(x) // This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define ctz(x) __builtin_ctz(x) // This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define popcount(x) __builtin_popcount(x) // This function returns number of active bits in the binary represintation of the number
#define pb push_back

using namespace std;
typedef long long ll;

ll INF = (1LL << 29LL);

ll Mypow(ll X,ll Y){
    if(Y < 0)return 0;
    if(Y == 0)return 1;
    if(Y == 1){
        return X;
    }
    else{
        ll x = Mypow(X ,Y / 2);
        x *= x;
        if(Y % 2)
            return (x * X);
        else
            return x;
    }
}

int a[350005];
vector< int > V;
unordered_map <int, vector < int > > m;
unordered_map <int, bool> vis;
int n;

int main() {
	SF(n);
	for (int i=0;i<n;i++){
        SF(a[i]);
		m[a[i]].pb(i);
		if (vis[a[i]]) continue;
		vis[a[i]] = 1;
		V.pb(a[i]);
	}
	sort(V.begin(),V.end());
	int s = 0,e = n - 1;
	int ans = 1000000007;
	for (int i=0;i < V.size();i++){
		for (int j=0;j < m[V[i]].size();j++){
			int x = (m[V[i]][j]);
			int y = V[i];
			int c1 = 1000000007,c2 = 1000000007;
			if (x!=s)
                c1 = y/(x-s);
			if (x!=e)
                c2 = y/(e-x);
			ans = min(ans,min(c1,c2));
		}
		for (int j=s;j<=e;j++){
			if (a[j]<=V[i]) s++;
			else break;;
		}
		for (int j=e;j>=s;j--){
			if (a[j]<=V[i]) e--;
			else break;;
		}
		if (e<s) break;
		else if (e<0) break;
		else if (s>=n) break;
	}
	cout<<ans<<endl;
}