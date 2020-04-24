#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    int n;
    cin >> n;
    if(n < 10){
        cout << 1 << endl;
        return 0;
    }
    int temp = n, m = 0, temp2 = 1;
    while(temp){
        if(temp < 10){
            temp2 = temp;
        }
        temp /= 10;
        m++;
    }
    temp2++;
    m--;
    while(m--){
        temp2 *= 10;
    }
    cout << temp2 - n << endl;
    return 0;
}