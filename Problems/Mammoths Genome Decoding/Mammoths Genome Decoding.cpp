#include <iostream>

using namespace std;

int A, G, C, T;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(n % 4 != 0){
        cout << "===" << endl;
        return 0;
    }
    int temp = n / 4;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'A')
            A++;
        if(s[i] == 'G')
            G++;
        if(s[i] == 'C')
            C++;
        if(s[i] == 'T')
            T++;
    }
    if(A > temp || G > temp || C > temp || T > temp){
        cout << "===" << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '?'){
            if(A < temp){
                s[i] = 'A';
                A++;
                continue;
            }
            if(G < temp){
                s[i] = 'G';
                G++;
                continue;
            }
            if(C < temp){
                s[i] = 'C';
                C++;
                continue;
            }
            if(T < temp){
                s[i] = 'T';
                T++;
                continue;
            }
        }
    }
    cout << s << endl;
    return 0;
}