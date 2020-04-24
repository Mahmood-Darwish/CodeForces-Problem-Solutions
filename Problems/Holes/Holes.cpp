#include <iostream>
#include <stdio.h>

using namespace std;

int countt[200100];
int last[200100];
int nextt[200100];
int block[200100];
int a[200100];
int n, m;

void fix(int i)
{
    if(a[i] + i >= n + 1){
        countt[i] = 1;
        last[i] = i;
        nextt[i] = n + 1;
        return;
    }
    if(block[i + a[i]] != block[i]){
        countt[i] = 1;
        last[i] = i;
        nextt[i] = i + a[i];
        return;
    }
    countt[i] = countt[i + a[i]] + 1;
    last[i] = last[i + a[i]];
    nextt[i] = nextt[i + a[i]];
}

void ans(int i)
{
    int answer = 0;
    int lastt = last[i];
    while(nextt[i] != n + 1){
        answer += countt[i];
        i = nextt[i];
        lastt = last[i];
    }
    answer += countt[i];
    printf("%d %d\n", lastt, answer);
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        scanf("%d", &a[i]);
    int temp = 0;
    for(int i = 1 ; i <= n ; i++){
        block[i] = temp;
        if(i % 350 == 0) temp++;
    }
    for(int i = n ; i >= 1 ; i--){
        fix(i);
    }
    int t, x, y;
    while(m--){
        scanf("%d", &t);
        if(t == 0){
            scanf("%d %d", &x, &y);
            a[x] = y;
            for(int i = x ; i >= 1 ; i--){
                if(block[i] != block[x]) break;
                fix(i);
            }
        }
        else{
            scanf("%d", &x);
            ans(x);
        }
    }
    return 0;
}