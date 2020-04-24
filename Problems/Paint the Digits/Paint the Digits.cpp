#include <bits/stdc++.h>
#define F first
#define S second
#define R return
#define pb push_back
#define SI size()
#define ll long long
using namespace std;
/*D
int n,ans;
vector<int> v[200030];
bool vis[200030];

void dfs(int node){
    if(vis[node]) R;
    vis[node]=1;
    if(node > n){
        int cur = 0;
        for(auto pp:v[node]){
            if(vis[pp]) continue;
            cur++;
        }
        if(cur==0){ans++;R;}
    }
    for(auto pp:v[node]) dfs(pp);
}
*/
vector<int> v;
string s;
char c[200030];
pair<int,int> a[200030];
int w[200030];

/*E1
int m,n;
int a[15][120];
bool vis[102];

int solve(int row){
    int mxx=0,cur=0;
    for(int i=0;i<m;i++){
        if(vis[i]) continue;
        int mx = 0;
        for(int j=0;j<n;j++) mx = max(mx , a[j][i]);
        if(mx > mxx){
            mxx= mx;
            cur = i;
        }
    }
    vis[cur] = 1;
    R mxx;
}
*/
int main()
{
    /*D
    int k;scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        int a,b;scanf("%d%d",&a,&b);
        v[n+i].pb(a);
        v[n+i].pb(b);
        v[a].pb(n+i);
        v[b].pb(n+i);
    }
    dfs(1);
    for(int i=1;i<=k;i++){
        if(vis[i+n]) continue;
        dfs(n+i);
    }
    printf("%d\n",ans);*/
    int test;scanf("%d",&test);
    while(test--){
        v.clear();
        int n;scanf("%d",&n);
        scanf("%s",&c);s = c;
        for(int i=0;i<s.SI;i++){
            a[i].F = s[i]-'0';
            a[i].S = i;
        }
        sort(a,a+n);
        w[a[0].S] = 1;
        for(int i=0;i<n-1;i++){
            w[a[i].S] = 1;
            if(a[i+1].S < a[i].S){
                int f = a[i+1].F;
                int mx = a[i].S;
                for(int j=i+1;j<n-1;j++){
                    if(a[j].F>f) break;
                    if(a[j].S > mx) w[a[j].S]=1;
                }
                break;
            }
        }
        for(int i=0;i<n;i++)
            if(w[i]==0) w[i] = 2;
        for(int i=0;i<n;i++){
            if(w[i] == 1) v.pb(s[i]-'0');
        }
        for(int i=0;i<n;i++){
            if(w[i] == 2) v.pb(s[i]-'0');
        }
        bool b = 0;
        for(int i=0;i<v.SI-1;i++){
            if(v[i+1]<v[i]) b=1;
        }
        if(b) printf("-");
        else{
            for(int i=0;i<n;i++) printf("%d",w[i]);
        }
        for(int i=0;i<n;i++) w[i]=0;
        printf("\n");
    }
    /*E1
    int test;scanf("%d",&test);
    while(test--){
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=solve(i);
        }
        printf("%d\n",ans);
    }*/
    return 0;
}