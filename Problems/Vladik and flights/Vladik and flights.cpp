#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b,n;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    cout << abs(s[--a] - s[--b]) << endl;
}