#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, k;
vector < long long > V;

int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            V.push_back(i);
            if(i != n / i){
                V.push_back(n / i);
            }
        }
    }
    sort(V.begin(), V.end());
    for(int i = 0 ; i < V.size() - 1; i++){
        if(V[i] == V[i + 1])
            V.erase(V.begin() + i);
    }
    if(V.size() < k)
        cout << -1;
    else
        cout << V[k - 1];
    cout << endl;
}