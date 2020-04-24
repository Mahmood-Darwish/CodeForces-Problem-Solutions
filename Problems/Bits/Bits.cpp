#include <iostream>

using namespace std;

unsigned long long n, L, R, ans;

int main()
{
    cin >> n;
    while(n--){
        cin >> L >> R;
        ans = L;
        for(unsigned long long i = 0 ; i <= 63 ; i++){
            if((ans | ((unsigned long long)(1LL << i))) <= R){
                ans |= ((unsigned long long)(1LL << i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}