#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

bool is_prime(int x)
{
    for(int i = 2 ; i <= sqrt(x) ; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int n, a[1007], ones;
bool prime[10000100], cool;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        if(a[i] == 1)
            ones++;
        if(!cool && a[i] != 1){
            cool = is_prime(a[i] + 1);
        }
    }
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i <= 1e4 ; i++){
        if(prime[i]){
            for(int j = i + i ; j <= 1e7 ; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            if(prime[a[i] + a[j]]){
                if(ones + cool > 2){
                    cout << ones + cool << endl;
                    for(int i = 0 ; i < n ; i++){
                        if(prime[a[i] + 1] && a[i] != 1){
                            cout << a[i] << ' ';
                            break;
                        }
                    }
                    while(ones--){
                        cout << 1 << ' ';
                    }
                    cout << endl;
                    return 0;
                }
                else{
                    cout << 2 << endl << a[i] << ' ' << a[j] << endl;
                    return 0;
                }
            }
        }
    }
    if(ones + cool == 0){
        cout << 1 << endl << a[0] << endl;
        return 0;
    }
    cout << ones + cool << endl;
    for(int i = 0 ; i < n ; i++){
        if(prime[a[i] + 1] && a[i] != 1){
            cout << a[i] << ' ';
            break;
        }
    }
    while(ones--){
        cout << 1 << ' ';
    }
    cout << endl;
    return 0;
}