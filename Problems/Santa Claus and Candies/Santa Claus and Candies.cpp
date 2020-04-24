#include <iostream>
#include <vector>
using namespace std;
int n;
vector < int > V;
int main(){
    cin >> n;
    for(int i = 1; i <= n ;i++){
        n -= i;
        V.push_back(i);
        if(i + 1 > n)
            break;
    }
    V[V.size() - 1] += n;
    cout << V.size() << endl;
    for(auto cur:V)
        cout << cur << ' ';
}