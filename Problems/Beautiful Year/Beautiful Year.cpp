#include <iostream>
#include <string.h>

using namespace std;

bool f(int num){
    bool vis[15];
    memset(vis,0,sizeof(vis));
    while(num){
        if(vis[num % 10])return false;
        vis[num % 10] = true;
        num /= 10;
    }
    return true;
}

int main(){
    int y;
    cin >> y;
    for(int i = y + 1 ; ; i++){
        if(f(i)){
            cout << i ;
            break;
        }
    }
}