#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 1)
        return cout << -1, 0;
    cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
}