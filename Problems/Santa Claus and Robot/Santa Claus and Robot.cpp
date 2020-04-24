#include <iostream>

using namespace std;

int n, Left, Right, Down, Up, sum = 1;
string s;

int main()
{
    cin >> n >> s;
    for(int i =  0 ; i < n ; i++){
        if(s[i] == 'U' && Down){
            sum++;
            Down = Right = Left = Up = 0;
        }
        if(s[i] == 'D' && Up){
            sum++;
            Down = Right = Left = Up = 0;
        }
        if(s[i] == 'L' && Right){
            sum++;
            Down = Right = Left = Up = 0;
        }
        if(s[i] == 'R' && Left){
            sum++;
            Down = Right = Left = Up = 0;
        }
        if(s[i] == 'U')
            Up++;
        if(s[i] == 'D')
            Down++;
        if(s[i] == 'R')
            Right++;
        if(s[i] == 'L')
            Left++;
    }
    cout << sum << endl;
    return 0;
}