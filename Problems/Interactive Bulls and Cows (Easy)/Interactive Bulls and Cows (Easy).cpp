#include <bits/stdc++.h>

using namespace std;

int n, m;
vector < char > V;
char a[5];

int main()
{
    cout << "0000" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('0');
    }
    cout << "1111" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('1');
    }
    cout << "2222" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('2');
    }
    cout << "3333" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('3');
    }
    cout << "4444" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('4');
    }

    cout << "5555" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('5');
    }
    cout << "6666" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('6');
    }
    cout << "7777" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('7');
    }

    cout << "8888" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('8');
    }
    cout << "9999" << endl;
    cin >> n >> m;
    if(n){
        V.push_back('9');
    }
    for(int i = 0 ; i < 4 ; i++){
        a[i] = V[i];
    }
    do{
        cout << a << endl;
        cin >> n >> m;
        if(n == 4){
            return 0;
        }
    }while(next_permutation(a, a+ 4));
    return 0;
}