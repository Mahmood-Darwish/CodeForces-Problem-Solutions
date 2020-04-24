#include <iostream>

using namespace std;

string s;
long long n, temp, temp2, sum;

int main()
{
    cin >> s;
    n = s.size();
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '@'){
            temp = temp2 = 0;
            int j = i - 1;
            while(s[j] != '@' && s[j] != '.' && j >= 0){
                if(isalpha(s[j])){
                    temp++;
                }
                j--;
            }
            for(j = i + 1 ; j < n ; j++){
                if(s[j] == '@' || s[j] == '_'){
                    temp = temp2 = 0;
                    goto M;
                }
                if(s[j] == '.')break;
            }
            if(j - 1 == i){
                temp = temp2 = 0;
                goto M;
            }
            j++;
            if(j < n){
                while(isalpha(s[j])){
                    temp2++;
                    j++;
                }
            }
            sum += temp * temp2;
            temp = temp2 = 0;
        }
        M:continue;
    }
    cout << sum << endl;
    return 0;
}