#include <iostream>

using namespace std;

int n ,m ,k ,sum = 1;

int main()
{
    cin >> n >> m >> k;
    n *= 2;
    for(int i = 1 ; i <= n ; i += 2){
        for(int j = 1 ; j <= m ; j++){
            if(sum == k){
                cout << (i + 1) / 2 << ' ' << j << " L";
                return 0;
            }
            sum++;
            i++;
            if(sum == k){
                cout << (i + 1) / 2 << ' ' <<  j << " R";
                return 0;
            }
            sum++;
            i--;
        }
    }
    return 0;
}