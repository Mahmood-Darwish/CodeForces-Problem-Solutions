#include <bits/stdc++.h>

using namespace std;

vector < int > m, h;
vector < int > V[200105];
int n, a, b, SQ = 350, ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i++){
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
    }
    for(int i = 0 ; i <= 100050 ; i++){
        if(V[i].size()){
            m.push_back(i);
        }
    }
    for(int i = 0 ; i < m.size(); i++){
        sort(V[m[i]].begin(), V[m[i]].end());
    }
    for(int i = 0 ; i < m.size() ; i++){
        if(V[m[i]].size() > SQ)
            h.push_back(m[i]);
    }
    for(unsigned int qq = 0 ; qq < m.size() ; qq++){
        if((int)V[m[qq]].size() <= SQ){
            for(unsigned int j = 0 ; j < V[m[qq]].size() ; j++){
                for(unsigned int k = j + 1 ; k < V[m[qq]].size() ; k++){
                    int dif = V[m[qq]][k] - V[m[qq]][j];
                    auto it1 = lower_bound(V[m[qq] + dif].begin(), V[m[qq] + dif].end(), V[m[qq]][j]), it2 = lower_bound(V[m[qq] + dif].begin(), V[m[qq] + dif].end(), V[m[qq]][k]);
                    if(it1 != V[m[qq] + dif].end() && it2 != V[m[qq] + dif].end()){
                        if(*it1 == V[m[qq]][j] && *it2 == V[m[qq]][k]){
                            ans++;
                        }
                    }
                    dif = V[m[qq]][k] - V[m[qq]][j];
                    if(m[qq] - dif >= 0 && V[m[qq] - dif].size() > SQ){
                        it1 = lower_bound(V[m[qq] - dif].begin(), V[m[qq] - dif].end(), V[m[qq]][j]), it2 = lower_bound(V[m[qq] - dif].begin(), V[m[qq] - dif].end(), V[m[qq]][k]);
                        if(it1 != V[m[qq] - dif].end() && it2 != V[m[qq] - dif].end()){
                            if(*it1 == V[m[qq]][j] && *it2 == V[m[qq]][k]){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < h.size() ; i++){
        for(int j = 0 ; j < V[h[i]].size() ; j++){
            for(int k = i + 1 ; k < h.size() ; k++){
                auto it1 = lower_bound(V[h[k]].begin(), V[h[k]].end(), V[h[i]][j]);
                if(it1 != V[h[k]].end()){
                    if(*it1 == V[h[i]][j]){
                        int dif = h[k] - h[i];
                        auto it2 = lower_bound(V[h[i]].begin(), V[h[i]].end(), V[h[i]][j] + dif);
                        auto it3 = lower_bound(V[h[k]].begin(), V[h[k]].end(), V[h[i]][j] + dif);
                        if(it2 != V[h[i]].end() && it3 != V[h[k]].end()){
                            if(*it2 == V[h[i]][j] + dif && *it3 == V[h[i]][j] + dif)
                                ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}