#include <iostream>

using namespace std;

int n, k, ans;

int main(){
    cin >> n >> k;
    int Time = 4 * 60;
    for(int i = 1 ; i <= n ; i++){
        Time -= i * 5;
        if(Time >= k)
            ans++;
        else 
            break;
    }
    cout << ans << endl;
}