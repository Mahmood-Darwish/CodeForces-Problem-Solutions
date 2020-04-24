#include <iostream>

using namespace std;

int n, deg[1000000], len;
string a[1000000];

int main()
{
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        len = a[i].size();
    }
    for(int i = 0 ; i < len ; i++){
        char temp = ';';
        for(int j = 0 ; j < n ; j++){
            if(a[j][i] != '?'){
                if(temp != a[j][i]){
                    deg[i]++;
                    temp = a[j][i];
                }
            }
        }
    }
    for(int i = 0 ; i < len ; i++){
        if(deg[i] == 0)
            cout << 'a';
        if(deg[i] > 1)
            cout << '?';
        if(deg[i] == 1){
            for(int j = 0 ; j < n ; j++){
                if(a[j][i] != '?')
                {
                    cout << a[j][i];
                    break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}