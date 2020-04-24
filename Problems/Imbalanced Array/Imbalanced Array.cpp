#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;


ll n, a[1001000], sum;
stack < ll > s;
ll leftt[1001000];
ll rightt[1001000];

int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i++){
        scanf("%I64d", &a[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        if(s.empty()){
            leftt[i] = 0;
            s.push(i);
        }
        else{
            bool bol = false;
            while(!s.empty()){
                if(a[s.top()] >= a[i]){
                    s.pop();
                }
                else{
                    leftt[i] = s.top();
                    s.push(i);
                    bol = true;
                    break;
                }
            }
            if(!bol){
                leftt[i] = 0;
                s.push(i);
            }
        }
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i = n ; i >= 1 ; i--){
        if(s.empty()){
            rightt[i] = n + 1;
            s.push(i);
        }
        else{
            bool bol = false;
            while(!s.empty()){
                if(a[s.top()] > a[i]){
                    s.pop();
                }
                else{
                    rightt[i] = s.top();
                    s.push(i);
                    bol = true;
                    break;
                }
            }
            if(!bol){
                rightt[i] = n + 1;
                s.push(i);
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        sum -= a[i] * (((i - leftt[i])) * ((rightt[i] - i)));
    //    cout << i << ' ' << (((i - leftt[i])) * ((rightt[i] - i))) << ' ';
    }
    //cout << endl;
    while(!s.empty()){
        s.pop();
    }
    for(int i = 1 ; i <= n ; i++){
        if(s.empty()){
            leftt[i] = 0;
            s.push(i);
        }
        else{
            bool bol = false;
            while(!s.empty()){
                if(a[s.top()] <= a[i]){
                    s.pop();
                }
                else{
                    leftt[i] = s.top();
                    s.push(i);
                    bol = true;
                    break;
                }
            }
            if(!bol){
                leftt[i] = 0;
                s.push(i);
            }
        }
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i = n ; i >= 1 ; i--){
        if(s.empty()){
            rightt[i] = n + 1;
            s.push(i);
        }
        else{
            bool bol = false;
            while(!s.empty()){
                if(a[s.top()] < a[i]){
                    s.pop();
                }
                else{
                    rightt[i] = s.top();
                    s.push(i);
                    bol = true;
                    break;
                }
            }
            if(!bol){
                rightt[i] = n + 1;
                s.push(i);
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        sum += a[i] * (((i - leftt[i])) * ((rightt[i] - i)));
        //cout << i << ' ' << (((i - leftt[i])) * ((rightt[i] - i))) << ' ';
    }
    //cout << endl;
    cout << sum << endl;
    return 0;
}