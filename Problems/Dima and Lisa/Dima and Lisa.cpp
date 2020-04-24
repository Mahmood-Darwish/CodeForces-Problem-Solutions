#include <iostream>
#include <cmath>

using namespace std;

int n;

bool PRIME(int x)
{
    for(int i = 2 ; i <= sqrt(x) ; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    if(PRIME(n)){
        cout << 1 << endl << n << endl;
        return 0;
    }
    if(PRIME(n - 2)){
        cout << 2 << endl << n - 2 << ' ' << 2 << endl;
        return 0;
    }
    int temp = n;
    while(!PRIME(temp)) temp--;
    int i = 1;
    while(true){
        i++;
        if(PRIME(i) && PRIME((n - temp) - i)){
            cout << 3 << endl << i << ' ' << temp << ' ' << ((n - temp) - i) << endl;
            return 0;
        }
    }
    return 0;
}