#include <iostream>

using namespace std;
typedef long long ll;

ll h, sum;
bool rightt;

ll mypow(int x, int y)
{
    ll temp = 1;
    for(int i = 0 ; i < y ; i++){
        temp *= x;
    }
    return temp;
}

ll DFS(ll n ,int how_much, bool rightt)
{
    if(!how_much)return 0;
    ll all = mypow(2 , how_much);
    if(n > all / 2){
        if(rightt){
            return DFS(n - (all / 2),how_much - 1, 0) + 1;
        }
        else{
            return DFS(n - (all / 2),how_much - 1, 0) + mypow(2 ,how_much);
        }
    }
    else{
        if(rightt){
            return DFS(n ,how_much - 1, 1) + mypow(2 ,how_much);
        }
        else{
            return DFS(n ,how_much - 1, 1) + 1;
        }
    }
}

int main()
{
    ll n;
    cin >> h >> n;
    cout << DFS(n ,h , 0) << endl;
    return 0;
}