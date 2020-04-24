#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1 ; i <= n ;i++){
        cin >> a[i];
    }
    stack < int > S;
    S.push(a[1]);
    long long maxx = -1;
    for(int i = 2; i <= n ; i++){
        while(!S.empty()){
            maxx = max(maxx,(long long)(a[i] ^ S.top()));
            if(S.top() > a[i])
                break;
            S.pop();
        }
        S.push(a[i]);
    }
    cout << maxx << endl;
    return 0;
}