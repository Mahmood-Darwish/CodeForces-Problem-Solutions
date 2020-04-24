#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define F first
#define S second
using namespace std;

int n, a[300100], ans, INF = (1 << 30);
pair < int , int > tree[1001000];
vector < int > sol, temp;

void build(int node, int start, int endd)
{
    if(start == endd){
        tree[node] = {a[start], a[start]};
        return;
    }
    int mid = (start + endd) / 2;
    build(node * 2, start, mid);
    build((node * 2) + 1, mid + 1, endd);
    tree[node].F = min(tree[node * 2].F, tree[(node * 2) + 1].F);
    tree[node].S = __gcd(tree[node * 2].S, tree[(node * 2) + 1].S);
    return;
}

pair < int , int > query(int node, int start, int endd, int l, int r)
{
    if(start > r || endd < l)
        return {INF, -1};
    if(start >= l && endd <= r){
        return tree[node];
    }
    int mid = (start + endd) / 2;
    pair < int , int > p1 = query(node * 2, start, mid, l, r), p2 = query((node * 2) + 1, mid + 1, endd, l, r);
    if(p1.S == -1)
        return p2;
    if(p2.S == -1)
        return p1;
    return {min(p1.F, p2.F), __gcd(p1.S, p2.S)};
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }
    build(1, 1 ,n);
    int low = 0, high = n + 1, l, r;
    bool flag;
    while(low <= high){
        int mid = (low + high) / 2;
        temp.clear();
        flag = false;
        l = 1, r = mid + 1;
        for(int i = r ; i <= n ; i++){
            pair < int , int > QUERY = query(1, 1 , n, l ,r);
            if(QUERY.F == QUERY.S){
                temp.push_back(l);
                flag = true;
            }
            l++;
            r++;
        }
        if(flag){
            sol.swap(temp);
            ans = mid, low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << sol.size() << ' ' << ans << endl;
    for(auto cur : sol){
        printf("%d ", cur);
    }
    cout << endl;
    return 0;
}