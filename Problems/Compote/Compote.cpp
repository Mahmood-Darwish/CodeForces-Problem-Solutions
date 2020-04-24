#include <iostream>

using namespace std;

int main() {
    int a, l, p, sum = 0;
    cin >> l >> a >> p;
    while(true){
        if(l && a >= 2 && p >= 4){
            sum += 7;
            l--;
            a -= 2;
            p -= 4;
        }
        else break;
    }
    cout << sum << endl;
    return 0;
}