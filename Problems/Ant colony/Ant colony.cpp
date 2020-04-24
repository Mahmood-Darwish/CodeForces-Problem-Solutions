#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int a[100100];
int tree[4 * 100100];
unordered_map < int, vector < int > > m;

int GCD(int a, int b)
{
    if(!b) return a;
    return GCD(b, a % b);
}

void Build(int node, int st, int en)
{
    if(st == en){
        tree[node] = a[st];
        return ;
    }
    int mid = (st + en) / 2;
    Build(node * 2, st, mid);
    Build((node * 2) + 1, mid + 1, en);
    tree[node] = GCD(tree[node * 2], tree[(node * 2) + 1]);
    return;
}

int query(int node, int st, int en, int l, int r)
{
    //cout << node << ' ' << st << ' ' << en << ' ' << l << ' ' << r << endl;
    //system("pause");
    if(st > r || en < l) return 0;
    if(l <= st && en <= r) return tree[node];
    int mid = (st + en) / 2;
    //cout << mid << endl;
    return GCD(query(node * 2, st, mid, l ,r), query((node * 2) + 1, mid + 1, en, l ,r));
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        m[a[i]].push_back(i);
    }
    Build(1, 1, n);
    int Q, l, r, x, y;
    cin >> Q;
    while(Q--){
        scanf("%d", &l);
        scanf("%d", &r);
        x = query(1, 1, n, l, r);
        //cout << x << ' ';
        y = upper_bound(m[x].begin(), m[x].end() ,r) - lower_bound(m[x].begin(), m[x].end() ,l);
        printf("%d\n", (r - l + 1) - y);
    }
    return 0;
}