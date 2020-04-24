#include <iostream>
#include <stdio.h>
#include <string.h>
#define F first
#define S second
using namespace std;

int n, m, b, x, pos1, pos2, INF = (2000000007);
int pizza[100100];
int sz[100100];
int cost[100100];
int mask[100100];
int freq[100100];
pair < int, int > cost_mask[100100];
pair < int, int > idx[100100];

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &b);
        for(int j = 1 ; j <= b ; j++){
            scanf("%d", &x);
            x--;
            mask[i] |= (1 << x);
        }
        freq[mask[i]]++;
    }
    for(int i = 0 ; i <= (1 << 9) ; i++) cost_mask[i].F = cost_mask[i].S = INF;
    for(int i = 1 ; i <= m ; i++){
        scanf("%d%d", &cost[i], &b);
        for(int j = 1 ; j <= b ; j++){
            scanf("%d", &x);
            x--;
            pizza[i] |= (1 << x);
        }
        if(cost_mask[pizza[i]].F >= cost[i]){
            cost_mask[pizza[i]].S = cost_mask[pizza[i]].F;
            idx[pizza[i]].S = idx[pizza[i]].F;
            cost_mask[pizza[i]].F = cost[i];
            idx[pizza[i]].F = i;
            continue;
        }
        if(cost_mask[pizza[i]].S >= cost[i]){
            cost_mask[pizza[i]].S = cost[i];
            idx[pizza[i]].S = i;
            continue;
        }
        //cout << i << ' ' << pizza[i] << ' ' << cost_mask[pizza[i]].F << ' ' << idx[pizza[i]].F << endl;
    }
    pair < int, int > ans = {-INF, INF};
    for(int i = 0 ; i <= (1 << 9); i ++){
        for(int j = 0 ; j <= (1 << 9) ; j++){
            if(j == i){
                if(cost_mask[i].F == INF || cost_mask[i].S == INF) continue;
                pair < int, int > temp = {0, cost_mask[i].F + cost_mask[i].S};
                for(int k = 0 ; k <= (1 << 9) ; k++){
                    if((i & k) == k){
                        temp.F += freq[k];
                    }
                }
                if(temp.F > ans.F || (temp.F == ans.F && temp.S < ans.S)){
                    ans = temp;
                    pos1 = idx[i].F;
                    pos2 = idx[i].S;
                }
                continue;
            }
            if(cost_mask[i].F == INF || cost_mask[j].F == INF) continue;
            pair < int, int > temp = {0, cost_mask[i].F + cost_mask[j].F};
            for(int k = 0 ; k <= (1 << 9) ; k++){
                if((((j | i) & k) == k)){
                    temp.F += freq[k];
                }
            }
            if(temp.F > ans.F || (temp.F == ans.F && temp.S < ans.S)){
                //cout << temp.F << endl;
                //cout << i << ' ' << j << ' ' << cost_mask[i].F << ' '<< cost_mask[j].F << endl;
                ans = temp;
                pos1 = idx[i].F;
                pos2 = idx[j].F;
            }
        }
    }
    cout << pos1 << ' ' << pos2 << endl;
    return 0;
}