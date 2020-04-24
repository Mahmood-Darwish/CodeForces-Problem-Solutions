#include <iostream>
#include <cmath>

using namespace std;

bool check(int x)
{
    for(int i = 2 ; i <= sqrt(x) ; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= 1000 ; i++){
        if(!check((n * i) + 1)){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}