#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[100100], sum;
vector < char > sol1, sol2;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(sum >= 0){
            sum -= a[i];
            sol1.push_back('-');
            sol2.push_back('+');
        }
        else{
            sum += a[i];
            sol1.push_back('+');
            sol2.push_back('-');
        }
    }
    reverse(sol1.begin(), sol1.end());
    reverse(sol2.begin(), sol2.end());
    if(sum >= 0 && sum <= a[0]){
        for(auto cur : sol1){
            cout << cur;
        }
    }
    else{
        for(auto cur : sol2){
            cout << cur;
        }
    }
    cout << endl;
    return 0;
}