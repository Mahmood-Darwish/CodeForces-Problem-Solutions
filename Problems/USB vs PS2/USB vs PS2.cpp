#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back

using namespace std;

long long a, b, c, m, val, ans, sum;
string type;
vector < long long > USB, PS;
vector < long long > mixed;

int main()
{
    cin >> a >> b >> c;
    cin >> m;
    while(m--){
        cin >> val >> type;
        if(type == "USB")
            USB.pb(val);
        else PS.pb(val);
    }
    sort(USB.begin(), USB.end());
    sort(PS.begin(), PS.end());
    unsigned int i;
    for(i = 0 ; i < USB.size() ; i++){
        if(a){
            ans++;
            sum += USB[i];
            a--;
        }
        else{
            mixed.pb(USB[i]);
        }
    }
    for(i = 0 ; i < PS.size() ; i++){
        if(b){
            ans++;
            b--;
            sum += PS[i];
        }
        else {
            mixed.pb(PS[i]);
        }
    }
    sort(mixed.begin(), mixed.end());
    for(i = 0 ; i < mixed.size() ; i++){
        if(c){
            ans++;
            c--;
            sum += mixed[i];
        }
        else break;
    }
    cout << ans << ' ' << sum << endl;
    return 0;
}