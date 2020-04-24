#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long ll;


int SQ = 450, n, q;
int arr[200100];
ll ans;
int cnt[2001000];
ll ans_arr[200100];

void add(int index)
{
    ans -= (1LL * cnt[arr[index]]) * (1LL * cnt[arr[index]]) * (1LL * arr[index]);
    cnt[arr[index]]++;
    ans += (1LL * cnt[arr[index]]) * (1LL * cnt[arr[index]]) * (1LL * arr[index]);;
}

void sub(int index)
{
    //cout << index << endl;
    ans -= (1LL * cnt[arr[index]]) * (1LL * cnt[arr[index]]) * (1LL * arr[index]);
    //cout << index << endl;
    cnt[arr[index]]--;
    //cout << index << endl;
    ans += (1LL * cnt[arr[index]]) * (1LL * cnt[arr[index]]) * (1LL * arr[index]);
}

struct Query{
    int L, R, index;
}query[200100];

bool cmp(Query q1,Query q2){
	if(q1.L / SQ != q2.L / SQ)
		return (q1.L / SQ) < (q2.L / SQ);
	return q1.R < q2.R;
}

int main()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1 ; i <= q ; i++){
        scanf("%d %d", &query[i].L, &query[i].R);
        query[i].index = i;
    }
    sort(query + 1, query + q + 1, cmp);
    /*for(int i = 1 ; i <= q ; i++){
        cout << query[i].L << ' ' << query[i].R << endl;
    }*/
    int L = 1, R = 1;
    add(1);
    for(int i = 1 ; i <= q ; i++){
        int a = query[i].L, b = query[i].R;
        while(L < a){
            sub(L);
            L++;
        }
        while(L > a){
            L--;
            add(L);
        }
        while(R < b){
            R++;
            add(R);
        }
        while(b < R){
            sub(R);
            R--;
        }
        ans_arr[query[i].index] = ans;
    }
    for(int i = 1 ; i <= q ; i++){
        printf("%I64d\n", ans_arr[i]);
    }
    return 0;
}