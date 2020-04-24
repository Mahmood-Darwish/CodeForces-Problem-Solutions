#include <iostream>
#include <map>

#define F first
#define S second

using namespace std;

int n, A, B, a[100100];
map < int , pair < int , bool > > cnt;

int main()
{
    cin >> n >> A;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(!B && a[i] == A){
            B = i;
        }
        cnt[a[i]].F++;
    }
    for(auto it = cnt.begin() ; it != cnt.end() ; it++){
        if((it -> S).F < cnt[A].F)
            (it -> S).S = true;
    }
    for(int i = n ; i > B ; i--){
        --cnt[a[i]].F;
        if(cnt[a[i]].F < cnt[A].F){
            cnt[a[i]].S = true;
        }
    }
    for(auto it = cnt.begin() ; it != cnt.end() ; it++){
        if((it -> S).S == false && ((it -> F) != A)){
            cout << it -> F << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}