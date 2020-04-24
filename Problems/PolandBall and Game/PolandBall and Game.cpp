#include <iostream>
#include <cmath>

using namespace std;

string arr1[10000], arr2[10000];

int main()
{
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> arr1[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> arr2[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr1[i] == arr2[j]){
                sum++;
            }
        }
    }
    int Polandball = (n - (sum / 2));
    int EnemyBall = (m - ((sum + 1) / 2));
    if(Polandball > EnemyBall){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}