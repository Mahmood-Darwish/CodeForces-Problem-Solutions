#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll leftt[100100];
ll rightt [100100];
map < ll, ll> mr, ml;
vector < ll > Vl, Vr, V;
ll n, ans;
string s[100100];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> s[i];
        int sum = 0;
        for(int j = s[i].size() - 1 ; j >= 0 ; j--){
            if(s[i][j] == ')'){
                sum++;
            }
            else{
                if(sum > 0) sum--;
            }
        }
        leftt[i] = sum;
        sum = 0;
        for(int j = 0 ; j < s[i].size() ; j++){
            if(s[i][j] == '('){
                sum++;
            }
            else{
                if(sum > 0) sum--;
            }
        }
        rightt[i] = sum;
        if(!leftt[i] && ! rightt[i]) V.pb(i);
        if(leftt[i] && !rightt[i]) Vl.pb(leftt[i]), ml[leftt[i]]++;
        if(!leftt[i] && rightt[i]) Vr.pb(rightt[i]), mr[rightt[i]]++;
    }
    for(int i = 0 ; i < Vl.size() ; i++){
        if(mr[Vl[i]] > 0){
            ans++;
            mr[Vl[i]]--;
        }
    }
    ans += V.size() / 2;
    cout << ans << endl;
    return 0;
}