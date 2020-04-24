#include <iostream>
#include <cmath>

using namespace std;

long long s, x1, x2, t1, t2, p, d, ans1, ans2;

int main()
{
    cin >> s >> x1 >> x2;
    cin >> t2 >> t1;
    cin >> p >> d;
    ans1 = abs(x1 - x2) * t1;
    if(d == 1 && x1 >= p){
        if(x2 >= x1){
            ans2 = abs(p - x2) * t2;
        }
        else{
            ans2 = abs(p - s) * t2;
            ans2 += abs(s - x2) * t2;
        }
    }
    else{
        if(d == 1 && x1 < p){
            ans2 = abs(s - p) * t2;
            ans2 += abs(s - x1) * t2;
            if(x2 < x1){
                ans2 += abs(x2 - x1) * t2;
            }
            else {
                ans2 += x1 * t2;
                ans2 += x2 * t2;
            }
        }
        else{
            if(d == -1 && x1 <= p){
                ans2 = abs(x1 - p) * t2;
                if(x2 < x1)
                    ans2 += abs(x1 - x2) * t2;
                else {
                    ans2 += x1 * t2;
                    ans2 += x2 * t2;
                }
            }
            else{
                ans2 = p * t2;
                ans2 += x1 * t2;
                if(x2 > x1)
                    ans2 += abs(x1 - x2) * t2;
                else
                {
                    ans2 += abs(x1 - s) * t2;
                    ans2 += abs(s - x2) * t2;
                }
            }
        }
    }
    cout << min(ans1 ,ans2) << endl;
    return 0;
}