#include <iostream>

using namespace std;

int x, y, a, b, i = 29;

void Q(int a1, int b1)
{
    cout << "? " << a1 << ' ' << b1 << endl;
    return;
}

int main(){
    cout << "? 0 0\n";
    cin >> x;
    for( ; i >= 0 ; i--){
        if(x == 0) break;
        Q(a ^ (1 << i), b ^ (1 << i));
        cin >> y;
        if(y == x){
            if(x == 1){
                Q(a ^ (1 << i), b);
                cin >> y;
                if(y != x){
                    a ^= (1 << i);
                    b ^= (1 << i);
                }
            }
            else{
                Q(a, b ^ (1 << i));
                cin >> y;
                if(y != x){
                    a ^= (1 << i);
                    b ^= (1 << i);
                }
            }
        }
        else{
            if(x == 1){
                a ^= (1 << i);
            }
            else b ^= (1 << i);
            Q(a, b);
            cin >> x;
        }
    }
    for( ; i >= 0 ; i--){
        Q(a ^ (1 << i), b);
        cin >> y;
        if(y == -1) a ^= (1 << i), b ^= (1 << i);
    }
    cout << "! " << a << ' ' << b << endl;
    return 0;
}