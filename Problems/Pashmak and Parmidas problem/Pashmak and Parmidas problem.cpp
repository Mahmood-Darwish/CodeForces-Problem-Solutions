#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

ll n, sum;
ll seg[4000010];
ll a[1001000];
ll ans[1001000];
map < ll , ll > cnt;

void upd1(int node, int le, int ri, int num)
{
    if(le == ri){
        if(le == num)
            seg[node]++;
        return;
    }
    int mid = (le + ri) / 2;
    if(num <= mid)
        upd1(node * 2, le, mid, num);
    else
        upd1((node * 2) + 1, mid + 1, ri, num);
    seg[node] = seg[node * 2] + seg[(node * 2) + 1];
}

void upd2(int node, int le, int ri, int num)
{
    if(le == ri){
        if(le == num)
            seg[node]--;
        return;
    }
    int mid = (le + ri) / 2;
    if(num <= mid)
        upd2(node * 2, le, mid, num);
    else
        upd2((node * 2) + 1, mid + 1, ri, num);
    seg[node] = seg[node * 2] + seg[(node * 2) + 1];
}

int query(int node, int le, int ri, int num)
{
    if(ri < num)
        return seg[node];
    if(ri >= num && le >= num)
        return 0;
    int mid = (le + ri) / 2;
    int p1 = query(node * 2, le, mid, num);
    int p2 = query((node * 2) + 1, mid + 1, ri, num);
    return p1 + p2;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }
    for(int i = n ; i > 0 ; i--){
        cnt[a[i]]++;
        ans[i] = cnt[a[i]];
        upd1(1 ,1 ,n ,ans[i] );
    }
    /*for(int i = 1 ; i <= n ; i++)
        cout << ans[i] << ' ';
    cout << endl;
    for(int i = 1 ; i <= n * 2 ; i++){
        cout << seg[i] << ' ' ;
    }
    cout << endl;*/
    cnt.clear();
    for(int i = 1 ; i < n ; i++){
        upd2(1, 1, n, ans[i]);
        cnt[a[i]]++;
        //cout << cnt[a[i]] << ' ' << query(1, 1, n, cnt[a[i]]) << endl;
        sum += query(1, 1, n, cnt[a[i]]);
    }
    cout << sum << endl;
    return 0;
}