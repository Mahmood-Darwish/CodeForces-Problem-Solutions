#include <iostream>
#include <map>

using namespace std;

int n, sum, x;
map < int, int > m;

int main()
{
    cin >> n;
    while(n--){
        cin >> x;
        if(!m[x] && x != 0) {m[x] = 1, sum++;}
    }
    cout << sum << endl;
    return 0;
}