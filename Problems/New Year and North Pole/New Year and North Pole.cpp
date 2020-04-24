#include <iostream>

using namespace std;

int n, pos, t;
bool bad, north_pole, south_pole;
string dir;

int main(){
    cin >> n;
    while(n--){
        if(!pos){
            north_pole = true;
        }
        else north_pole = false;
        if(pos == 20000){
            south_pole = true;
        }
        else south_pole = false;
        cin >> t >> dir;
        if((dir == "West" || dir == "East") && (north_pole || south_pole)){
            bad = true;
        } 
        if(north_pole && dir == "North"){
            bad = true;
        }
        if(south_pole && dir == "South"){
            bad = true;
        }
        if(dir == "North"){
            pos -= t;
        }
        if(dir == "South"){
            pos += t;
        }
        if(pos > 20000 || pos < 0)
            bad = true;
    }
    if(bad || pos)
        cout << "NO";
    else cout << "YES";
    cout << endl;    
}