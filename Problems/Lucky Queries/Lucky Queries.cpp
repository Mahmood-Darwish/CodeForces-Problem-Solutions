#include <iostream>

using namespace std;

int n, m, l, r;
string s, t;
bool vis[4000100];

struct Node{
    int f, s, fs, sf;
}tree[4000100];

void Build(int node, int st, int en)
{
    //cout << node << ' ' << st << ' ' << en << endl;
    if(st == en){
        //cout << s[st] << endl;
        if(s[st] == '4'){
            tree[node].f++;
        }
        else{
            tree[node].s++;
        }
        tree[node].fs++;
        tree[node].sf++;
        return;
    }
    else{
        int mid = (st + en) / 2;
        Build(node * 2, st, mid);
        Build(node * 2 + 1, mid + 1, en);
        tree[node].f = tree[node * 2].f + tree[node * 2 + 1].f;
        tree[node].s = tree[node * 2].s + tree[node * 2 + 1].s;
        tree[node].fs = max(tree[node * 2].f + tree[node * 2 + 1].s, max(tree[node * 2].fs + tree[node * 2 + 1].s, tree[node * 2].f + tree[node * 2 + 1].fs));
        tree[node].sf = max(tree[node * 2].s + tree[node * 2 + 1].f, max(tree[node * 2].sf + tree[node * 2 + 1].f, tree[node * 2].s + tree[node * 2 + 1].sf));
    }
}

void up(int node, int st, int en, int low, int high)
{
    if(vis[node]){
        swap(tree[node].f, tree[node].s);
        swap(tree[node].fs, tree[node].sf);
        vis[node] = false;
        if(st != en)
            vis[node * 2] = 1 - vis[node * 2], vis[node * 2 + 1] = 1 - vis[node * 2 + 1];
    }
    if(low > en || high < st) return;
    if(low <= st && high >= en){
        swap(tree[node].f, tree[node].s);
        swap(tree[node].fs, tree[node].sf);
        if(st != en)
            vis[node * 2] = 1 - vis[node * 2], vis[node * 2 + 1] = 1 - vis[node * 2 + 1];
        return;
    }
    int mid = (st + en) / 2;
    up(node * 2, st, mid, low, high);
    up(node * 2 + 1, mid + 1, en, low, high);
    tree[node].f = tree[node * 2].f + tree[node * 2 + 1].f;
    tree[node].s = tree[node * 2].s + tree[node * 2 + 1].s;
    tree[node].fs = max(tree[node * 2].f + tree[node * 2 + 1].s, max(tree[node * 2].fs + tree[node * 2 + 1].s, tree[node * 2].f + tree[node * 2 + 1].fs));
    tree[node].sf = max(tree[node * 2].s + tree[node * 2 + 1].f, max(tree[node * 2].sf + tree[node * 2 + 1].f, tree[node * 2].s + tree[node * 2 + 1].sf));
    return;
}

int main()
{
    cin >> n >> m;
    cin >> s;
    s = "#" + s;
    Build(1, 1, n);
    while(m--){
        cin >> t;
        if(t == "count"){
            printf("%d\n", tree[1].fs);
        }
        else{
            scanf("%d %d", &l, &r);
            up(1, 1, n, l, r);
        }
    }
    return 0;
}