#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, q, a, b, timer = 1, SQ = 350;
int col[100005];
int col2 [100005];
vector < int > adj[100005];
int st[100005];
int en[100005];
int ans[100005];
int takrar1[100005];
int takrar2[100005];

struct Query{
    int L, R, K, index;
}query[100005];

void pre_calc(int node, int par)
{
    col2[timer] = col[node];
    st[node] = timer++;
    for(auto cur : adj[node]){
        if(cur == par) continue;
        pre_calc(cur, node);
    }
    en[node] = timer - 1;
    return;
}

bool cmp(const Query &lhs, const Query &rhs)
{
	if (lhs.L / SQ == rhs.L / SQ)
		return lhs.R > rhs.R;
	return lhs.L / SQ < rhs.L / SQ;
}

int main()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        scanf("%d", &col[i]);
    for(int j = 1 ; j < n ; j++){
        scanf("%d %d", &a, &b);
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    pre_calc(1, -1);
    for(int i = 1 ; i <= q ; i++){
        scanf("%d %d", &a, &b);
        query[i].L = st[a];
        query[i].R = en[a];
        query[i].index = i;
        query[i].K = b;
    }
    sort(query + 1, query + q + 1, cmp);
    int L = 1, R = 1;
    takrar1[col[1]]++;
    takrar2[1]++;
    for(int i = 1 ; i <= q ; i++){
        a = query[i].L, b = query[i].R;
        while(L < a){
            takrar2[takrar1[col2[L]]]--;
            takrar1[col2[L]]--;
            L++;
        }
        while(L > a){
            L--;
            takrar1[col2[L]]++;
            takrar2[takrar1[col2[L]]]++;
        }
        while(R > b){
            takrar2[takrar1[col2[R]]]--;
            takrar1[col2[R]]--;
            R--;
        }
        while(R < b){
            R++;
            takrar1[col2[R]]++;
            takrar2[takrar1[col2[R]]]++;
        }
        ans[query[i].index] = takrar2[query[i].K];
    }
    for(int i = 1 ; i <= q ; i++)
        printf("%d\n", ans[i]);
    return 0;
}