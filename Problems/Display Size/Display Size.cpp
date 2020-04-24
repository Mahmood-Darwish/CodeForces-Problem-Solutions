#include <iostream>
#include <vector>

using namespace std;

int n, mn = 999999, one , two;
vector < int > V;

int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0)
            V.push_back(i);
    }
    int m = V.size();
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(V[i] * V[j] == n && V[i] >= V[j] && mn >= V[i] - V[j]){
                mn = V[i] - V[j];
                one = V[i];
                two = V[j];
            }
        }
    }
    cout << two << ' ' << one << endl;
    return 0;
}