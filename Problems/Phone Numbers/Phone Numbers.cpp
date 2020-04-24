#include <iostream>

using namespace std;

int n;
string s;

int main(){
    cin >> n >> s;
    if(n == 2 || n == 3)
    {
        cout << s;
        return 0;
    }
    for(int i = 0 ; i <  n;){
        cout << s[i] << s[i+1] << '-';
        i += 2;
        if(i + 3 == n){
            cout << s[i] << s[i+1] << s[i+ 2];
            return 0;
        }
        if(i + 2 == n){
            cout << s[i] << s[i+1];
            return 0 ;
        }
    }
}