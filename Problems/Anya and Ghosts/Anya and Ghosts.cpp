#include <iostream>

using namespace std;

int n, t, r, num, a[1000], ans, INF = (1 << 12);

int main()
{
    cin >> n >> t >> r;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        a[num + 400] = -INF;
    }
    if(r > t){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 400 ; i <= 700 ; i++){
        if(a[i] == -INF || a[i] == 10){
            int temp = 0;
            for(int j = i - t ; j != i ; j++){
                if(a[j] == 1 || a[j] == 10)
                    temp++;
            }
            for(int j = i - 1 ; temp < r ; j--){
                if(a[j] == -INF){
                    a[j] = 10;
                    ans++;
                }
                else{
                    if(a[j] == 0){
                        a[j] = 1;
                        ans++;
                    }
                }
                temp++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}