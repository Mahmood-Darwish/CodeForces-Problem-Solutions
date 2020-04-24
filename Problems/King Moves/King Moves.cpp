#include <iostream>

using namespace std;

int main()
{
    char c , r;
    int sum = 8;
    bool sure = false;
    cin >> c >> r;
    if(c == 'a' || c == 'h')
    {
        sum -= 3;
        sure = true;
    }
    if(r == '1' || r == '8')
    {
        sum -= 2;
        if(!sure)sum--;
    }
    cout << sum;
    return 0;
}