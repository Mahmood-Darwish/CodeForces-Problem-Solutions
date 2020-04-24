#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int SQ = 700, arr[100100];

class Bucket{
    public:
    int L, R;
    int cnt[100100];
    deque < int > Q;
    Bucket(){
        L = R = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    Bucket(int a, int b, vector < int > v){
        L = a, R = b;
        memset(cnt,0 ,sizeof(cnt));
        for(int i = 0 ; i < v.size() ; i++){
            Q.push_back(v[i]);
            cnt[v[i]]++;
        }
    }
    int modify(int add)
    {
        cnt[add]++;
        cnt[Q.back()]--;
        Q.push_front(add);
        int temp = Q.back();
        Q.pop_back();
        return temp;
    }
};

vector < Bucket > V;

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &arr[i]);
    }
    int a = 1, b = min(SQ, n);
    while(a <= n){
        vector < int > v;
        for(int i = a ; i <= min(n, b); i++){
            v.push_back(arr[i]);
        }
        V.push_back(Bucket(a, min(n, b), v));
        a += SQ;
        b += SQ;
    }
    int q, ans = 0, l, r, t, k;
    cin >> q;
    while(q--){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d", &l, &r);
            l = ((l + ans - 1) % n) + 1;
            r = ((r + ans - 1) % n) + 1;
            if(r < l)
                swap(r, l);
            //cout << l << ' ' << r << endl;
            int l2 = max(0, (l / SQ) - ((l % SQ) == 0));
            int r2 = max(0, (r / SQ) - ((r % SQ) == 0));
            if(l2 == r2){
                vector < int > V_l;
                while(V[l2].Q.size()){
                    int u = V[l2].Q.front();
                    V[l2].Q.pop_front();
                    V_l.push_back(u);
                }
                int temp = V_l[r - V[l2].L];
                V_l.erase(V_l.begin() + r - V[l2].L);
                V_l.insert(V_l.begin() + (l - V[l2].L), temp);
                for(int i = 0 ; i < V_l.size() ; i++){
                    V[l2].Q.push_back(V_l[i]);
                }
//                for(int i = 0 ; i < V.size() ; i++){
//                    for(int j = 0 ; j < V[i].Q.size() ; j++){
//                        cout << V[i].Q.front() << ' ';
//                        V[i].Q.push_back(V[i].Q.front());
//                        V[i].Q.pop_front();
//                    }
//                    cout << endl;
//                    for(int j = 0 ; j < 10 ; j++){
//                        cout << V[i].cnt[j] << ' ';
//                    }
//                    cout << endl;
//                }
                continue;
            }
            vector < int > V_l, V_r;
            while(V[l2].Q.size()){
                int u = V[l2].Q.front();
                V[l2].Q.pop_front();
                V_l.push_back(u);
            }
            int temp = V_l.back();
            V_l.pop_back();
            V[l2].cnt[temp]--;
            for(int i = l2 + 1; i < r2 ; i++){
                temp = V[i].modify(temp);
            }
            while(V[r2].Q.size()){
                int u = V[r2].Q.front();
                V[r2].Q.pop_front();
                V_r.push_back(u);
            }
            int temp2 = V_r[(r - V[r2].L)];
            V[r2].cnt[temp2]--;
            V_r.erase(V_r.begin() + (r - V[r2].L));
            V_r.insert(V_r.begin(), temp);
            V[r2].cnt[temp]++;
            V_l.insert(V_l.begin() + (l - V[l2].L), temp2);
            V[l2].cnt[temp2]++;
            for(int i = 0 ; i < V_l.size() ; i++){
                V[l2].Q.push_back(V_l[i]);
            }
            for(int i = 0 ; i < V_r.size() ; i++){
                V[r2].Q.push_back(V_r[i]);
            }
//            for(int i = 0 ; i < V.size() ; i++){
//                for(int j = 0 ; j < V[i].Q.size() ; j++){
//                    cout << V[i].Q.front() << ' ';
//                    V[i].Q.push_back(V[i].Q.front());
//                    V[i].Q.pop_front();
//                }
//                cout << endl;
//                for(int j = 0 ; j < 10 ; j++){
//                    cout << V[i].cnt[j] << ' ';
//                }
//                cout << endl;
//            }
        }
        else{
            scanf("%d %d %d", &l, &r, &k);
            l = ((l + ans - 1) % n) + 1;
            r = ((r + ans - 1) % n) + 1;
            k = ((k + ans - 1) % n) + 1;
            if(r < l)
                swap(r, l);
            //cout << l << ' ' << r << ' ' << k << endl;
            int l2 = max(0, (l / SQ) - ((l % SQ) == 0));
            int r2 = max(0, (r / SQ) - ((r % SQ) == 0));
            if(l2 == r2){
                //cout << "Same\n";
                vector < int > V_l;
                while(V[l2].Q.size()){
                    int u = V[l2].Q.front();
                    V[l2].Q.pop_front();
                    V_l.push_back(u);
                }
                ans = 0;
                for(int i = l ; i <= r ; i++){
                    if(V_l[i - V[l2].L] == k)
                        ans++;
                }
                for(int i = 0 ; i < V_l.size() ; i++){
                    V[l2].Q.push_back(V_l[i]);
                }
                printf("%d\n", ans);
                continue;
            }
            vector < int > V_l, V_r;
            while(V[l2].Q.size()){
                int u = V[l2].Q.front();
                V[l2].Q.pop_front();
                V_l.push_back(u);
            }
            while(V[r2].Q.size()){
                int u = V[r2].Q.front();
                V[r2].Q.pop_front();
                V_r.push_back(u);
            }
            ans = 0;
            for(int i = l - V[l2].L ; i < V_l.size() ; i++){
                if(V_l[i] == k)
                    ans++;
            }
            for(int i = 0 ; i <= r - V[r2].L ; i++){
                if(V_r[i] == k)
                    ans++;
            }
            for(int i = 0 ; i < V_l.size() ; i++){
                V[l2].Q.push_back(V_l[i]);
            }
            for(int i = 0 ; i < V_r.size() ; i++){
                V[r2].Q.push_back(V_r[i]);
            }
            for(int i = l2 + 1 ; i < r2; i++){
                ans += V[i].cnt[k];
            }
            printf("%d\n", ans);
        }
    }
}