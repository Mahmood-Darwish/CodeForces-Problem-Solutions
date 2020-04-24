#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <map>

using namespace std;

long long sum;
map < int , int > cnt;
int seg[4001000];
int n, a[1001000], b[1001000];
long long l[1001000], r[1001000];

int qu(int node, int le, int ri, int idx)
{

    if(idx >= ri && le <= idx)
        return 0;
    if(le > idx && ri > idx)
        return seg[node];
    /*cout << node << ' ' << le << ' ' << ri << ' ' << idx << endl;
    int x;
    cin >> x;*/
    int mid = (le + ri) / 2;
    int p1, p2;
    p1 = qu(node * 2, le, mid , idx);
    p2 = qu((node * 2) + 1 , mid + 1, ri, idx);
    return p1 + p2;
}

int qu2(int node, int le, int ri, int idx)
{
//    cout << node << ' ' << le << ' ' << ri << ' ' << idx << endl;
//    int x;
//    cin >> x;
    if(idx > ri && le < idx)
        return seg[node];
    if(le >= idx && ri >= idx)
        return 0;
    int mid = (le + ri) / 2;
    int p1, p2;
    p1 = qu2(node * 2, le, mid , idx);
    p2 = qu2((node * 2) + 1 , mid + 1, ri, idx);
    return p1 + p2;
}

void up(int node, int le, int ri, int idx)
{
    //cout << node << ' ' << le << ' ' << ri << ' ' << idx << endl;
    if(le == ri){
        if(le == idx)
            seg[node]++;
        return;
    }
    if(idx < le || idx > ri)
        return;
    int mid = (le + ri) / 2;
    up(node * 2, le, mid, idx);
    up((node * 2) + 1, mid + 1, ri, idx);
    seg[node] = seg[node * 2] + seg[(node * 2) + 1];
}


int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1 ; i <= n ; i++){
        cnt[a[i]] = i;
    }
    for(int i = 1 ; i <= n ; i++){
        b[i] = cnt[b[i]];
    }
    for(int i = 1 ; i <= n ; i++){
        l[i] += qu(1, 1, n, b[i]);
        up(1, 1, n, b[i]);
    }
    /*for(int i = 1 ; i <= n ; i++)
        cout << l[i] << ' ';
    cout << endl;
    */memset(seg, 0, sizeof(seg));
    for(int i = n ; i > 0 ; i--){
        r[i] += qu2(1, 1, n, b[i]);
        up(1, 1, n, b[i]);
    }
    /*for(int i = 1 ; i <= n ; i++){
        cout << r[i] << ' ';
    }
    cout << endl;*/
    for(int i = 1 ; i <= n ; i++){
        sum += r[i] * l[i];
    }
    cout << sum << endl;
    return 0;
}