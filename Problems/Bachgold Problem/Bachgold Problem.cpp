#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    while ( n != 3 ){
        if(!n)break;
        n -= 2;
        sum++;
    }
    if(n == 3)
    {
        cout << sum + 1 << endl;
        while(sum--)
            cout << 2 << ' ';
        cout << 3;

    }
    else{
        cout << sum << endl;
        while(sum--)
            cout << 2 << ' ';
    }
    return 0;
}