#include <iostream>
#include <vector>
#include <queue>

#define F first
#define S second

using namespace std;

int n;

int main()
{
    cin >> n;
    if(n % 2){
        cout << 7;
        n -= 3;
    }
    while(n){
        n -= 2;
        cout << 1;
    }
    cout << endl;
}