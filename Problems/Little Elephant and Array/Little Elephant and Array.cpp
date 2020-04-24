#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, sum, SQ = 350;
int a[100100];
int ans[100100];
unordered_map < int , int > cnt;

struct Query{
    int l, r, ind;
}arr[100100];

bool cmp(Query lhs, Query rhs)
{
    if(lhs.l / SQ == rhs.l / SQ){
        return lhs.r < rhs.r;
    }
    return lhs.l / SQ < rhs.l / SQ;
}

void add(int x)
{
    int temp = cnt[a[x]];
    if(temp == a[x]){
        cnt[a[x]]++;
        sum--;
        return;
    }
    cnt[a[x]]++;
    if(temp + 1 == a[x]){
        sum++;
    }
    return;
}

void sub(int x)
{
    int temp = cnt[a[x]];
    if(temp == a[x]){
        cnt[a[x]]--;
        sum--;
        return;
    }
    cnt[a[x]]--;
    if(temp - 1 == a[x]){
        sum++;
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d", &arr[i].l, &arr[i].r);
        arr[i].ind = i;
    }
    sort(arr + 1, arr + m + 1, cmp);
    int L = 1, R = 1;
    add(1);
    for(int i = 1 ; i <= m ; i++){
        int l = arr[i].l, r = arr[i].r;
        int index = arr[i].ind;
        //cout << L << ' ' << R << ' ' << l  << ' ' << r << ' ' << index << ' ' << sum << endl;
        while(L > l){
            add(--L);
        }
        //cout << L << ' ' << R << ' ' << l  << ' ' << r << ' ' << index << ' ' << sum << endl;
        while(L < l){
            sub(L++);
        }
        //cout << L << ' ' << R << ' ' << l  << ' ' << r << ' ' << index << ' ' << sum << endl;
        while(R < r){
            add(++R);
        }
        //cout << L << ' ' << R << ' ' << l  << ' ' << r << ' ' << index << ' ' << sum << endl;
        while(R > r){
            sub(R--);
        }
        //cout << L << ' ' << R << ' ' << l  << ' ' << r << ' ' << index << ' ' << sum << endl;
        ans[index] = sum;
    }
    for(int i = 1 ; i <= m ; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}