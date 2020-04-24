#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(!(n % 2)) return cout << -1 << endl, 0;
    for(int i = 0 ; i < n ; i++){
        cout << i << ' ';
    }
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        cout << i << ' ';
    }
    cout << endl;
    for(int i = 0 ; i < n ; i++){
        cout << (i + i) % n << ' ';
    }
    cout << endl;
    return 0;
}