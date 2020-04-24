#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

int n, green, black, k, temp, last;
vector < char > V;

void P()
{
    for(auto cur : V)
        cout << cur;
    cout << endl;
    return;
}

int main()
{
    cin >> n >> k >> green >> black;
    if(green < black)
    {
        while(true)
        {
            while(green != black && temp != k)
            {
                last = 'B';
                V.pb('B');
                black--;
                temp++;
            }
            if(green == black)
                break;
            if(!green)
            {
                cout << "NO";
                return 0;
            }
            V.pb('G');
            green--;
            last = 'G';
            if(green == black)
                break;
            temp = 0;
        }
        temp = 0;
        while(green || black){
            if(last == 'B'){
                V.pb('G');
                green--;
                V.pb('B');
                black--;
            }
            else{
                V.pb('B');
                black--;
                V.pb('G');
                green--;
            }
        }
        P();
        return 0;
    }
    else {
        while(true)
        {
            while(green != black && temp != k)
            {
                last = 'G';
                V.pb('G');
                green--;
                temp++;
            }
            if(green == black)
                break;
            if(!black)
            {
                cout << "NO";
                return 0;
            }
            V.pb('B');
            black--;
            last = 'B';
            if(green == black)
                break;
            temp = 0;
        }
        temp = 0;
        while(green || black){
            if(last == 'B'){
                V.pb('G');
                green--;
                V.pb('B');
                black--;
            }
            else{
                V.pb('B');
                black--;
                V.pb('G');
                green--;
            }
        }
        P();
        return 0;
    }
    return 0;
}