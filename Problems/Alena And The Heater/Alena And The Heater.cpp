#include <iostream>

using namespace std;

int n, l = -1e9, r = 1e9;
int a[100100];
string s;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cin >> s;
    for(int i = 4 ; i < s.size() ; i++){
        if(s[i] == '0'){
            if(s[i - 1] == '1' && s[i - 2] == '1' && s[i - 3] == '1' && s[i - 4] == '1'){
                if(r >= a[i] || r >= a[i - 1] || r >= a[i - 2] || r >= a[i - 3] || r >= a[i - 4]){
                    r = min(a[i], min(a[i - 1], min(a[i - 2], min(a[i - 3], a[i - 4]))));
                    r--;
                }
            }
        }
        if(s[i] == '1'){
            if(s[i - 1] == '0' && s[i - 2] == '0' && s[i - 3] == '0' && s[i - 4] == '0'){
                if(l <= a[i] || l <= a[i - 1] || l <= a[i - 2] || l <= a[i - 3] || l <= a[i - 4]){
                    l = max(a[i], max(a[i - 1], max(a[i - 2], max(a[i - 3], a[i - 4]))));
                    l++;
                }
            }
        }
    }
    cout << l << ' ' << r << endl;
    return 0;
}